#include <stdio.h>

void dont_change_a(int a){
  a = 42; // a is a local variable
}

void change_a(int *p_a){
  *p_a = 32; // go to the address a and change a value there
}

void dont_change_pa(int p_a){
  p_a = 0; // changes address value of a to 0, but the actual value of a is not changed 
}

void change_arr(int *arr)
{
  arr[0] = 5; //same things as pointer to arr, e.g *arr = 5
}

void dont_change_arr(int *arr)
{
   arr = 0; //works the same with ints // does not change the value at address arr
}

void change_s(const char *s)
{
  s[0] = 'x'; // compilation error. CANNOT CHANGE const
}

void change_str(char *s)
{
  s[0] = 'x'; // no compilation error, but
                 // may crash if s is actually
                 // constant
}

// Local arrays disappear once a function has finished running
// Arrays in C are not resizable
// malloc allocates space in the memory table to store a block of values

/*
#include <stdlib.h>
int *block_int = (int *)malloc(sizeof(int) * 150); // allocate space for 150 integers
                                                                         // malloc returns the address of 
                                                                         // element 0
                                                                         // cast the address to int *

block_int[7] = 42; 
*(block_int + 7) = 42;   // REMINDER: those are the same
                              // block + 7 gets to the right location in the memory table
                              // because C knows how many cells ints take up
*/

////////////////////////////////SIZEOF

// sizeof(int) = 4 bytes
// sizeof(char) = ALWAYS 1 byte
// sizeof(char *) // usually addresses take up 8 bytes 
                      // NOT the length of a string/array
// sizeof(int *)    // usually addresses take up 8 bytes
                      // NOT the length of a string/array

// int arr[] = {1, 2, 3}
// sizeof(arr)/sizeoff(arr[0]) // length of the array

/*
if arr is passed to a function, it is converted to a pointer:
void sz(int *a)   // int a[] is just syntactic sugar and won't help
{
     sizeof(a); // 8
}
*/



int main()
{
  char *s1 = "abc";
  change_arr(s1); // may cause a crash 

  char s2[] = "abc";
  change_str(s2); // OK can change the first element of the array
}



