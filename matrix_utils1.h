#ifndef MAT_UTILS1_H
#define MAT_UTILS1_H

#include "matrix_utils1.h"

template <typename T= double >
Matrix<T> createNumMatrix(const std::string matInString)
{
  std::stringstream matStream(matInString);
  size_t rows;
  size_t cols;
  matStream >> rows;
  matStream >> cols;
  Matrix <T> mat(rows, cols);
  T tmp;
  for (size_t i=1; i<=rows; i++){
    for (size_t j=1; j<=rows; j++){
      matStream >> tmp;
      mat.setValue(i, j, tmp);
    }
  }
  std::cout << mat << std::endl;
  return mat;
}

#endif
