#ifndef COMB_H
#define COMB_H
#include "header.h"

class PascalTriangle
{
  private:
    unsigned currentlen;
    std::map <unsigned, std::vector<unsigned> > triangle;
    void configureTriangle(unsigned lines);

  public:
    PascalTriangle();
    unsigned getBinomialCoeff(unsigned n, unsigned r);

};

PascalTriangle::PascalTriangle()
  : currentlen(0)
{
  configureTriangle(currentlen+1);
}

unsigned PascalTriangle::getBinomialCoeff(unsigned n, unsigned r)
{
  unsigned coeff=0;
  if (r > n)
  {
    throw std::runtime_error("Make sure n ≥ r ≥ 0");
  }
  if (triangle.find(n+1) == triangle.end())
  {
    configureTriangle(2*(n+1));
  }
  std::vector<unsigned> row = triangle.find(n+1)->second;
  coeff = row[r];
  return coeff;
}

void PascalTriangle::configureTriangle(unsigned lines)
{
  if (lines < currentlen)
    return;
  std::vector<unsigned> row;
  for (auto line = currentlen; line <= lines; line++)
  {
    unsigned c = 1;
    for (unsigned i = 1; i <= line; i++)
    {
      row.push_back(c);
      c = c * (line - i) / i;
    }
    triangle[line] = row;
    row.clear();
  }
  currentlen = lines;
}

unsigned nCr(unsigned n, unsigned r)
{
  return PascalTriangle().getBinomialCoeff(n, r);
}

#endif
