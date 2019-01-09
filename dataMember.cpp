

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cmath>
#include <vector>

class X{};

class Y:public virtual X{};

class Z:public virtual X{};

class A:public Y,public Z{};

int main() {
  printf("sizeof(X)=%d\n",sizeof(class X));
  printf("sizeof(Y)=%d\n",sizeof(class Y));
  printf("sizeof(Z)=%d\n",sizeof(class Z));
  printf("sizeof(A)=%d\n",sizeof(class A));
  return 0;
}
