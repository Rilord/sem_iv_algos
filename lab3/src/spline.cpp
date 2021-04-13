#include <iostream>
#include "spline.hpp"


Spline::Spline(vector<dot> _dots) : dots(_dots) {}

unsigned Spline::GetPos(dot &a) { 
    auto i = 1;
    
    while (i < dots.size() && dots[i].x < a.x)
        i += 1;

    return i - 1;
}
dot Spline::solve(double x) {
    vec x_args;
    for  (auto j: dots) {
        x_args.push_back(j.x);
    }
    vec y_args;
    for  (auto j: dots) {
        y_args.push_back(j.y);
    }


    vec a(y_args.begin(), y_args.end() - 1);
    vec c;
    for (auto i = 0; i <  dots.size() - 1; i++) {
        c.push_back(0);
    }

    vec ksi_coef { 0, 0 }, eta_coef { 0, 0 };

    for (auto i = 2; i < dots.size(); i++) {
        auto xhi = x_args[i] - x_args[i - 1], 
            xhi_1 = x_args[i - 1] - x_args[i - 2];
        auto yhi = y_args[i] - y_args[i - 1], 
            yhi_1 = y_args[i - 1] - y_args[i - 2];

        auto fi = 3 * (yhi / xhi - yhi_1 / xhi_1);

        ksi_coef.push_back(-xhi / 
                (xhi_1 * ksi_coef[i - 1] + 
                2 * (xhi_1 + xhi)));

        eta_coef.push_back((fi - xhi_1 * eta_coef[i - 1]) / 
                (xhi_1 * ksi_coef[i - 1] + 
                2 * (xhi_1 + xhi)));
    }

    c[dots.size() - 2] = eta_coef[-1];

    for (auto i = dots.size() - 2; i > 0; i--)
        c[i - 1] = ksi_coef[i] * c[i] + eta_coef[i];

    vec b, d;

    for (auto i = 1; i < dots.size() - 1; i++) {
        auto xhi = x_args[i] - x_args[i - 1];
        auto yhi = y_args[i] - y_args[i - 1];
        b.push_back(yhi / xhi - (xhi * (c[i] + 2 * c[i - 1])) / 3);
        d.push_back((c[i] - c[i - 1]) / (3 * xhi));
    }

    b.push_back((y_args[-1] - y_args[-2]) / (x_args[-1] - x_args[-2]) - 
            ((x_args[-1] - x_args[-2]) * 2 * c[-1]) / 3);

    d.push_back(-c[dots.size() - 2] / (3 * (x_args[-1] - x_args[-2])));

    dot tmp {x, 0};

    auto pos = GetPos(tmp);

    auto res = 
        a[pos] + 
        b[pos] * (x - dots[pos].x) +  
        c[pos] * (x - dots[pos].x) * 
                 (x - dots[pos].x) + 
        d[pos] * (x - dots[pos].x) * 
                 (x - dots[pos].x) * 
                 (x - dots[pos].x);


    return dot{ x, res };
        }
