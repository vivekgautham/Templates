#ifndef MATRIX_H
#define MATRIX_H
#include "header.h"
#include "grid.h"

template <typename ElemType=double>
class Matrix
{
public:
  Matrix(size_t, size_t);
  Matrix(const Matrix<ElemType>&);
  ~Matrix() {};

  std::pair<size_t, size_t> getDims() const;
  void setValue(size_t, size_t, ElemType val);
  ElemType getValue(size_t, size_t) const;

  std::vector<ElemType> operator[](size_t) const;
  ElemType operator~() const;
  Matrix<ElemType>& operator=(const Matrix<ElemType>&);

  Matrix<ElemType> inverse(const Matrix<ElemType>&) const;
  Matrix<ElemType> transpose(const Matrix<ElemType>&) const;

  size_t nRows() const
  {
    return matGrid.nRows();
  };
  size_t nCols() const
  {
    return matGrid.nCols();
  };
  ElemType getCofactor(size_t, size_t, size_t) const;
  ElemType getMinor(size_t, size_t, size_t) const;
  Matrix<ElemType> subMatrix(size_t, size_t, size_t) const;

  template <class E>
  friend std::ostream& operator<<(std::ostream&, const Matrix<E>&);

private:
  Grid<ElemType> matGrid;


};

template <typename ElemType>
std::ostream& operator<<(std::ostream& os, const Matrix<ElemType>& m)
{
	  os << m.matGrid;
    return os;
}

template <typename ElemType>
Matrix<ElemType>::Matrix(size_t numRows, size_t numCols)
{
  std::vector<ElemType> v(numCols);
  for (size_t i = 1; i <= numRows; i++) {
    matGrid.appendRow(v);
  }
}

template <typename ElemType>
Matrix<ElemType>& Matrix<ElemType>::operator=(const Matrix<ElemType>& rhs)
{
    if(&rhs == this)
        return *this;
    if (getDims() != rhs.getDims()){
      throw std::runtime_error("Not the same dimensions");
    }
    for (size_t i=0; i<nRows(); i++){
      for (size_t j=0; j<nCols(); j++){
        setValue(i,j,rhs.getValue(i,j));
      }
    }
}

template <typename ElemType>
void Matrix<ElemType>::setValue(size_t i, size_t j, ElemType val)
{
  matGrid.setValue(i,j,val);
}

template <typename ElemType>
ElemType Matrix<ElemType>::getValue(size_t i, size_t j) const
{
  return matGrid.at(i,j);
}

template <typename ElemType>
Matrix<ElemType> Matrix<ElemType>::subMatrix(size_t i, size_t j, size_t size) const
{
  Matrix Mij(size-1, size-1);
  size_t x=1;
  size_t y=1;
  for (size_t l=1; l<=nRows(); l++){
    if (l == i)
    {
      continue;
    }
    for (size_t m=1; m<=nCols(); m++){
      if (m == j)
      {
        continue;
      }
      Mij.setValue(x, y, getValue(l, m));
      y++;
    }
    y = 1;
    x++;
  }
  return Mij;
}

template <typename ElemType>
ElemType Matrix<ElemType>::getMinor(size_t i, size_t j, size_t size) const
{
  Matrix<ElemType> Mij = subMatrix(i, j, size);
  return ~Mij;
}

template <typename ElemType>
ElemType Matrix<ElemType>::getCofactor(size_t i, size_t j, size_t size) const
{
  return (std::pow(-1, i+j) * getMinor(i, j, size));
}

template <typename ElemType>
ElemType Matrix<ElemType>::operator~(void) const
{
    if (nRows() != nCols()){
      throw std::runtime_error("Not square matrix");
    }
    if (nRows() == 2){
      return ((getValue(1, 1)*getValue(2, 2)) - (getValue(1, 2)*getValue(2, 1)));
    }

    ElemType k = ElemType();
    ElemType cofactor = ElemType();
    for (size_t i=1; i<=nCols(); i++){
      cofactor = getCofactor(1, i, nCols());k += (getValue(1, i) * cofactor);
    }
    return k;
}

template <typename ElemType>
Matrix<ElemType>::Matrix(const Matrix& m)
{
  typename std::vector<ElemType> v(m.getDims().second);
  for (size_t i = 1; i <= m.getDims().first; i++) {
    std::copy(m[i].begin(), m[i].end(), v.begin());
    matGrid.appendRow(v);
  }
}

template <typename ElemType>
std::vector<ElemType> Matrix<ElemType>::operator[](size_t rowID) const
{
  typename std::vector<int> row(nCols());
  std::copy(matGrid[rowID].begin(), matGrid[rowID].end(), row.begin());
  return row;
}

template <typename ElemType>
std::pair<size_t, size_t> Matrix<ElemType>::getDims() const
{
  return std::make_pair(nRows(), nCols());
}


#endif
