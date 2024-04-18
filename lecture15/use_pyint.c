#include "pyint.h"
#include <stdio.h>

int main(){
  pyint *p;
  create_pyint(&p, 3);
  set_pyint(p, 190);
  printf("hi\n");
}