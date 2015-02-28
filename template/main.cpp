#include <iostream>
#include <cstdlib>

#include <assert.h>
#include "tensor.hpp"
#include "vector_tensor.hpp"
//#include "matrix_tensor.hpp"

using namespace std;

int main() {
  Tensor<double> x(3,4);
  Vector<double> y(5);
  /*
  x[3] = 1;
  x[5] = 1;
  Tensor<double> y(3,4);
  Tensor<double> z = x + y;
  z.print();*/
  /*
  Matrix x(3,4);
  x.fill(1);
  Tensor* xp = &x;
  x.print();
  xp->print();
  
  Tensor** x = new Tensor*[2];
  Matrix* a = new Matrix(3,4);
  x[0] = new Matrix(3,4);
  x[1] = new Vector(2);
  for (int i = 0; i < 2; i++)
    delete x[i];
  delete[] x;
  
 Vector b(5);
  Tensor c(2);
  x[0] = &a;
  x[1] = &b;
  x[2] = &c;
  for (int i = 0; i < 3; i++)
    x[i]->print();
  */
  /*
  // how to do down_cast from tensor to matrix?
  Tensor x(5);
  cout << x.getSize()[0] << endl;
  cout << x[0] << endl;
  Tensor y(x);
  y[1] = 1;
  int s[2] = {2,3};
  Tensor z(2, s);
  cout << z.getDim() << endl;
  cout << z.getSize()[1] << endl;
  cout << "z[0] = " << z[0] << endl;
  z.fill(1.);
  cout << "z[0] = " << z[0] << endl;
  Tensor h = z+z;
  h[2] = 5;
  h[4] = 3;
  cout << h[1] << endl;
  cout << "h[3] = " << h[3] << endl;
  cout << "h = " << endl;
  h.print();
  cout << *x.getSize() << endl;
  Tensor l(5);
  l = y + x;
  cout << l[3] << endl;
  l += y;
  cout << l[3] << endl;
  l.print();
  Vector a(10);
  a[1] = 4;
  Vector b(10);
  b[1] = 2;
  b.print();
  cout << a.dot(b) << endl;
  Matrix p = (Matrix)b;
  cout << p.getSize()[0] << ", " << p.getSize()[1] << endl;
  Matrix x2(3,2); 
  x2(2,1) = 5;
  x2(1,0) = 4;
  Matrix y1(3,2); 
  y1(2,1) = 6;
  y1(1,0) = 5;
  cout << "y1 = " << endl;
  y1.print();
  y1.transpose();
  cout << "y1^T = " << endl;
  y1.print();
  Matrix l1(2,3);
  l1.fill(1);
  Matrix k = x2*l1;
  cout << "matrix*matrix = " << endl;
  k.print();
  Vector g(3); // automatic cast from tensor to vector/matrix?
  g.fill(2);
  Vector m = l1*g; // or define * for general tensor?
  cout << "matrix*vector = " << endl;
  m.print();*/
  return 0;
}
