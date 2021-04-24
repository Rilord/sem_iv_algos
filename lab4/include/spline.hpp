#ifndef SPLINE_
#define SPLINE_

#include <vector>
#include "hermite.hpp"
using std::vector;

class Spline {
    using vec = vector<double>;
public:
        Spline(vector<dot> _dots);

        unsigned GetPos(dot &a);

        dot solve(double x);
private:
    vector<dot> dots;


};

#endif // SPLINE_

