#include <iostream>
#include <cstdlib>

#include <assert.h>
#include "tensor.hpp"
#include "vector_tensor.hpp"

using namespace std;

int main() {
  Tensor x(2,3);
  cout << x[3] << endl;
  //Tensor y(x);
  Tensor y(2,3);
  y[3] = 1;
  int s[2] = {2,3};
  Tensor z(2, s);
  cout << z.getDim() << endl;
  cout << z.getSize()[1] << endl;
  Tensor h = z+z;
  cout << h[1] << endl;
  cout << *x.getSize() << endl;
  cout << *(x.getSize()+1) << endl;
  cout << x.getSize()[0] << ", " << x.getSize()[1] << endl;
  cout << y.getSize()[0] << ", " << y.getSize()[1] << endl;
  Tensor l(5);
  l = y + x;
  cout << l[3] << endl;
  l += y;
  cout << l[3] << endl;
  Vector a(10);
  a[1] = 4;
  Vector b(10);
  b[1] = 2;
  b.print();
  cout << a.dot(b) << endl;
  return 0;
}
