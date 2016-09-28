#!/usr/bin/env python27
# -*- coding: utf-8 -*-

import traceback
import sys
from monitor import *

reload(sys)
sys.setdefaultencoding('utf-8')

if __name__ == '__main__':
    try:
        main()
    except:
        trace_info = traceback.format_exc()
        print trace_info
