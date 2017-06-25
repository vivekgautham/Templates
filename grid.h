#ifndef GRID_H
#define GRID_H
#include "header.h"

template <typename ElemType>
class Grid
{
public:
	Grid();
	Grid(size_t numRows, size_t numCols);
	~Grid(){

	};

	void clear();

        std::vector<ElemType> operator[](unsigned);
        ElemType& at(unsigned, unsigned);

	/* basic info funcs */

	size_t nRows() const;
	size_t nCols() const;
	bool empty() const;

	/*iterator funcs */

	typedef typename std::vector<ElemType>::iterator iterator;
	typedef typename std::vector<ElemType>::const_iterator const_iterator;

	iterator begin();
	iterator end();

	iterator begin() const;
	iterator end() const;

	const_iterator cbegin ();
	const_iterator cend ();

  void appendRow(const std::vector<ElemType>&);
  void appendCol(const std::vector<ElemType>&);

  template <class E>
  friend std::ostream& operator<<(std::ostream& os, const Grid<E>& g);

private:
	std::vector<ElemType> elems;
	size_t rows;
	size_t cols;

};

template <typename ElemType>
std::ostream& operator<<(std::ostream& os, const Grid<ElemType>& g)
{
	  int index = 0;
	  for (unsigned i=0; i<g.nRows(); i++)
	  {
	      for (unsigned j=0; j<g.nCols(); j++)
	      {
	          std::cout << g.elems[index];
	          index += 1;
	      }
	      std::cout << std::endl;
	  }
	  return os;
}

template <typename ElemType>
std::vector<ElemType> Grid<ElemType>::operator[](unsigned a)
{
    unsigned startIndex;
    unsigned endIndex;
    startIndex = cols*(a-1);
    endIndex = startIndex + cols;
    typename std::vector<ElemType> resRow(endIndex-startIndex+1);

    for ( unsigned i = startIndex; i < endIndex; i++)
    {
        resRow.push_back(elems[i]);
    }
    return resRow;

}

template <typename ElemType>
ElemType& Grid<ElemType>::at(unsigned a, unsigned b)
{
    unsigned index;
    if (a > 0 && b > 0)
    {
        index = cols*(a-1) + (b-1);
    }
    else
    {
        throw "Index cannot be 0";
    }
    return elems[index];
}

template <typename ElemType>
size_t Grid<ElemType>::nRows() const
{
    return rows;
}

template <typename ElemType>
size_t Grid<ElemType>::nCols() const
{
    return cols;
}

/* Constructs a new, empty grid. */
template <typename ElemType> Grid<ElemType>::Grid() :
	elems(),
	rows(0),
	cols(0)
{

}

/* Constructs a grid of the specified size. */
template <typename ElemType>
Grid<ElemType>::Grid(size_t rows, size_t cols) :
  elems(rows * cols),
  rows(rows),
  cols(cols)
{

}

/* Appends row to the Grid  */
template <typename ElemType>
void Grid<ElemType>::appendRow(const std::vector<ElemType>& row)
{
    for (auto it = row.begin(); it != row.end(); it++)
    {
        elems.push_back(*it);

    }
    rows += 1;
    cols = row.size();
}

/* Iterator support, including const overloads. */

template <typename ElemType>
typename Grid<ElemType>::iterator Grid<ElemType>::begin() {
  	return elems.begin();
}

template <typename ElemType>
typename Grid<ElemType>::iterator Grid<ElemType>::end() {
  	return elems.end();
}

template <typename ElemType>
typename Grid<ElemType>::iterator Grid<ElemType>::begin() const {
  	return elems.begin();
}

template <typename ElemType>
typename Grid<ElemType>::iterator Grid<ElemType>::end() const {
  	return elems.end();
}

template <typename ElemType>
typename Grid<ElemType>::const_iterator Grid<ElemType>::cbegin() {
  	return elems.cbegin();
}

template <typename ElemType>
typename Grid<ElemType>::const_iterator Grid<ElemType>::cend() {
  return elems.cend();
}

#endif
