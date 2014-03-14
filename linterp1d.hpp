#include <iostream>     // std::cout
#include <algorithm>    // std::lower_bound, std::upper_bound
#include <vector>       // std::vector

typedef std::vector<double> dvec;
typedef std::vector<int> ivec;


class LinearInterp {

    public:
        LinearInterp(dvec x1, dvec x2);
        ~LinearInterp();

        dvec interp(dvec f);

    private:
        dvec *a;
        dvec *b;
        dvec::iterator low,up;
        ivec* lower;
        ivec* upper; 
};

