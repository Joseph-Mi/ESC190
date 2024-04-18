//array in C
//int arr[] = {5, 10, 2};
//int arr[0] = {3};

// long int is a type: an int that can store larger ints than regular ints (addresses stored in same way long ints are stored)
//long int la = 5;

//functions
//specify function name, the parameters and the type of each parameter
//int add(int a, int b)
//{
  //return a + b;
//}

//another func
//int f(int *p_a)
//{
  //*p_a = 43;
//}
// function f takes an addy, and puts 43 in there
// analogous to passing a list in python

//arrays and pointers
//arrays are generally converted to the pointer to the first element
//a[0] is the same as *(a+0), the first element of a

//int *p, a = 60; // p is to be pointed to the 'a' variable holding the value at address of variable 
//int *p = &a; //now, p is pointed to the address of 'a' that holds the value of '60' 

double sum(double x, double y)
{
  return x + y;
}

void change_a(int *p_a)
{
  *p_a = 44; 
}

int main()
{
  // int * sores the address of an int
  //*p_a means the value at address p_a
  //&a means the address of a 
  //you copy the value to the local variable from the function call
  //arr[0] is the same as *arr
  
  int aa = 43;
  int *p_aa = &aa; // p_aa is the address of aa
  change_a(p_aa); //change value of p_aa. aa is now 44
  
  int a = 42;
  printf("%d\n", a);


  char *str = "hello";
  printf("%s\n is stores at address %ld", str, str);
  // casting: "converting" between types. it foes the same thing as printf with the wrong type
  //interpret it as if it were the type I say
  //int(1.2) -> 1(truncates)
  //(long int)str: just the address of the first element of str

  int arr[] = {5,6,7};
  printf("%d\n", arr[0]); //5
  printf("%d\n",arr);//address where array starts = address of 5
  printf("%d\n", *arr);//5 *arr is the same as arr[0]. same as *(arr+0)

///////////////////////////////////////////////////
  //int b = 8;
  //int *p_b = &b;
  //printf("%d %ld %d\n", b p_b, *p_b); //8 1032 5

  //
  //void f(int *aa)               1032 7
  //{                             1033
  //aa[0] = 7;                    1034 6
  //}                             1035
  //                              1036 7 you can go to an address and find the value
  //int main()
  //{
  //int b[] = {5,6,7};
  //b[0] = 6;
  //int *p = b;
  //f(b);
  //print
  //}


  //1032 45 //int b                     void
  //1033
  //1034
  //1035
  //1036
  //
  //2064
  //2065
  //2066
  //2067
  //2068
  //2069
}

