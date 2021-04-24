#include "mean_square.hpp"
#include <iostream>

void slae::build(vector<Dot> dots, int _n) {
    vector<Dot> data = dots;
    m.clear();
    m.resize(_n + 1);

    for (auto &j: m) {
        j.resize(_n + 2);
    }
    this->n = _n;
    for (auto i = 0; i < n + 1; i++)
        for (auto j = 0; j < n + 2; j++)
            m[i][j] = 0;

    for (auto i = 0; i < n + 1; i++) {
        for (auto j = 0; j < n + 1; j++) {
            auto coefs = 0.0;
            auto expanded_coefs = 0.0;

            for (auto k = 0; k < data.size(); k++) {
                coefs += data[k].w * 
                    pow(data[k].x, i) * 
                    pow(data[k].x, j);
                expanded_coefs += data[k].w * data[k].y * pow(data[k].x, i);

            }

            m[i][j] = coefs;
            m[i][n + 1] = expanded_coefs;
        }
    }

}

mat slae::solve() { 
    for (auto i = 0; i < n + 1; i++) {
        for (auto j = 0; j < n + 1; j++) {
            if (i == j)
                continue;

            auto sub_coef = m[j][i] / m[i][i];
            for (auto k = 0; k < n + 2; k++)
                m[j][k] -= sub_coef * m[i][k];
        }
    }

    for (auto i = 0; i < n + 1; i++) {
        auto div = m[i][i];
        for (auto j = 0; j < n + 2; j++)
            m[i][j] /= div;

    }

    return m;
}

void Approximation::get_coeffs(mat data) {
    coeffs.clear();
    for (auto i = 0; i < data.size(); i++) {
        this->coeffs.push_back(data[i][data.size()]);
    }

}

vector<Dot> Approximation::build(vector<Dot> dots) {
    vector<Dot> tmp;

    for (float i = dots[0].x; i < dots.back().x + 0.11111; i += 0.1) {
        auto d = Dot(i, 0, 0); 

        for (auto j = 0; j < coeffs.size(); j++) {
            d.y += pow(d.x, j) * coeffs[j];
        }

        tmp.push_back(d);
    }
    return tmp;
}


