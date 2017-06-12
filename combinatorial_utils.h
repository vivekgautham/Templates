#ifndef COMB_H
#define COMB_H


class PascalTriangle
{
  private:
    static std::map<unsigned, std::vector<int> > triangle;
    void configureTriangle(unsigned lines);
    unsigned currentlen = 0;

  public:

    auto static getBinomialCoeff(unsigned n, unsigned r)
    {
      auto row = triangle.find(n+1)
      if (row == triangle.end())
      {
        configureTriangle(2*n);
        auto row = triangle.find(n+1);
      }
      return row[r];
    }

};

void PascalTriangle::configureTriangle(unsigned lines)
{
  if (lines < currentlen)
    return;
  for (auto line = currentlen; line <= lines; line++)
  {
    std::vector <int> row;
    auto c = 1;  // used to represent C(line, i)
    for (auto i = 1; i <= line; i++)
    {
      //std::cout << c;
      row.push_back(c);
      c = c * (line - i) / i;
    }
    triangle[line] = row
  }
}


auto nCr(unsigned n, unsigned r)
{
  return PascalTriangle::getBinomialCoeff(n, r);
}

#endif
