//function one is changes value of a locally
//function two goes to the reference (address) of a, defererences it, then changes the value
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student1.h"


typedef struct student2{
char *name;
char *student_number;
int year;
} student2;

/*void student_info(student1 my_student){
  printf("Enter Name:");
  scanf("%c", my_student.name);
  printf("Enter Student Number:");
  scanf("%c", my_student.student_number);
  printf("Enter Year:");
  scanf("%d", my_student.year);

  printf("Name: %c", my_student.name);
  printf("Student Number: %c", my_student.student_number);
  printf("Year: %d", my_student.year);
}*/

void student_information(student1 my_student){
  printf("Name: %s", my_student.name);
  printf("Student Number: %s", my_student.student_number);
  printf("Year: %d", my_student.year);
}

void create_block1(student1 **p_p_s, int n_students){
  (*p_p_s) = (student1 *)malloc((n_students) * sizeof(student1));

  //printf("%zu", sizeof(**p_p_s));
}

void set_default_name(student1 *p_s) {
    sprintf(p_s->name, "Default Student");
    p_s->year = 0;
}
void set_default_name_NOTwrong(student1 *s){
  strcpy(s->name, "Default Name");
}

void wrong(student1 s){
  sprintf(s.name, "Default");
}

void create_block2(student2 **p_p_s, int num_students){
  *p_p_s = (student2 *)malloc((num_students) * sizeof(student2));
  for (int i = 0; i < num_students; i ++){
    (*p_p_s)[i].name = NULL; //has value of 0 same thing!
    (*p_p_s)[i].student_number = NULL;
  }
}

void set_name(student1 *student, char *name){
  strncpy(student->name, name, 199);
  student->name[199] = '\0';
}

void set_name2(student2 *student, char *name){
  student->name = (char*) malloc((strlen(name) + 1) * sizeof(char));
  strncpy(student->name, name, sizeof(student->name) - 1);
  student->name[sizeof(student->name) - 1] = '\0';
}

void destroy_block1(student1 *p_p_s){
  free(p_p_s);
}

void destroy_block2(student2 **student){
  // free(student[2]->name);
  free(*student);
}

// cd labs to enter labs directory

void read_file(const char *filename){
  char line[200];
  int N = 15; //eof
  FILE *fp = fopen(filename, "r");
  for(int i = 0; i < N; i++){
    fgets(line, sizeof(line), fp); //read in at most sizeof(line) characters
//(including ’\0’) into line.
    printf("%s", line);
  }
  fclose(fp);
}

int read_average(const char *filename){
  char line[200];
  int count = 0;
  double sum = 0.0;

  FILE *fav = fopen(filename, "r");
  while(fgets(line, sizeof(line), fav)) {
    double num;
    num = (int) atoi(line);
    sum = sum + num;
    count ++;
  }
  return (sum)/(count); 
  fclose(fav);
}

int main(){
  /*student1 John;
  //set_default_name(&John);
  printf("name is now: %s", John.name);

  //set_default_name_wrong(John);
  printf("name: %s", John.name);

  student1 *p_p_class;
  char *name = "John";
  int n = 5;
  
  create_block1(&p_p_class, n);
  set_name(p_p_class, name);
  set_default_name(p_p_class);
  printf("%s", p_p_class->name);
  printf("%d\n", p_p_class->year);
  destroy_block1(p_p_class);*/

  student2 *engsciclass;
  char *name =  "allan";

  create_block2(&engsciclass, 5);
  printf("%s\n", engsciclass[2].name);
  set_name2(&(engsciclass[2]), name);
  printf("%s\n", engsciclass[2].name);
  destroy_block2(&engsciclass);
  printf("no more existence: %s", engsciclass->name);
  
  read_file("lab3.txt");

  int avg = read_average("average.txt");
  printf("average is: %d", avg);
  return 0;
}

