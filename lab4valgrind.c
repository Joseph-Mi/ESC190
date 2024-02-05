#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(){
  /*
  char *p = (char *)malloc(1000);
  printf("Value: %c\n", p[500000]); #segmentation fault
  */

  char filename[] = "a.txt";  // Specify the filename directly
  
  FILE *file = fopen(filename, "r");

  if (file == NULL) {
    printf("Error opening the file.\n");
    return 1; // exit with an error code
  }

  printf("Contents of the file:\n");
  int character;
  while ((character = fgetc(file)) != EOF) {
      printf("%c", character);


      
  }
}