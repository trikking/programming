#!/usr/bin/env python27
# -*- coding: utf-8 -*-

import multiprocessing,threading
import paramiko
import logging, logging.handlers
import getopt
import traceback
import ConfigParser
import datetime, time
import urllib2
from xmltodict import xmltodict
import json
from common import *

conffile='conf/monitor.cnf'

dataflume_logger = logging.getLogger('dataflume-monitor-logger')
dataflume_logger.setLevel(logging.INFO)

mq_logger = logging.getLogger('mq-monitor-logger')
mq_logger.setLevel(logging.INFO)

dataflume_service_log = 'log/dataflume-service.log'
dataflume_service_fh = logging.FileHandler(dataflume_service_log)
#dataflume_service_fh = logging.handlers.TimedRotatingFileHandler(dataflume_service_log, when='D', interval=1, backupCount=10)
dataflume_service_fh = logging.handlers.RotatingFileHandler(dataflume_service_log, maxBytes = 100 * 1024 * 1024, backupCount=10)
dataflume_service_fh.setLevel(logging.INFO)

dataflume_error_log = 'log/dataflume-error.log'
dataflume_error_fh = logging.FileHandler(dataflume_error_log)
dataflume_error_fh = logging.handlers.RotatingFileHandler(dataflume_error_log, maxBytes = 50 * 1024 * 1024, backupCount=10)
dataflume_error_fh.setLevel(logging.ERROR)

mq_service_log = 'log/mq-service.log'
mq_service_fh = logging.FileHandler(mq_service_log)
mq_service_fh = logging.handlers.RotatingFileHandler(mq_service_log, maxBytes = 100 * 1024 * 1024, backupCount=10)
mq_service_fh.setLevel(logging.INFO)

mq_error_log = 'log/mq-error.log'
mq_error_fh = logging.FileHandler(mq_error_log)
mq_error_fh = logging.handlers.RotatingFileHandler(mq_error_log, maxBytes = 50 * 1024 * 1024, backupCount=10)
mq_error_fh.setLevel(logging.WARNING)

formatter = logging.Formatter('%(asctime)s - %(name)s - %(levelname)s - %(message)s')

dataflume_service_fh.setFormatter(formatter)
dataflume_error_fh.setFormatter(formatter)

dataflume_logger.addHandler(dataflume_service_fh)
dataflume_logger.addHandler(dataflume_error_fh)

mq_service_fh.setFormatter(formatter)
mq_error_fh.setFormatter(formatter)

mq_logger.addHandler(mq_service_fh)
mq_logger.addHandler(mq_error_fh)

def parse_conf(conffile):
    config = ConfigParser.ConfigParser()
    config.read(conffile)

    ### parse extractor parameters
    extractor_default = {}
    extractor_para_list = []
    mq_default = {}
    mq_para_list = []
    applier_default = {}
    applier_para_list = []

    sections = config.sections()

    mq_default['admin_user'] = config.get('mq-default', 'admin_user')
    mq_default['admin_passwd'] = config.get('mq-default', 'admin_passwd')
    mq_default['admin_web_port'] = config.get('mq-default', 'admin_web_port')

    extractor_default['ssh_user'] = config.get('extractor-default', 'ssh_user')
    extractor_default['ssh_port'] = config.get('extractor-default', 'ssh_port')
    extractor_default['app_pattern'] = config.get('extractor-default', 'app_pattern')

    applier_default['ssh_user'] = config.get('applier-default', 'ssh_user')
    applier_default['ssh_port'] = config.get('applier-default', 'ssh_port')
    applier_default['app_pattern'] = config.get('applier-default', 'app_pattern')

    for section in sections:

        mq = {}
        if 'mq-' in section and section != 'mq-default':
            mq['ip'] = config.get(section, 'ip')
            mq['admin_user'] = config.get(section, 'admin_user')
            mq['admin_passwd'] = config.get(section, 'admin_passwd')
            mq['admin_web_port'] = config.get(section, 'admin_web_port')
            mq_para_list.append(mq)
        
        extractor = {}
        if 'extractor-' in section and section != 'extractor-default':
            extractor['ip'] = config.get(section, 'ip')
            #extractor['ssh_user'] = config.get(section, 'ssh_user')
            #extractor['ssh_port'] = config.get(section, 'ssh_port')
            extractor['app_dir'] = config.get(section, 'app_dir')
            #extractor['app_pattern'] = config.get(section, 'app_pattern')
            extractor['ssh_user'] = extractor_default['ssh_user']
            extractor['ssh_port'] = extractor_default['ssh_port']
            extractor['app_pattern'] = extractor_default['app_pattern']
            extractor_para_list.append(extractor)

        applier = {}
        if 'applier-' in section and section != 'applier-default':
            applier['ip'] = config.get(section, 'ip')
            #applier['ssh_user'] = config.get(section, 'ssh_user')
            #applier['ssh_port'] = config.get(section, 'ssh_port')
            applier['app_dir'] = config.get(section, 'app_dir')
            #applier['app_pattern'] = config.get(section, 'app_pattern')
            applier['ssh_user'] = applier_default['ssh_user']
            applier['ssh_port'] = applier_default['ssh_port']
            applier['app_pattern'] = applier_default['app_pattern']
            applier_para_list.append(applier)

    return mq_para_list, extractor_para_list, applier_para_list

def monitor(monitor_type, para = {}):
    date = datetime.datetime.now()
    priv_error_log_date = date - datetime.timedelta(hours = 1)
    is_loop = 0
    delay_dict_info = {}
    while True:
        try:
            if monitor_type == 'mq':
                sleep_time = 300
                time.sleep(10)
                mq_monitor_date = datetime.datetime.now()
                ip = para['ip']
                admin_user = para['admin_user']
                admin_passwd = para['admin_passwd']
                admin_web_port = para['admin_web_port']
                active_mq_http_baseurl = 'http://%s:%s/api/jolokia' % (ip, admin_web_port)

                #surl = '%s/read/org.apache.activemq:type=Broker,brokerName=localhost,destinationType=Queue,destinationName=t_tfr_unload_diffcheck_report/QueueSize' % (active_mq_http_baseurl)
                check_health_url = '%s/read/org.apache.activemq:type=Broker,brokerName=localhost,service=Health/CurrentStatus' % (active_mq_http_baseurl)
                queue_view_url = 'http://%s:%s/admin/xml/queues.jsp' % (ip, admin_web_port)

                passman = urllib2.HTTPPasswordMgrWithDefaultRealm()
                passman.add_password(None, queue_view_url, admin_user, admin_passwd)
                auth_handler = urllib2.HTTPBasicAuthHandler(passman)
                opener = urllib2.build_opener(auth_handler)
                urllib2.install_opener(opener)
                response = urllib2.urlopen(queue_view_url)
                xml_resContent = response.read()
                queues_json = xmltodict.parse(xml_resContent)
                mq_logger.info(mq_monitor_date.strftime("%Y-%m-%d %H:%M:%S") + '的MQ队列情况如下(表名,消息数量(大概多久同步完(s)),消费者数量,进队数量,出队数量):')
                for queue in queues_json["queues"]["queue"]:
                    queue_name = queue["@name"]
                    #print delay_dict_info
                    if is_loop == 0:
                        delay_dict_info[queue_name] = {}
                        delay_dict_info[queue_name]["priv_size"] = queue["stats"]["@size"]
                        delay_dict_info[queue_name]["priv_consumerCount"] = queue["stats"]["@consumerCount"]
                        delay_dict_info[queue_name]["priv_enqueueCount"] = queue["stats"]["@enqueueCount"]
                        delay_dict_info[queue_name]["priv_dequeueCount"] = queue["stats"]["@dequeueCount"]
                        delay = '监控刚启动，未计算所需同步时间'
                    else:
                        delay_dict_info[queue_name]["this_size"] = queue["stats"]["@size"]
                        delay_dict_info[queue_name]["this_consumerCount"] = queue["stats"]["@consumerCount"]
                        delay_dict_info[queue_name]["this_enqueueCount"] = queue["stats"]["@enqueueCount"]
                        delay_dict_info[queue_name]["this_dequeueCount"] = queue["stats"]["@dequeueCount"]
                        #print queue["@name"],delay_dict_info[queue_name]["priv_size"],delay_dict_info[queue_name]["priv_enqueueCount"],delay_dict_info[queue_name]["priv_dequeueCount"],delay_dict_info[queue_name]["this_size"],delay_dict_info[queue_name]["this_enqueueCount"],delay_dict_info[queue_name]["this_dequeueCount"]
                        if (int(delay_dict_info[queue_name]["this_dequeueCount"]) - int(delay_dict_info[queue_name]["priv_dequeueCount"])) != 0:
                            delay_seconds = 1.0 * sleep_time * int(delay_dict_info[queue_name]["this_size"]) / (int(delay_dict_info[queue_name]["this_dequeueCount"]) - int(delay_dict_info[queue_name]["priv_dequeueCount"]))
                            delay_seconds = float("%.2f" % delay_seconds)
                            delay = str(delay_seconds) + 's'
                            if delay_seconds > 900:
                                warning_log = '%s 表预估延迟有可能超过900s，当前队列中未消费数量:%s, 请检查!（如果队列数量较小，请忽略报警）' % (queue["@name"], queue["stats"]["@size"])
                                mq_logger.warning(warning_log)
                        else:
                            delay = str(sleep_time) + 's内消费数量为0，暂时无法计算'
                    if queue["stats"]["@size"] == '0':
                        delay = '无延迟'

                    mq_logger.info("%s,%s(所需同步时间:%s),%s,%s,%s" % (queue["@name"], 
                                                       queue["stats"]["@size"], 
                                                       delay,
                                                       queue["stats"]["@consumerCount"], 
                                                       queue["stats"]["@enqueueCount"], 
                                                       queue["stats"]["@dequeueCount"]))
                    if int(queue["stats"]["@consumerCount"]) == 0:
                        error_log = 'Number of consumer(s) on queue %s(MQ IP:%s port:%s) is 0, please check!!!' % (queue["@name"], ip, admin_web_port)
                        mq_logger.error(error_log)
                    if is_loop == 1:
                        delay_dict_info[queue_name]["priv_size"] = queue["stats"]["@size"]
                        delay_dict_info[queue_name]["priv_consumerCount"] = queue["stats"]["@consumerCount"]
                        delay_dict_info[queue_name]["priv_enqueueCount"] = queue["stats"]["@enqueueCount"]
                        delay_dict_info[queue_name]["priv_dequeueCount"] = queue["stats"]["@dequeueCount"]
                time.sleep(sleep_time - 10)
                mq_logger.info('\n' * 3)
                is_loop = 1

            if monitor_type == 'extractor' or monitor_type == 'applier':
                time.sleep(60)
                ip = para['ip']
                ssh_user = para['ssh_user']
                ssh_port = para['ssh_port']
                app_dir = para['app_dir']
                app_pattern = para['app_pattern']
                monitor_cmd = 'ps -ef | grep %s | grep -v grep' % (app_pattern)
                monitor_result = ssh_outs(ip = ip, port = ssh_port, cmd = monitor_cmd, user = ssh_user)
                if monitor_result['status'] == 'failure':
                    if monitor_result['message']:
                        error_info = '%s %s on %s monitor error, ssh cmd ps failed !!!' % (monitor_type, app_pattern, ip)
                    else:
                        error_info = "%s %s on %s is NOT running!!!" % (monitor_type, app_pattern, ip)
                    dataflume_logger.critical(error_info + '\n' + monitor_result["message"])
                    # send SMS error_info
                        
                else:
                    monitor_log_cmd = """ ls --full-time %s/log/error.log | awk '{print $6 " " $7}' | sed 's/\..*$//g' """ % (app_dir)
                    monitor_log_result = ssh_outs(ip = ip, port = ssh_port, cmd = monitor_log_cmd, user = ssh_user)
                    if monitor_log_result['status'] == 'failure':
                        error_log = '%s %s on %s monitor error, ssh cmd ls failed!!!' % (monitor_type, app_pattern, ip)
                        dataflume_logger.critical(error_info + '\n' + monitor_result["message"])
                        # send SMS error_info
                    else:
                        error_log_date_str = monitor_log_result["data"].strip()
                        error_log_date = datetime.datetime.strptime(error_log_date_str, "%Y-%m-%d %H:%M:%S")
                        if priv_error_log_date >= error_log_date:
                            dataflume_logger.info('%s %s on %s is running, app log is OK!' % (monitor_type, app_pattern, ip))
                        else:
                            error_log = '%s %s on %s new error log found since %s' % \
                                         (monitor_type, app_pattern, ip, priv_error_log_date.strftime("%Y-%m-%d %H:%M:%S"))
                            dataflume_logger.error(error_log)
                            # send SMS error_info
                        priv_error_log_date = error_log_date

        except:
            trace_info = traceback.format_exc()
            print trace_info

def multi_monitor():
    (mq_para_list, extractor_para_list, applier_para_list) = parse_conf(conffile)
    threads = []
    for mq_para in mq_para_list:
        t = multiprocessing.Process(target = monitor, args = ('mq', mq_para,))
        t.daemon = True
        threads.append(t)
    #for extractor_para in extractor_para_list:
    #    t = multiprocessing.Process(target = monitor, args = ('extractor', extractor_para,))
    #    t.daemon = True
    #    threads.append(t)
    for applier_para in applier_para_list:
        t = multiprocessing.Process(target = monitor, args = ('applier', applier_para,))
        t.daemon = True
        threads.append(t)
    for t in threads:
        t.start()
    for t in threads:
        t.join()

def main():
    multi_monitor()
