#include "hermite.hpp"

#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <stdbool.h>
#include <math.h>


void interpolation::loadFile(std::string name) {
    std::ifstream f;

    f.open(name, std::ios::in);

    int i = 0;

    double x;

    std::string line;

    table.records.clear();

    while (getline(f, line)) {

        while (sscanf(line.c_str(), "%lf", &x) == 1)
            table.records[i].push_back(dot { x = x });
        i++;
    }

    f.close();

    std::sort(table.records.begin(),
            table.records.end(),
            [] (dot a, dot b) {
            return a.x < b.x;
            }
            );
}

void interpolation::printTable() {
    std::cout << "Y / X ";

    for (int i = 0; i < table.records[0].size(); i++)
        std::cout << table.records[0][i].x << " ";
}

void interpolation::getBase(dot arg) {
    base_x = std::vector (x_args.begin(), x_args.end());

    std::sort(base_x.begin(), base_x.end(),
            [arg] (dot a, dot b) {
            return abs(a.x - arg.x) < abs(b.x - arg.x);
            }
    );


    std::sort(base_x.begin(), base_x.end(),
            [] (dot a, dot b) {
            return a.x < b.x;
            }
    );

    base_x = std::vector (x_args.begin() + nx + 1, x_args.end());


    base_y = std::vector (y_args.begin(), y_args.end());

    std::sort(base_y.begin(), base_y.end(),
            [arg] (dot a, dot b) {
            return abs(a.x - arg.y) < abs(b.x - arg.y);
            }
    );

    std::sort(base_y.begin(), base_y.end(),
            [] (dot a, dot b) {
            return a.x < b.x;
            }
    );


    base_y = std::vector (y_args.begin() + ny + 1, y_args.end());
}

void interpolation::tableSplit() {
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

void interpolation::getPolynomial() {

    int k, l;

    int rng_x = std::find(x_args.begin(), x_args.end(), base_x[0]) - 
        x_args.begin();

    int rng_y = std::find(y_args.begin(), y_args.end(), base_y[0]) - 
        y_args.begin();
    
    for (int i = rng_x, k = 0; i < rng_x + nx + 1; i++, k++)
        for (int j = rng_y, l = 0; j < rng_y + ny + 1; j++, l++)
            temp[l][k] = matrix[i][j];

    std::vector<dot> new_set;
    
    for (int i = 0; i < temp.size(); i++) {
        for (int j = 0; j < base_x.size(); j++) {
            temp[i][j].y = base_x[j].x;
            std::swap(temp[i][j].x, temp[i][j].y);
        }

        new_set.push_back(NewtonPolynom.build());

    }


            
}
