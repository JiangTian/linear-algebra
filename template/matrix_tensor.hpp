#ifndef MATRIX_TENSOR_H
#define MATRIX_TENSOR_H

#include "tensor.hpp"
#include "vector_tensor.hpp"

class Matrix : public Tensor {
private:
  int row;
  int col;

public:
  Matrix(int i, int j): Tensor(i, j), row(i), col(j) {};
  Matrix(const Vector&);
  inline double& operator()(int i, int j);
  inline const double& operator()(int i, int j) const;
  int rows() const {return row;};
  int cols() const {return col;};
  void print() const override;
  void transpose();
  Vector operator*(const Vector& vec) const;
  Matrix operator*(const Matrix& mat) const;
  ~Matrix() {
    std::cout << "destructing Matrix" << std::endl;
  }
};

double& Matrix::operator()(int i, int j) {
  assert((i >= 0) && (i < row) && (j >= 0) && (j < col));
  return array[i*col + j];
}

const double& Matrix::operator()(int i, int j) const {
  assert((i >= 0) && (i < row) && (j >= 0) && (j < col));
  return array[i*col + j];
}
  
#endif
