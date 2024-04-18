// all variables need to be declared

char *s = "xyz";
// char * = address of char
// s is the address where x is stores

//int *p_a = &a;
// p_a is the address where a is stored

int arr[] = {4,5};
// arr gets converted into the address where the 4 is stored

// &a = address where a is stored
// thus, p_a is the address of a
// *p_a is the value at address p_a
// *arr is the value at address arr (same as arr[0])

void f(int a){
  a = 42;
}
//f(43) copies 43 to local variable a. the var a is local, so f has no effect

void g(int *p_a){
  p_a = 0;
}

// f(&a) copies &a to local variable p_a. the variable p_a is local, but *p_a is the same as a, so f has no effect

///////////////////////////////////////////////////////////// blocks of values

//strings and arrays are examples of blocks of values
//blocks of values are stores consecutively 

//e.g "hi"
//1032: 'h', 1033: 'i', 1034: '\O'

//{3,4}
//2064: 3, (2064+4): 4

///////////////////////////// pointer arithmetic
//pointers = addresses

//char *s = "hi"; 
//1032: 'h', 1033: 'i'
//s+1 // 1033

//2064: 3, (2064+4): 4 //{3,4}
//int arr[] = {3,4}
//arr+1; // 2064+4
//*(arr+1); // 4

//arr[5] = *(arr+5)
//syntactic sugar/salt
//salt : adding featues to the syntax that constrain what can be said 
//NOT same as L[5] in python 

int main(){
  int a = 45;
  printf("a is: %d\n", &a);

  g(&a);
  printf("a is: %d NOT CHANGED\n", &a);
}
