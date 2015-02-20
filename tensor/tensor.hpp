#ifndef TENSOR_H
#define TENSOR_H

class Tensor {
protected:
  int dim;
  int* size;
  int total_length;
  double* array;

public:
  //constructors
  Tensor(): dim(0), total_length(0) {
    
}; // what does "= default" do?
  Tensor(int length);
  Tensor(int row, int column);
  Tensor(int dim1, int dim2, int dim3);
  Tensor(int dim, int* dim_array);
  //utility functions
  void fill(double);
  int* getSize() const {return size;};
  int getDim() const {return dim;};
  int getTotalLength() const {return total_length;};
  //print?
  //set, get functions
  double& operator[](int);
  const double& operator[](int) const;
  //arithmetic operations
  Tensor operator+(const Tensor&) const;
  Tensor operator+(const double) const;
  Tensor operator-(const Tensor&) const;
  Tensor& operator+=(const Tensor&);
  Tensor operator*(const double) const;
  Tensor operator*(const Tensor&) const;
  //copy constructor
  Tensor(const Tensor&);
  //copy assignment
  Tensor& operator=(const Tensor&);
  //destructor
  ~Tensor() {
    if (dim > 0)
      delete[] size;
      delete[] array;
  }
};

#endif
