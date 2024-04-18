#include <stdio.h>
#include <stdlib.h>

int main(){
  char *p = (char *)malloc(1000);
  printf("Value: %c\n", p[500]); //*(p+500)//sengmentation fault: tried to access memory that it wasnt supposed to access

  int **p_p_int;
  p_p_int = (int **)malloc(2 * sizeof(int *));

  //p_p_int is a block of int int *;too few arguments in function call
  int *p_int = *p_p_int; //p_p_int[0] or *(p_p_int + 0)
  /*
  block of int *
  <address1> (of type int *), <address2> <- stored at address p_p_int
  *p_p_int <- <address1>

  put *p_p_int into variable p_int -> p_int contains address1
  */

  int my_int = *p_int; //NOT OK// tries to go address1 but it is a garbage address(malloc gives list of garbage addresses, so when you try to access it, it will break)
}
