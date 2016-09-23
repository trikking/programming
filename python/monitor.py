#!/usr/bin/env python
# -*- coding: utf-8 -*-

import multiprocessing
import paramiko
import logging
import getopt
import traceback
from common import *

def multi_monitor():
    (extractor_para_list, mq_para_list, applier_para_list) = parse_conf(conffile)
    threads = []
    for extractor_para in extractor_para_list:
        t = multiprocessing.Process(target = monitor, args = ('extractor', extractor_para,))
        t.daemon = True
        threads.append(t)
    #for mq_para in mq_para_list:
    #    para['ip'] = ip
    #    t = multiprocessing.Process(target = monitor, args = ('mq', mq_para,))
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

if __name__ == '__main__':
  main()
