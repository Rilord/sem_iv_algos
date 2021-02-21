#include "hermite.hpp"

#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <stdbool.h>
#include <math.h>

template<typename T>
std::vector<T> sub(std::vector<T> const &v, int begin, int end)
{
    auto first = v.begin() + begin;
    auto last = v.begin() + end + 1;

    std::vector<T> tmp(first, last);

    return tmp;

}

static double findx;

bool biggerThan(record elem)
{
    return(elem.x >= findx);
}

interpolation::interpolation(unsigned int polynomSize)
{
    this->polynomSize = polynomSize;
}

void interpolation::loadFile(std::string name)
{
    std::ifstream f;
    f.open(name, std::ios::in);
    
    double x, y, dy;
    record tmp;

    table.records.clear();

    while (f >> x >> y >> dy)
    {
        tmp.x = x; tmp.y = y; tmp.dy = dy;    

        table.records.push_back(tmp);
    }

    f.close();
    std::sort(
            table.records.begin(), 
            table.records.end(), 
            [](record a, record b){
                return a.x < b.x;
            }
    );
}

void interpolation::tableSlice(double x)
{
    findx = x;
    size_t len = table.records.size();

    unsigned int num  = 
        this->polynomSize + 1;

    std::vector<record>::iterator it = 
        std::find_if(this->table.records.begin(), 
                table.records.end(), biggerThan);

    std::cout << it->x << "\n";
    if (it != this->table.records.end())
    {
        int half = ceil(num / 2.f);


        int ind = it - table.records.begin();

        while(ind < len && half > 0)
        {
            half--; 
            ind++;
        }


        ind -= num;


        if (ind < 0)
            ind = 0;

        table.records = std::vector<record> 
            (table.records.begin() + ind, table.records.begin() + ind + num);

        this->setSeparateDiffs();

        this->tableDuplicate();

        this->setHermiteDiffs();

        return;
    }

    table.records = sub(table.records, len - 1 - polynomSize, len);

    this->setSeparateDiffs();

    this->tableDuplicate();

    this->setHermiteDiffs();

    return;
}

void interpolation::setSeparateDiffs()
{
    std::vector<double> next;

    std::vector<double> x;

    std::vector<double> y;

    newtonDiffs.clear();

    for (std::vector<record>::iterator it = this->table.records.begin(); !(it == table.records.end()); it++)
    {
        x.push_back((*it).x); y.push_back((*it).y);

    }

    newtonDiffs.push_back(y[0]);

    for (unsigned int i = 1; i < this->table.records.size(); ++i)
    {
        next.clear();
        for (unsigned int t = 0; t < y.size() - 1; ++t)
        {
            next.push_back( ( y[t + 1] - y[t] ) / ( x[( t + i )] - x[t] ));
        }

        y = next; newtonDiffs.push_back(y[0]);
    }

}

void interpolation::setHermiteDiffs()
{

    std::vector<double> next;

    std::vector<double> x;

    std::vector<double> y;

    std::vector<double> dy;


    hermiteDiffs.clear();

    for (std::vector<record>::iterator it = this->hermite.records.begin(); !(it == this->hermite.records.end()); it++)
    {
        x.push_back((*it).x);
        y.push_back((*it).y); 
        dy.push_back((*it).dy);
    }

    hermiteDiffs.push_back(y[0]);

    for (unsigned int i = 1; i < hermite.records.size(); ++i)
    {
        next.clear();
        for (unsigned int t = 0; t < y.size() - 1; ++t)
        {
            if (i == 1)
            {
                if (x[t] == x[t + 1])
                    next.push_back(dy[t]);
                else
                    next.push_back((y[t + 1] - y[t]) / (x[t + i] - x[t]));

            }
            else
            {
                next.push_back((y[t + 1] - y[t]) / (x[t + i] - x[t]));
            }

        }

        y = next; hermiteDiffs.push_back(y[0]);
    }

}

void interpolation::invertTable()
{
    double tmp;
    for(auto &j: table.records)
    {
        tmp = j.x;
        j.x = j.y;
        j.y = tmp;
    }
    setSeparateDiffs();
}

void interpolation::tableDuplicate()
{
    this->hermite.records.clear();
    for(auto &v: table.records)
    {
        this->hermite.records.push_back(v);
        this->hermite.records.push_back(v);
    }
}

double interpolation::Newtonf(double x)
{

    double yy = table.records[0].y;
    double vl = 0.f;

    for (int i = 1; i < polynomSize + 1; i++)
    {
        vl = newtonDiffs[i];

        for (int j = 0; j < i; j++)
        {
            vl *= (x - table.records[j].x);
        }
        yy += vl;
    }

    return yy;
}

double interpolation::Hermitef(double x)
{

    double _y = hermite.records[0].y;

    for (double i = 1; i < polynomSize + 1; i++)
    {
        double val = hermiteDiffs[i];

        for (double j = 0; j < i; j++)
        {
            val *= (x - hermite.records[j].x);
        }
        _y += val;

    }
    return _y;
}

void interpolation::setPolynomSize(unsigned int polynomSize)
{
    this->polynomSize = polynomSize;
}
