# setup.py

from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext
import numpy
import os

os.environ["CC"] = "g++"
os.environ["CXX"] = "g++"

setup( name = 'linear-interp',
       version = '0.1',
       author = 'Greg von Winckel',
       description = 'C++ class for linear interpolation with Cython',
       ext_modules=[Extension("cy_linterp1d",
                        sources=["cy_linterp1d.pyx","linterp1d.cpp"],
                        language="c++",
                        include_dirs=[numpy.get_include()])
       ],
       cmdclass = {'build_ext': build_ext},
)                                  
