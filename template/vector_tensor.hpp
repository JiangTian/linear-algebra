#ifndef VECTOR_TENSOR_H
#define VECTOR_TENSOR_H

#include "tensor.hpp" 
//#include "matrix_tensor.hpp"
template <typename T>
class Vector : public Tensor<T> {
public://syntax for parent class and using its constructor
  Vector(int length): Tensor<T>::Tensor(length) {}; 
  //void print() const override;
  T dot(const Vector& vec) const {
    assert(vec.getTotalLength() == Tensor<T>::total_length);
    T prod = 0.;
    for (int i = 0; i < Tensor<T>::total_length; i++)
      prod += Tensor<T>::array[i] * vec[i];
    return prod;
  };
  //operator Matrix();
  ~Vector() {
    std::cout << "destructing Vector" << std::endl;
  }
};

#endif
