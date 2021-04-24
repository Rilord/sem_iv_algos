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
    std::vector<std::vector<double>> records;
} funcTable;

class newtonPolynom{
    public:
        newtonPolynom(unsigned int n, std::vector<double> values, 
                std::vector<double> args, double x);
        double build();
    private:
        double x;
        unsigned int n;
        std::vector<double> values; 
        std::vector<double> args; 
        std::vector<double> diffs;
        void calculate();

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
        void loadFile(const std::string name);
        void getBase(dot arg);
        void setPolynomSize(unsigned int nx, unsigned int ny);
        void setArg(dot arg);
        void tableSplit();
        /* diffs methods */ 

       /* polynom funcs */
        double getPolynomial();


    private:
        unsigned int nx, ny;
        dot arg;

        funcTable table;
        std::vector<double> x_args;
        std::vector<double> y_args;

        std::vector<double> base_x;
        std::vector<double> base_y;


        std::vector<std::vector<double>> matrix;

        double answer;

};
#endif
