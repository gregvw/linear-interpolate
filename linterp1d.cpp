#include <iostream>     // std::cout
#include <algorithm>    // std::lower_bound, std::upper_bound
#include <vector>       // std::vector
#include "linterp1d.hpp"

typedef std::vector<double> dvec;
typedef std::vector<int> ivec;

LinearInterp::LinearInterp(dvec x1, dvec x2)
{
    int m = x1.size();        
    int n = x2.size();

    a = new dvec(n);
    b = new dvec(n);


    lower = new ivec(n);
    upper = new ivec(n);

    int k;

    for(k=0;k<n;++k)
    {
        low = std::lower_bound(x1.begin(),x1.end(),x2[k]);
        up = std::upper_bound(x1.begin(),x1.end(),x2[k]);
        
    }
 
}

LinearInterp::~LinearInterp()
{
    delete a, b, upper, lower;

}








int main () {

  int m = 11;
  int n = 21; 

  dvec::iterator low,up;

  dvec x1(m);
  dvec x2(n);

  ivec lower(n);
  ivec upper(n);

  int k;


  for(k=0;k<m;++k)
  {
     x1[k] = k/double(m-1);
  }

  for(k=0;k<n;++k)
  {
     x2[k] = k/double(n-1);
  }

  LinearInterp LI(x1,x2);


  return 0;
}
