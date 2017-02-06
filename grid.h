#ifndef GRID_H
#define GRID_H

#include <vector>
#include <algorithm>

template <typename ElemType>
class Grid
{
public:
	Grid();
	Grid(size_t numRows, size_t numCols);
	~Grid(){

	};
	
	void clear();

	/* basic info funcs */

	size_t nRows() const;
	size_t nCols() const;
	bool empty() const;

	/* accessor funcs */

	/*iterator funcs */

	typedef typename std::vector<ElemType>::iterator iterator;
	typedef typename std::vector<ElemType>::const_iterator const_iterator;

	iterator begin();
	iterator end();

	iterator begin() const;
	iterator end() const;

	const_iterator cbegin ();
	const_iterator cend (); 

private:
	std::vector<ElemType> elems;
	size_t rows;
	size_t cols;

};

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
