#include <iostream>     // std::cout, std::endl 
#include <vector>       // std::vector
#include <cmath>        // sin
#include "linterp1d.hpp"


int main () {

  int m = 11;
  int n = 21; 

  dvec::iterator low,up;

  dvec x1(m);
  dvec x2(n);

  dvec f1(m);
  dvec f2(n);

  ivec lower(n);
  ivec upper(n);

  int k;


  for(k=0;k<m;++k)
  {
     x1[k] = k/double(m-1);
     f1[k] = sin(3*x1[k]);
  }

  for(k=0;k<n;++k)
  {
     x2[k] = k/double(n-1);
  }

  LinearInterp LI(x1,x2);

  f2 = LI.interp(f1); 

  for(k=0;k<n;++k)
  {
     std::cout << f2[k] << std::endl;
  }


  return 0;
}
