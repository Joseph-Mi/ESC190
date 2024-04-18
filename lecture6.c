//pointer = address (same thing)

//void f(int a)
//f(43)
//43 gets copied into variable in function f
//a = 43 but 43 also exists
//f(&x) is the same logic. value gets sent to f. 
//if f changes value at address, the value x will get changed
//f(int *p_a) CANNOT take just an integer as it expects an address

#include <stdio.h>

void change_a(int *p_a){
  *p_a = 43;
}

void dont_change_a(int x){
  x = 44;
  printf("%d", x);
}

void swap(int *p_x, int *p_y){
  int temp = *p_x;
  *p_x = *p_y;
  *p_y = temp;
 }

 //swap_office(office1, office2):
 //   put person in office1 in hallway
 //   put person in office2 in office1
 //   put person in hallway in office2
 //
 //BA2026   BA2030
 //Mike     Morgan 
 //
 //swap_office(&Mike, &Morgan)
 //
 //

////////////////////////// STIRINGS IN C
//
/*C DOES NOT HAVE STRINGS
char s1[] = "abc"; array of type char with 'a', 'b', ...'\0'
char *s2 = “abc”;  put the block ‘a’, ‘b’, ‘c’, ‘\0’ somewhere in memory

const char *s2 =  "xyz";
s2[0] = 'y'; WILL NOT COMPILE

char *s1 = “abc”; warning: implicit conversion to char*
s1[0] = ‘x’; will compile, but might crash at runtime SOMETIME SWILL CRASH
*/

////////////////////////////////////// CONST
/*
char *s1 = “abc”; // warning: implicit conversion to char*
s1[0] = ‘x’; // will compile, but might crash at runtime
const char *s2 = “xyz”; // compiles with no warnings
s2[0] = ‘y’; // will not compile

const int a = 42;
a = 43; WILL NOT WORK

char * const str = "hello"; CANNOT EDIT VALUE OF STR, BUT YOU CAN EDIT THE VALUE OF STR AT ADDRESSES
str = “world”; //error
str[0] = ‘H’; // OK

const char * const str = "hello"; CANNOT EDIT VALUE OF STR OR THE VALUE OF STR AT ADDRESSES
str = “world”; //error
str[0] = ‘H’; // error



*/

 void set_arr0(int *arr){
  arr[0] == 44; //same as *arr = 44bs arr[j] is syntactic sugar for *(arr + j)
 }

 void set_arr1(int *arr){
  arr = 0; //changes the local arr to 0 NO CHANGES TO 
 }

int main(){
  int a = 42;
  change_a(&a);
  printf("%d", a);
  dont_change_a(a);
  printf("%d", a);

  int arr[] = {5,6,7,8};
  set_arr0(arr); //arr[0] is now 44; arr is a location to the first element 
  // &arr is the same as arr

  int x = 5;
  int y = 6;

  //swap(x,y) no way to do this
  swap(&x, &y);
}