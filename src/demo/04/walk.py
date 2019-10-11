#!/usr/bin/env python3
# -*- coding:utf-8 -*-
'''
Copyright (c) 2019  T-Life Research Center, Fudan University, Shanghai, China.
See the accompanying Manual for the contributors and the way to cite this work.
Comments and suggestions welcome. Please contact
Dr. Guanghong Zuo <ghzuo@fudan.edu.cn>

@Author: Dr. Guanghong Zuo
@Date: 2016-04-19 11:56:28
@Last Modified By: Dr. Guanghong Zuo
@Last Modified Time: 2019-10-11 10:07:18
'''

# A python script to do a random walker
# Author: G.H.Zuo

import sys
import numpy as np

# Basic setup
NDIM = 2
nStep = 100
if (len(sys.argv) > 1):
    nStep = int(sys.argv[1])

# Initial state
r = np.array([0.0] * NDIM)
print(0, " ".join("{:6.3f}".format(c) for c in r))

# walk around...
for i in range(1, nStep + 1):
    step = np.random.random_sample(NDIM) - 0.5
    step /= np.linalg.norm(step)
    r += step
    print(i, " ".join("{:6.3f}".format(c) for c in r))
