#!/usr/bin/env python
# -*- coding: utf-8 -*-

import multiprocessing
import paramiko
import logging
import getopt
import traceback
from common import *

def multi_monitor():
    (extractor_para, mq_para, applier_para) = parse_conf(conffile)
    threads = []
    para = extractor_para
    for ip in extractor_para['ip']:
        para['ip'] = ip
        t = multiprocessing.Process(target = monitor, args = ('extractor', ip, para,))
        t.daemon = True
        threads.append(t)
    para = mq_para
    for ip in mq_para['ip']:
        para['ip'] = ip
        t = multiprocessing.Process(target = monitor, args = ('mq', ip, para,))
    para = applier_para
    for ip in applier_para['ip']:
        para['ip'] = ip
        t = multiprocessing.Process(target = monitor, args = ('applier', ip, para,))
    for t in threads:
        t.start()
    for t in threads:
        t.join()

def main():
    multi_monitor()

if __name__ == '__main__':
  main()
