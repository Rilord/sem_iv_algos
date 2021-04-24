#include "data.hpp"
#include <iostream>
#include <fstream>
#include <iterator>
#include <sstream>


vector<Dot> readDots(string &filename) {
    vector<Dot> dots;

    std::ifstream file (filename, std::ios::in);

    std::string line;

    std::stringstream ss;

    while (getline(file, line)) {
        double x, y, w;

        ss << line;

        std::stringstream(line) >> x >> y >> w;
        dots.push_back(Dot(x, y, w));
    }

    file.close();

    return dots;
}
