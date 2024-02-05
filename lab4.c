#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(){
  /*
  char *p = (char *)malloc(1000);
  printf("Value: %c\n", p[500000]); #segmentation fault

  char *p = (char *)calloc(1000);
  printf("%s\n", p); #start printing at address p and keep going while looking for null 
  # if p[2] is not '\0', ..., eventually it will try to access memory it was not supposed to 
  */

  /*FILE *file;
  char line[length];
  double sum = 0.0;

  file = fopen("lab4.txt", "r");
  if (file == NULL){
    printf("Can't open file.\n");
    return 1;
  }

  while(fgets(line, length, file) != NULL){
    char *name = strtok(line, " =\n");
    char *value = strtok(NULL, " =\n");
    if (value != NULL){
      double value = atof
    }
  */

  char line[200];
  int N = 15; //eof
  FILE *fp = fopen("lab3.txt", "r");
  for(int i = 0; i < N; i++){
    fgets(line, sizeof(line), fp); //read in at most sizeof(line) characters //(including ’\0’) into line.
    printf("%s", line);
  }
}

