#ifndef MEAN__SQUARE_
#define MEAN__SQUARE_

#include <math.h>
#include <vector>

using std::vector;
using mat =  vector<vector<double>>;
using Dot = struct Dot;

struct Dot {
    float x, y, w;
    Dot(float _x, float _y, float _w) : x(_x) , y(_y), w(_w) {} 
};

class slae {
    public:
        slae() = default;
        void build(vector<Dot> dots, int _n);
        mat solve();
    private:
        int n;
        mat m;
};

class Approximation {
    vector<float> coeffs;
    public: 
        void get_coeffs(mat data);

        vector<Dot> build(vector<Dot> dots);
};

#endif // MEAN__SQUARE_
