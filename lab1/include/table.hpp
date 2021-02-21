#ifndef __TABLE_HPP__
#define __TABLE_HPP__

#include <vector>
#include <string>

typedef struct vec2_
{
    double x, y;
} vec2d;

class Table
{
    public:
        Table(int x, int y, int dy, int polynomSize);
        double Newtonf();
        double Hermitef();
        float NewtonseparateDiffs();
        float HermiteseparateDiffs();
        void loadFile(const std::string name);
        std::vector<double> sliceTable();
        
    private:
         
         


};
#endif
