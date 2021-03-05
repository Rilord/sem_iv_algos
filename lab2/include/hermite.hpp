#ifndef __HERMITE_H__
#define __HERMITE_H__

#include <vector>
#include <string>

typedef struct dot_struct {
    double x, y;
} dot;

typedef struct result_struct {
    double x, y, z;
    unsigned int nx, ny;
} result;

typedef struct funcTable_struct {
    std::vector<std::vector<dot>> records;
} funcTable;

class newtonPolynom{
    public:
        newtonPolynom();
        void build();

    private:

};

class interpolation {
    public:
        interpolation(
                unsigned int nx, 
                unsigned int ny,
                dot arg
                );
        /* table methods */

        void printTable();
        void loadFile(std::string name);
        void getBase(dot arg);
        void setPolynomSize(unsigned int polynomSize);
        void tableSplit();
        /* diffs methods */ 

       /* polynom funcs */
        void getPolynomial();

        double Newtonf(double x);
        double multiNewton();

    private:
        unsigned int nx, ny;
        dot arg;

        funcTable table;
        std::vector<dot> x_args;
        std::vector<dot> y_args;

        std::vector<dot> base_x;
        std::vector<dot> base_y;

        std::vector<std::vector<double>> newton;

        std::vector<std::vector<dot>> matrix;
        std::vector<std::vector<dot>> temp, first, second, third;

};
#endif
