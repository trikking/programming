#!/usr/bin/env python27
# -*- coding: utf-8 -*-

import paramiko
import traceback
import ConfigParser
import logging
import multiprocessing
import time

global_ssh_port = 22
global_timeout = 20

conffile='monitor.cnf'

logger = logging.getLogger('testlogger')

logging.basicConfig(level=logging.INFO,
                    format='%(asctime)s-%(name)s-%(levelname)s: %(message)s',
                    datefmt='%a, %d %b %Y %H:%M:%S',
                    filename='test.log',
                    filemode='a')


def ssh_outs(ip, cmd, port = global_ssh_port, user = '', password = ''):

    """
    介  绍：返回执行远程操作系统命令的执行结果.
    返回值：返回值为字典. status为success时, data类型为str, 以\n分隔每行.
    """

    ssh = paramiko.SSHClient()
    ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
    try:
        if not user:
            ssh.connect(hostname = ip, 
                        port = int(port), 
                        username = user, 
                        key_filename = global_key_filename, 
                        timeout = global_timeout)
        else:
            ssh.connect(hostname = ip, 
                        port = int(port), 
                        username = user, 
                        password = password, 
                        timeout = global_timeout)
        stdin, stdout, stderr = ssh.exec_command("set -o pipefail; " + cmd, 
                                                  timeout = global_timeout)
        output = stdout.readlines()
        error = stderr.readlines()
        content = output + error
    except:
        trace_info = traceback.format_exc()
        status = 'failure'
        message = trace_info
        data = ''
    else:
        paramiko_status = stdout.channel.recv_exit_status()
        if paramiko_status == 0:
            status = 'success'
            message = 'Executed remote host os command via paramiko successfully!'
            data = ''.join(content)
        else:
            status = 'failure'
            message = ''.join(content)
            data = ''
    return_info = {"status":status, "message":message, "data":data}
    return return_info

def parse_conf(conffile):
    config = ConfigParser.ConfigParser()
    config.read(conffile)

    ### parse extractor parameters
    extractor_para = {}
    extractor_para['ip'] = config.get('extractor', 'ip').split(',')
    extractor_para['ssh_user'] = config.get('extractor', 'ssh_user')
    extractor_para['ssh_port'] = config.get('extractor', 'ssh_port')
    extractor_para['app_dir'] = config.get('extractor', 'app_dir')
    extractor_para['app_pattern'] = config.get('extractor', 'app_pattern')

    ### parse mq parameters
    mq_para = {}
    mq_para['ip'] = config.get('mq', 'ip').split(',')
    mq_para['ssh_user'] = config.get('mq', 'ssh_user')
    mq_para['ssh_port'] = config.get('mq', 'ssh_port')
    mq_para['app_dir'] = config.get('mq', 'app_dir')
    mq_para['app_port'] = config.get('mq', 'app_port')
    mq_para['app_pattern'] = config.get('mq', 'app_pattern')

    ### parse applier parameters
    applier_para = {}
    applier_para['ip'] = config.get('applier', 'ip').split(',')
    applier_para['ssh_user'] = config.get('applier', 'ssh_user')
    applier_para['ssh_port'] = config.get('applier', 'ssh_port')
    applier_para['app_dir'] = config.get('applier', 'app_dir')
    applier_para['app_pattern'] = config.get('applier', 'app_pattern')

    return extractor_para, mq_para, applier_para

def monitor(monitor_type, para):
    ip = para['ip']
    ssh_user = para['ssh_user']
    ssh_port = para['ssh_port']
    app_dir = para['app_dir']
    app_pattern = para['app_pattern']
    if monitor_type == 'mq':
        app_port = para['app_port']
    while True:
        monitor_cmd = 'ps -ef | grep %s | grep -v grep' % (app_pattern)
        monitor_result = ssh_outs(ip = ip, port = ssh_port, cmd = monitor_cmd, user = ssh_user)
        if monitor_type == 'extractor':
            if monitor_result['status'] == 'failure':
                logger.info('%s -- %s -- %s is NOT running!!! Please check!!!' % (ip, monitor_type, app_pattern))
            else:
                logger.info('%s -- %s -- %s is running' % (ip, monitor_type, app_pattern))
        time.sleep(5)

def multi_monitor():
    (extractor_para, mq_para, applier_para) = parse_conf(conffile)
    threads = []
    para = extractor_para
    for ip in extractor_para['ip']:
        para['ip'] = ip
        t = multiprocessing.Process(target = monitor, args = ('extractor', para,))
    #para = mq_para
    #for ip in mq_para['ip']:
    #    para['ip'] = ip
    #    t = multiprocessing.Process(target = monitor, args = ('mq', para,))
    #para = applier_para
    #for ip in applier_para['ip']:
    #    para['ip'] = ip
    #    t = multiprocessing.Process(target = monitor, args = ('applier', para,))
    threads.append(t)
    for t in threads:
        t.daemon = True
    for t in threads:
        t.start()
    for t in threads:
        t.join()
