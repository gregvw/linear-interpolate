#include <iostream>     // std::cout
#include <algorithm>    // std::lower_bound, std::upper_bound
#include <vector>       // std::vector


//class LinearInterp {
//
//};

typedef std::vector<double> dvec;
typedef std::vector<int> ivec;

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
     x2[k] = 1.1*k/double(n-1);
  }


   for(k=0;k<n;++k)
   {
    
      low = std::lower_bound(x1.begin(),x1.end(),x2[k]);
      up = std::upper_bound(x1.begin(),x1.end(),x2[k]);
      lower[k] = (low-x1.begin());
      upper[k] = (up-x1.begin());
      std::cout << lower[k] << " " << upper[k] << std::endl;

    } 

  return 0;
}
