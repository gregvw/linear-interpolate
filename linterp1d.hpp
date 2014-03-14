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
        int m;                         // Number of source points
        int n;                         // Number of target points

        dvec a;                        // Left weights
        dvec b;                        // Right weights
        dvec::iterator low,up;         // index iterator
        ivec lower;                    // lower bounds
        ivec upper;                    // upper bounds


};

