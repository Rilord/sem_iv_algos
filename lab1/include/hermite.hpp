#ifndef __HERMITE_H__
#define __HERMITE_H__

#include <vector>
#include <string>

typedef struct record_
{
    double x, y, dy;
} record;

typedef struct result_
{
    double x, y;
    unsigned int polynomSize;
    std::string type;
    
} result;



typedef struct funcTable_
{
    std::vector<record> records;
} funcTable;

class interpolation
{
    public:
        interpolation(
                unsigned int polynomSize
                );
        /* table methods */
        void loadFile(std::string name);
        void tableSlice(double x);
        void invertTable();
        void tableDuplicate();
        void tablePrint();
        void setPolynomSize(unsigned int polynomSize);
        /* diffs methods */ 
        void setSeparateDiffs();
        void setHermiteDiffs();
        /* polynom funcs */
        double Newtonf(double x);
        double Hermitef(double x);


    private:
        funcTable table;
        funcTable hermite;
        unsigned int polynomSize;
        std::vector<double> newtonDiffs;
        std::vector<double> hermiteDiffs;
        std::string filename;


};
#endif
