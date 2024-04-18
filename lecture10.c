/*
"Mike"  "Bos"   "Alice"
3.95     n      n

1042     2024   3024
'M'
'I'
'K'
'E'
*/
#include <stdio.h>

//option one: store everything inside struct
//prespecify length of name could result to spaces unused 
typedef struct student1{
  char name[50]; 
  double gpa;
} student1;

//option 2: store a pointer to name inside the struct
//student2 takes up less space than student1 because storing char * takes up less space than storing char[50]
typedef struct student2{
  char *name;
  double gpa;
}student2;

int main(){
  //array student1
  student1 s1[150];//150 cells store the info about the student in the cell

  //malloced block of student1s
  student1 *s1_block = (student1 *)malloc(150 * sizeof(student1));
  //unlike s1, can return s1_block because the addy of s1_block is valud until we free it
  
  student2 s2[150];//150 calls, store the info of the student in the cell
  //cannot say right now printf("%s",s2[0].name)// s2[0].name is not valid address
  //can only say printf("%f", s2[0].gpa as gpa has some value and will be printed)
  //printf("%ld", s2[0].name) will print some arbitrary value

  s2[0].name = "John"; //fine, but cant modify s2[0].name anymore, such as into 'j'
  //or
  s2[1].name = (char *)malloc(50 * sizeof(char));
  strcpy(s2[0].name, "John"); //fine 
  //same as:
  //s2[0].name[0] = 'J';
  //s2[0].name[1] = 'o';
  //s2[0].name[2] = 'h';
  //s2[0].name[3] = 'n';

  //malloc a block of pointers to student2s
  student2 **p_s2_block = (student2 **)malloc(150* sizeof(student2 *));
                          // objects that are of type student2 *
  
  // student2 s2;
  // s2.gpa =
  
  //student2 *p_s2 = &s2;
  // p_s2->gpa = 4.0; // (*p_s2).gpa = 4.0

  int i;
  for(i = 0; i <150; i++){
    p_s2_block[i] = (student2 *)malloc(sizeof(student2));
    p_s2_block[i]->gpa = 4.0;

    p_s2_block[i]->name = (char *)malloc(50 * sizeof(char));
    strcpy(p_s2_block, "John");
  }
  return 0;
}