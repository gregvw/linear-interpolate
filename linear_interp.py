import numpy as np
from bisect import bisect_left, bisect_right

class LinearInterp(object):
    def __init__(self,x1,x2):

        m = len(x1)
        n = len(x2)

        # Determine the x1 pairs which bracket each x2
        self.dl = [bisect_right(x1,x2[k])-1 for k in range(n)]
        self.dr = [bisect_left(x1,x2[k]) for k in range(n)]

        # Right interpolation weights   
        self.b = np.zeros(n)

        for k in range(n):

            if self.dl[k] == -1 and self.dr[k] == 0:
                self.dl[k] = 0
                self.dr[k] = 1      

            elif self.dl[k] == m-1 and self.dr[k] == m:
                self.dl[k] = m-2
                self.dr[k] = m-1


            if self.dl[k] == self.dr[k]:
                self.b[k] = 0.5

            else:
                self.b[k] = (x2[k]-x1[self.dl[k]])/ \
                            (x1[self.dr[k]]-x1[self.dl[k]])

        # Left interpolation weights
        self.a = 1-self.b


    def interp(self,f):
       return f[self.dl]*self.a + f[self.dr]*self.b       
        



if __name__ == '__main__':
   
    import matplotlib.pyplot as plt

    m = 200
    n = 20

    x1 = np.linspace(-1,1,m)
    x2 = np.linspace(-1,1,n)

    LI = LinearInterp(x1,x2)

    f = np.sin(3*x1)

#    LI.interp(f)
    plt.plot(x1,f)
    plt.plot(x2,LI.interp(f))
    plt.show()
      
