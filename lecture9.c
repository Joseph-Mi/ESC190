#include <stdio.h>
#include <string.h>
//#include "a.h" // Include your own header file like this
#include <math.h>
//#include "student.h"

//#define PI 3.14 //substitute 3.14 as PI that is not part of a longer string. FASTER THAN DEFINING A VARIABLE (search and replace)

/*
compliler takes in C code and converts it to executable file: what the operating system can run
C compiler runs gcc
gcc lecture9.c -o engsci.exe
./a runs a.c file

Header files:
#include copy and pastes the file into program
*/

typedef struct student{
  char name[20];
  int age;
}student; //struct student and student are different

typedef struct student1{
  char *name;
  int age;
}student1;

int main() {
  printf("Hello Wld");

  student s; 
  strcpy(s.name, "James");

  student1 s1;
  //strcpy(s1.name, "James"); //DOTES NT WORK AS s2.name is not a valid address
  s1.name = "James"; //works!
  s1.name = (char *)malloc(20 * sizeof(char));


  /// free 
  free(s1.name);

  student1 *block1 = (student1 *)malloc(20 * sizeof(char));

  // /say_hi();

  /*
  STRINGS
  
  char *name;
  strcpy(name, "Alice"); BAD, NAME IS NOT A VALID ADDESSS. CANNOT COPY THERE

  name = (char *)malloc(100*sizeof(char));
  strcpy(name, "Alice"); //OK NOW

  name = "Alice"; OK as well, but cannot modify name[0]; if it didnt free name, that's a memory leak
  //this overwrites the name[0] with the "A". name is a const char * essentially
  //loses location of malloc block, so cannot free it

  Name = "Alice";
  Name = "Bob" //this is ok

  char name[200]; //block of 200 characters
  name = "Jack";
  name = "Jones"; // BAD; cannot reassign to arrays
  strcpy(name, "Jones"); //OKAY
  name[0] = 'A'; //OK
  */

  return 0;
}