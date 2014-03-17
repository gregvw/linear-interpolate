import numpy as np
import matplotlib.pyplot as plt
from cy_linterp1d import Linterp
from linear_interp import LinearInterp

if __name__ == '__main__':

    # Number of source points
    m = 21

    # Number of target points
    n = 41

    # Source grid
    x1 = np.linspace(0,1,m)
  
    # Target grid
    x2 = np.linspace(-.01,1.01,n)

    # Instantiate pure Python interpolator object
    LI_py = LinearInterp(x1,x2)

    # Instantiate C++ interpolator object
    LI_cpp = Linterp(x1,x2)

    # Data to interpolate
    f1 = np.sin(2*np.pi*x1)

    fig = plt.figure(1,(16,7))

    ax1 = fig.add_subplot(121)
    ax2 = fig.add_subplot(122)

    f2_py = LI_py.interp(f1)
    f2_cpp = LI_cpp.interp(f1)

    ax1.plot(x1,f1,'bo')
    ax1.plot(x2,f2_py,'r.-')
    ax1.set_title('Python Implementation')
    ax2.plot(x1,f1,'bo')
    ax2.plot(x2,f2_cpp,'r.-')
    ax2.set_title('C++ Implementation')
    plt.show()
