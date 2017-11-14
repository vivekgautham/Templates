#ifndef INTR_PROBS
#define INTR_PROBS
#include "matrix.h"
#include "header.h"

unsigned rainfallInTerrain(const Matrix<unsigned>& mat)
{
  class BorderDetail
  {
  public:
    BorderDetail(): height(0), i(0), j(0)
    {
    }
    BorderDetail(const BorderDetail& c)
      :height(c.getHeight()), i(c.getI()), j(c.getJ())
    {

    }
    BorderDetail(unsigned h, unsigned i, unsigned j)
      :height(h), i(i), j(j)
    {
    }
    ~BorderDetail()
    {
    }

    void printDetails(void) {
      std::cout << "height " << height << " Coordinates " << i << " " << j << '\n';
    }
    unsigned getHeight() const
    {
      return height;
    }
    unsigned getI() const
    {
      return i;
    }
    unsigned getJ() const
    {
      return j;
    }
  private:
    unsigned height;
    unsigned i;
    unsigned j;
  };

  class BorderComparator
  {
   public:
    bool operator() (const BorderDetail& d1, const BorderDetail& d2) const
    {
       return (d1.getHeight() > d2.getHeight() && d1.getI() > d2.getI() && d1.getJ() > d2.getJ());
    }
  };

  std::vector<BorderDetail> borderDetails;
  Matrix<bool> visited(mat.nRows(), mat.nCols());

  for (size_t i=1; i <= mat.nRows(); i++)
  {
    for (size_t j=1; j <= mat.nCols(); j++)
    {
      if (i == 1 || j == 1 || i == mat.nRows() || j == mat.nCols())
      {
        borderDetails.push_back(BorderDetail(mat.getValue(i, j), i, j));
        visited.setValue(i, j, true);
      }
    }
  }
  std::cout << visited << std::endl;

  std::cout << "Before Heap" << std::endl;
  for (std::vector<BorderDetail>::iterator iter=borderDetails.begin(); iter < borderDetails.end(); iter++)
  {
    iter->printDetails();
  }

  std::make_heap(borderDetails.begin(), borderDetails.end(), BorderComparator());

  std::cout << "After Heap" << std::endl;
  for (std::vector<BorderDetail>::iterator iter=borderDetails.begin(); iter < borderDetails.end(); iter++)
  {
    iter->printDetails();
  }

  std::cout << "Popping " << std::endl;
  unsigned result = 0;
  BorderDetail b = BorderDetail();
  while (borderDetails.size() > 0)
  {
    std::pop_heap(borderDetails.begin(), borderDetails.end(), BorderComparator());
    b = borderDetails.back();
    borderDetails.pop_back();
    b.printDetails();
    /*std::vector< std::pair <int, int> > allBorders = {
      std::make_pair<int, int>(b.getI()+1, b.getJ()),
      std::make_pair<int, int>(b.getI()-1, b.getJ()),
      std::make_pair<int, int>(b.getI(), b.getJ()+1),
      std::make_pair<int, int>(b.getI(), b.getJ()-1),
    };
    for (size_t i = 0; i < allBorders.size(); i++)
    {
      if (
        (allBorders[i].first < mat.nRows() && allBorders[i].first >= 0) \
        && (allBorders[i].second < mat.nCols() && allBorders[i].second >= 0) \
        && (!visited.getValue(allBorders[i].first, allBorders[i].second))
      )
      {
        result += std::max(0, (b.getHeight() - mat.getValue(allBorders[i].first, allBorders[i].second)));
        borderDetails.push_back(BorderDetail(std::max(mat.getValue(allBorders[i].first, allBorders[i].second), b.getHeight()), allBorders[i].first, allBorders[i].second));
        std::make_heap( borderDetails.begin(), borderDetails.end(), BorderComparator() );
        visited.setValue(allBorders[i].first, allBorders[i].second, true);
      }
    }*/
  }

  return result;
}



#endif
