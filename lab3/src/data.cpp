#include "data.hpp"
#include <iostream>
#include <fstream>
#include <iterator>
#include <sstream>

vector<dot> readDots(string &filename) {
    vector<dot> dots;

    std::ifstream file (filename, std::ios::in);


    std::string line;

    std::stringstream ss;

    while (getline(file, line)) {
        double x, y;

        ss << line;

        std::stringstream(line) >> x >> y;
        dots.push_back(dot {x, y});
    }

    file.close();

    return dots;
}
