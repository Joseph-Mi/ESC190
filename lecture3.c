#include <stdio.h>

int main()
{ // Kernighan and Ritchie (K&R) style: the curly brace goes on the nect line after the function head
  // before we us ea variable, we need to declare it
  // optionally, initializing assigns an initial value to variable

  int a = 5; // initialize
  int b; // not initialized
  //printf("Hello! \n");
  
  char *s1 = "hi!"; //stores address of h in s1 (*s1)
  printf("%s\n", s1); // interpr!et s1 to whatever the % says
  printf("%ld\n", s1); // %s: string  %d: integer %ld: long decimal (another integer)
  printf("the string is: %s, the address is %ld\n", s1, s1);

  int c = 43;
  printf("%ld\n", c);

  char *c1 = 'abc'; //error
  char c2 = '1234'; //error doesnt work
  char c3 = '@'; //correct

  //printf("%ld\n", c1)


////////////////////////////////////////
  //int number = 91;
  char *word = "abcd";
  char letter = '@';
  double pi = 3.14;

  //printf("integer: %d\n", number);
  //printf("char is %c\n", letter);
  //printf("double: %d\n", pi);

  int *p_a = &a;
  printf("address is: %ld\n", p_a);
  printf("value is: %d\n", *p_a);
  printf("value is: %d\n", a);

  double x = 12.34;
  double *addy_of_var_x = &x;
  double y = 25 + *addy_of_var_x; // y + 12.34

  char *str1 = "hello";
  // * used as part of the type char *
  char c = *str1; 
  //* is used as a dereferencing operator = get value at address

  int a[] = {1,2,5,7,8};
  int *p_a = &a; 

  printf("%d\n", a);
  printf("%d\n", p_a);
  printf("%d\n", *p_a);
  printf("%d\n", &a);
  return 0;
}

//shows how 
//1032  'h'
//1033  'i'
//1034  '!'
//1035  '\0' null
//
//3066  1032
//
//3070  '@' //c// type: char
//
//4000  42  //a// type: int
//
//
//