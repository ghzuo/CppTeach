#!/usr/bin/python

# A python script to do a random walker
# Author: G.H.Zuo

from sys import *
from numpy import *

NDIM  = 3
nStep = 100

r = array([0.0]*NDIM)
for i in range(0,nStep):
    print i, " ".join(str(c) for c in r)
    step = random.sample(NDIM)-0.5
    step /= linalg.norm(step)
    r += step

