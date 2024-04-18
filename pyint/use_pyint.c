#include "pyint.h"
#include <stdio.h>

int main(){
  int a;
  int *p_a = &a;
  int **p_p_a = &p_a
  
  *p_a (type int)
  *(&a) (type int)
  **p_p_a (type int)
  *(*(&p_a)) // same as *p_a // same as a
  
  
  

  pyint *p = 0;
  create_pyint(&p, 3);
  set_pyint(p, 230);

  print_pyint(p);

  plusplus(p);
  print_pyint(p);

  printf("hi\n");
}