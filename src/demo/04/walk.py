#!/usr/bin/python

# A python script to do a random walker
# Author: G.H.Zuo

from sys import *
from numpy import *

# Basic setup
NDIM  = 2
nStep = 100
if(len(argv)>1) :
    nStep = int(argv[1])

# Initial state
r = array([0.0]*NDIM)
print 0, " ".join(str(c) for c in r)

# walk around...
for i in range(1,nStep+1):
    step = random.sample(NDIM)-0.5
    step /= linalg.norm(step)
    r += step
    print i, " ".join(str(c) for c in r)
