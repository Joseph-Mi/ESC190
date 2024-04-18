#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pyint.h"

void create_pyint(pyint **p, int length){
  *p = (pyint *)malloc(sizeof(pyint));
  (*p)->buffer = (int *)malloc(length * sizeof(int));

  (*p)->length = length;
  int i;
  for (i = 0; i < length; i++){
    (*p)->buffer[i] = 0;
  }
}

void destroy_pyint(pyint *p){
  free(p->buffer);
  free(p);
}

/*void add_pyint(pyint *p, int value){
  
}*/

void set_pyint(pyint *p, int value){
  int i = 0;

  //value :190
  //buffer: 0 9 1

  while(value > 0){
    p->buffer[i] = value % 10;
    value = value /10;
    i++;
  }
}

void plusplus(pyint *p){
  int carry = 1;
  int i = 0;

  while (carry != 0 && i < p->length){
    int sum = p->buffer[i] + carry;
    p->buffer[i] = sum % 10;
    carry = sum / 10;
    i++;
  }

  if (carry == 1){
    p->buffer = (int *)realloc(p->buffer, (p->length + 1) * sizeof(int));
    p->buffer[p->length] = 1;
    p->length++;
  }
}

void print_pyint(pyint *p){
  int i;
  for (i = p->length - 1; i >= 0; i--){
    printf("%d", p->buffer[i]);
  }

}
