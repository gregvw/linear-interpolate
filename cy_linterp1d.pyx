# distutils: language = c++
# distutils: sources = linterp1d.cpp

import cython
import numpy as np
cimport numpy as np

cdef extern from "<vector>" namespace "std":
    cdef cppclass vector[T]:
        cppclass iterator:
            T operator*()
            iterator operator++()
            bint operator==(iterator)
            bint operator!=(iterator)
        vector()
        void push_back(T&)
        T& operator[](int)
        T& at(int)
        iterator begin()
        iterator end()


cdef extern from "linterp1d.hpp":
    cdef cppclass LinearInterp:
        LinearInterp(vector[double],vector[double])
        vector[double] interp(vector[double])

        int m
        int n
        vector[double] a
        vector[double] b
        vector[double].iterator low
        vector[double].iterator up
        vector[int] lower
        vector[int] upper
    
        
cdef class Linterp:
    cdef LinearInterp *thisptr

    # Automatically converts NumPy arrays to STL vectors 
    def __init__(self,vector[double] x1,vector[double] x2):
        self.thisptr = new LinearInterp(x1,x2)

    def __dealloc__(self):
        del self.thisptr

    def interp(self,vector[double] f):
        return self.thisptr.interp(f)





