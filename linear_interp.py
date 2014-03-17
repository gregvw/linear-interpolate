#!/usr/bin/env python
#-*- coding: utf-8 -*-

import numpy as np
from bisect import bisect_left, bisect_right

class LinearInterp(object):
    def __init__(self,x1,x2):

        self.m = len(x1)
        self.n = len(x2)

        # Determine the x1 pairs which bracket each x2
        self.dl = [bisect_right(x1,x2[k])-1 for k in range(self.n)]
        self.dr = [bisect_left(x1,x2[k]) for k in range(self.n)]

        # Right interpolation weights   
        self.b = np.zeros(self.n)

        for k in range(self.n):
            
            # Left extrapolation case
            if self.dl[k] == -1 and self.dr[k] == 0:
                self.dl[k] = 0
                self.dr[k] = 1      

            # Right extrapolation case
            elif self.dl[k] == self.m-1 and self.dr[k] == self.m:
                self.dl[k] = self.m-2
                self.dr[k] = self.m-1

            # Same point 
            if self.dl[k] == self.dr[k]:
                self.b[k] = 0.5

            else:
                self.b[k] = (x2[k]-x1[self.dl[k]])/ \
                            (x1[self.dr[k]]-x1[self.dl[k]])

        # Left interpolation weights
        self.a = 1-self.b


    def interp(self,f):

       if self.m != len(f):
           raise Exception('Incompatible array length')

       return f[self.dl]*self.a + f[self.dr]*self.b       


