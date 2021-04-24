#include "hermite.hpp"

#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <stdbool.h>
#include <math.h>

using std::vector;


void interpolation::loadFile(const std::string name) {

    std::ifstream f;

    f.open(name, std::ios::in);

    int i = 0;

    double x;

    std::string line;
    std::string temp;

    table.records.clear();


    while (getline(f, line)) {

        std::istringstream ss(line);

        table.records.emplace_back(std::istream_iterator<double>{ss}, 
                std::istream_iterator<double>{});

    }

    f.close();

    std::sort(table.records[0].begin(),
            table.records[0].end(),
            [] (double a, double b) {
                return a < b;
            }
            );

    tableSplit();
    getBase(this->arg);
}

void interpolation::printTable() {
    std::cout << "Y / X ";

    for (int i = 0; i < table.records[0].size(); i++)
        std::cout << table.records[0][i] << " ";
}

void interpolation::getBase(dot arg) {

    base_x.clear();
    base_y.clear();

    base_x = std::vector (x_args.begin(), x_args.end());

    std::sort(base_x.begin(), base_x.end(),
            [arg] (double a, double b) {
            return abs(a - arg.x) < abs(b - arg.x);
            }
    );

    base_x = std::vector (base_x.begin(), base_x.begin() + nx + 1);

    std::sort(base_x.begin(), base_x.end(),
            [] (double a, double b) {
            return a < b;
            }
    );


    base_y = std::vector (y_args.begin(), y_args.end());

    std::sort(base_y.begin(), base_y.end(),
            [arg] (double a, double b) {
            return abs(a - arg.y) < abs(b - arg.y);
            }
    );


    base_y = std::vector (base_y.begin(), base_y.begin() + ny + 1);

    std::sort(base_y.begin(), base_y.end(),
            [] (double a, double b) {
            return a < b;
            }
    );


}

void interpolation::tableSplit() {

    x_args.clear();
    y_args.clear();
    matrix.clear();

    matrix.resize(table.records.size() - 1);

    for (auto i = 0; i < table.records.size() - 1; i++) {
        matrix[i].resize(table.records[1].size() - 1);
    }

    x_args = table.records[0];

    for (int i = 1; i < table.records.size(); i++) {
        y_args.push_back(table.records[i][0]);
    }

    for (int i = 1; i < table.records.size(); i++) {
        for (int j = 1; j < table.records[i].size(); j++) {
            matrix[i - 1][j - 1] = table.records[i][j];
        }
    }

}

interpolation::interpolation(unsigned nx, unsigned ny, dot arg) {
    this->nx = nx;
    this->ny = ny;
    this->arg = arg;
}

double interpolation::getPolynomial() {
    std::vector<double> coefs;

    std::vector<std::vector<double>> base_matrix;

    base_matrix.resize(ny + 1);

    for (auto &row: base_matrix) {
        row.resize(nx + 1);
    }

    int startX = std::find(x_args.begin(), 
                x_args.end(), base_x[0]) - x_args.begin();

    int startY = std::find(y_args.begin(), 
                y_args.end(), base_y[0]) - y_args.begin();

    for (int i = startY, k = 0; i < startY + ny + 1; i++, k++) {

        for (int j = startX, l = 0; j < startX + nx + 1; j++, l++) {
            base_matrix[k][l] = matrix[i][j];  
        }
    }

    for (auto i = 0; i < base_matrix.size(); i++) {

        coefs.push_back(newtonPolynom(nx, base_matrix[i], base_x, arg.x).build());
    }

    answer = newtonPolynom(ny, coefs, base_y, arg.y).build();

    return answer;
}

void interpolation::setPolynomSize(unsigned int nx, unsigned int ny) {
    this->nx = nx;
    this->ny = ny;
}

void interpolation::setArg(dot arg) {
    this->arg = arg;
}

newtonPolynom::newtonPolynom(unsigned int n, std::vector<double> values, 
        std::vector<double> args, double x) {
    this->values = values;
    this->args = args;
    this->n = n;
    this->x = x;
}

double newtonPolynom::build() {

    diffs.clear();
    std::vector<double> next;
    std::vector<double> y (values.begin(), values.end());

    diffs.push_back(y[0]);

    for (auto i = 1; i < values.size(); i++) {

        next.clear();
        for (auto t = 0; t < y.size() - 1; t++) {
            next.push_back(
                    (y[t + 1] - y[t]) 
                    / 
                    (args[t + i] - args[t]));
        }
        y = next; diffs.push_back(y[0]);
    }


    double y0 = values[0];
    double val = 0.0;

    for (auto i = 1; i < diffs.size(); i++) {
        val = diffs[i];
        for (auto j = 0; j < i; j++) {
            val *= (x - args[j]);
        }
        y0 += val;
    }


    return y0;
}


