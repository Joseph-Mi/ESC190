#include <string.h>
#include <stdio.h>

typedef struct student1{
char name[200];
char student_number[11];
int year;
} student1;

void print_info(student1 *student){
    printf("name: %s \nstudent number: %s \nyear: %d", student->name, student->student_number, student->year);
}

void create_block1(student1 **p_p_s, int n_students){
    *p_p_s = (student1 *)malloc(n_students * sizeof(student1));
}

void set_name(student1 *stud){

}

int main(){
    student1 allan[] = {"allan", "123456", 2005};
    print_info(allan);
}