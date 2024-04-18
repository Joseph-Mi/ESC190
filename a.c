#include <stdio.h>

void print_hi(){
  
}

int main()
{
  printf("Hello\n");

  int a[] = {1,2,5,7,8};
  int *p_a = &a; 

  printf("%d\n", a);
  printf("%d\n", p_a);
  printf("%d\n", *p_a);
  printf("%d\n", &a);
}