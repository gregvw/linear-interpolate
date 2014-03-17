#include <stdexcept>    // std exceptions
#include "linterp1d.hpp"

typedef std::vector<double> dvec;
typedef std::vector<int> ivec;

LinearInterp::LinearInterp(dvec x1, dvec x2)
{
    m = x1.size();           // Determine number of source grid points
    n = x2.size();          // Determine number of target grid points

    int k;

    // Loop over target points and determine which source points bracket them
    for(k=0;k<n;++k){

        low = std::lower_bound(x1.begin(),x1.end(),x2[k]);
        up = std::upper_bound(x1.begin(),x1.end(),x2[k]);

        // Index of upper bound for current point 
        upper.push_back(low-x1.begin());

        // Index of lower bound for current point 
        lower.push_back(up-x1.begin()-1); 

        // Left extrapolation case
        if(lower[k] == -1 & upper[k] == 0){
            lower[k] = 0;
            upper[k] = 1;
        }

        else if(lower[k] == m-1 & upper[k] == m){
            lower[k] = m-2;
            upper[k] = m-1;
        }

        // Same point
        if(lower[k] == upper[k]){
            b.push_back(0.5); 
        }
        else{
            b.push_back((x2[k]-x1[lower[k]])/(x1[upper[k]]-x1[lower[k]]));
        }
        a.push_back(1-b[k]);    
    }
}


dvec LinearInterp::interp(dvec f)
{
    if(m != f.size()){
        throw std::length_error("Vector length mismatch");
    }

    dvec g;

    for(int k=0;k<n;++k){
        g.push_back(f[lower[k]]*a[k]+f[upper[k]]*b[k]);
    }

    return g;
}

