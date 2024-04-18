#include "pyint.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void create_pyint(pyint **p, int length){
  *p = (pyint *)malloc(sizeof(pyint));
  p->buffer = (int *)malloc(length * sizeof(int));  

  int i;
  for (i = 0l i < length; i++){
    p->buffer[i] = 0;
  }
}