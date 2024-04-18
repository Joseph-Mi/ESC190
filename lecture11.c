#include <stdio.h>

/*
Can resize blocks of memory using realloc

char *str = (char *)malloc(100 * sizeof(char));
// want to make more space

str = (char *)realloc(str, 200 * sizeof(char));
*/



int main(){
  char *block = malloc(10000000);
    if (block == NULL){
      printf("Out of memory\n");
      exit(1); // exit terminates the program. the 1 is sent to the operating system
}

}