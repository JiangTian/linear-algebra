#ifndef VECTOR_TENSOR_H
#define VECTOR_TENSOR_H

#include "tensor.hpp" 

class Vector : public Tensor {
public:
  Vector(int length): Tensor(length) {}; 
  void print() const;
  double dot(const Vector& vec) const;
};

#endif
