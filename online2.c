#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 void change_int(int *p_int)
{
  *p_int = 88;
}

// Solution for Q_10
void change_int2(int **p_p_int)
{
  **p_p_int = 46;
}
// Solution for Q_11
void change_int_ptr(int **p){
  *p = (int *)malloc(sizeof(int));
}

// Solution for Q_16
void change_arr(int *arr){
  *(arr+2) = 8;
}

// Solution for Q_21
typedef struct student{
  char name[500];
  int age;
  char school[2000];
} student;

// Solution for Q_27
void change_name(student *s){
  strcpy(s->name, "Jenny");
}

// Solution for Q_28
void change_age(student *s){
  s->age = 20;
}

int main(){
  // Solution for Q_1
  int a = 42;

  // Solution for Q_2
  int *p_a = &a;

  // Solution for Q_3
  *p_a = 43;

  // Solution for Q_4
  int b = 90;
  p_a = &b;
  // Solution for Q_6
  change_int(&a);
  
  // Solution for Q_7
  change_int(p_a);

  // Solution for Q_8
  int **p_p_a;

  // Solution for Q_9
  p_p_a = &p_a; // Fixed assignment

  // Solution for Q_12
  change_ppint(&p_a);
  change_ppint(p_p_a);

  // Solution for Q_13
  change_int_ptr(&p_a);

  // Solution for Q_14
  change_int_ptr(p_p_a);

  // Solution for Q_15
  int arr[] = {5,6,7};

  // Solution for Q_17
  change_arr(arr);

  // Solution for Q_18
  int *p_block = (int *)malloc(sizeof(int) * 3); // Added missing cast
  change_arr(p_block); 

  // Solution for Q_19
  change_int(p_block);

  //Solution for Q_20
  change_int_ptr(&p_block);

  // Solution for Q_21
  student s = {"Allan", 18, "University of Toronto"};

  // Solution for Q_22
  strcpy(s.name, "Jennifer");

  // Solution for Q_23
  s.age = 21;

  // Solution for Q_24
  student *p_s = &s;

  // Solution for Q_25
  strcpy(p_s->name, "Jenny");

  // Solution for Q_26
  p_s->age = 20;

  // Solution for Q_29
  change_name(p_s);

  // Solution for Q_30
  change_age(&s);

  // Solution for Q_31
  student arr[5];

  // Solution for Q_32
  change_name(&(arr[2])); // Pass address of arr[2]
  change_age(&(arr[2]));  // Pass address of arr[2]
}