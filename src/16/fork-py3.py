#!/usr/bin/env python3
# -*- coding:utf-8 -*-
'''
Copyright (c) 2018  T-Life Research Center, Fudan University, Shanghai, China.
See the accompanying Manual for the contributors and the way to cite this work.
Comments and suggestions welcome. Please contact
Dr. Guanghong Zuo <ghzuo@fudan.edu.cn>

@Author: Dr. Guanghong Zuo
@Date: 2018-12-24 13:34:57
@Last Modified By: Dr. Guanghong Zuo
@Last Modified Time: 2018-12-24 13:38:22
'''

import os
import time

print('befor the fork, my PID is', os.getpid())
if os.fork():
    print('Hello from the parent. My PID is', os.getpid())
else:
    print('Hello from the child, My PID is', os.getpid())
time.sleep(1)

print('Hello from both of us.')
