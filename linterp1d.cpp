#include <iostream>     // std::cout, std::endl
#include <algorithm>    // std::lower_bound, std::upper_bound
#include <vector>       // std::vector
#include <stdexcept>    // std excecptions
#include "linterp1d.hpp"

typedef std::vector<double> dvec;
typedef std::vector<int> ivec;

LinearInterp::LinearInterp(dvec x1, dvec x2)
{

    // Determine number of source grid points
    m = x1.size();        

    // Determine number of target grid points
    n = x2.size();

    int k;

    // Loop over target points and determine which source points bracket them
    for(k=0;k<n;++k)
    {
        low = std::lower_bound(x1.begin(),x1.end(),x2[k]);
        up = std::upper_bound(x1.begin(),x1.end(),x2[k]);

        // Index of lower bound for current point 
        lower.push_back(low-x1.begin());

        // Index of upper bound for current point 
        upper.push_back(up-x1.begin()+1); 

        b.push_back((x2[k]-x1[lower[k]])/(x1[upper[k]]-x1[lower[k]]));
        a.push_back(1-b[k]);    
    }
 
}

LinearInterp::~LinearInterp()
{
}


dvec LinearInterp::interp(dvec f)
{

    if(m != f.size())
    {
        throw std::length_error("Vector length mismatch");
    }

    dvec g;

    for(int k=0;k<n;++k)
    {
        g.push_back(f[lower[k]]*a[k]+f[upper[k]]*b[k]);
    }
    return g;
}



