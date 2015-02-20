#ifndef VECTOR_H
#define VECTOR_H

class Vector {
 private:
  int n;
  double* array;

 public:
  Vector();
  Vector(int);
  void fill(double);
  int size() const {return n;};
  double& operator[](int);
  const double& operator[](int) const;
  Vector operator+(const Vector&) const;
  Vector operator+(const double) const;
  Vector& operator+=(const Vector&);
  Vector operator-(const Vector&) const;
  Vector operator*(const double) const;
  Vector operator*(const Vector&) const;
  double dot(const Vector&) const;
  Vector(const Vector&);
  Vector& operator=(const Vector&);
  void print() const;
  ~Vector() { 
    if (n > 0) 
      delete[] array;}
};
 
#endif
