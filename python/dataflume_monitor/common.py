#!/usr/bin/env python27
# -*- coding: utf-8 -*-

import paramiko
import traceback
from xml.etree import cElementTree as ElementTree

global_ssh_port = 14816
global_timeout = 20

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
        stdin, stdout, stderr = ssh.exec_command("set -o pipefail; " + cmd)
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

class XmlListConfig(list):
    def __init__(self, aList):
        for element in aList:
            if element:
                # treat like dict
                if len(element) == 1 or element[0].tag != element[1].tag:
                    self.append(XmlDictConfig(element))
                # treat like list
                elif element[0].tag == element[1].tag:
                    self.append(XmlListConfig(element))
            elif element.text:
                text = element.text.strip()
                if text:
                    self.append(text)


class XmlDictConfig(dict):
    '''
    Example usage:

    >>> tree = ElementTree.parse('your_file.xml')
    >>> root = tree.getroot()
    >>> xmldict = XmlDictConfig(root)

    Or, if you want to use an XML string:

    >>> root = ElementTree.XML(xml_string)
    >>> xmldict = XmlDictConfig(root)

    And then use xmldict for what it is... a dict.
    '''
    def __init__(self, parent_element):
        if parent_element.items():
            self.update(dict(parent_element.items()))
        for element in parent_element:
            if element:
                # treat like dict - we assume that if the first two tags
                # in a series are different, then they are all different.
                if len(element) == 1 or element[0].tag != element[1].tag:
                    aDict = XmlDictConfig(element)
                # treat like list - we assume that if the first two tags
                # in a series are the same, then the rest are the same.
                else:
                    # here, we put the list in dictionary; the key is the
                    # tag name the list elements all share in common, and
                    # the value is the list itself 
                    aDict = {element[0].tag: XmlListConfig(element)}
                # if the tag has attributes, add those to the dict
                if element.items():
                    aDict.update(dict(element.items()))
                self.update({element.tag: aDict})
            # this assumes that if you've got an attribute in a tag,
            # you won't be having any text. This may or may not be a 
            # good idea -- time will tell. It works for the way we are
            # currently doing XML configuration files...
            elif element.items():
                self.update({element.tag: dict(element.items())})
            # finally, if there are no child tags and no attributes, extract
            # the text
            else:
                self.update({element.tag: element.text})
