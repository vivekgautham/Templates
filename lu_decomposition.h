#ifndef LU_H
#define LU_H
#include "grid.h"

template <typename Elem>
std::pair< Grid<Elem>, Grid<Elem> > luDecompose(Grid<Elem> input)
{
    Grid<Elem> u(input.nRows(), input.nCols());
    Grid<Elem> l(input.nRows(), input.nCols());

    for (auto row=1; row <= input.nRows(); row++)
    {
        for (auto col=1; col <= input.nCols(); col++)
        {
            if (col < row)
            {
                l.at(col, row) = Elem();
            }
            else
            {
                l.at(col, row) = input.at(col, row);
                for (auto k=1; k<row; k++)
                {
                    l.at(col, row) = l.at(col, row) - l.at(col, k) * u.at(k, row);
                }
            }
        }
        for (auto col=1; col <= input.nCols(); col++)
        {
            if (col < row)
            {
                u.at(row, col) = Elem();
            }
            elif (col == row)
            {
                u.at(row, col) = Elem();
            }
            else
            {
                u.at(row, col) = input.at(row, col)/l.at(row, col);
                for (auto k=1; k<row; k++)
                {
                    u.at(row, col) = u.at(row, col) - ((l.at(row, k) * u.at(k, col)) / l.at(row, k));
                }
            }
        }
    }
    auto result = std::make_pair(u, l);
    return result;
}
