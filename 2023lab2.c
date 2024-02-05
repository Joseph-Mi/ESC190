#include <stdio.h>
#include <string.h>

void create_str(int *sz, char **character){
  printf("enter string length:");
  scanf("%d", sz); // scanf goes to pointer sz and changes value WITHIN, so not the pointer itself
  *character = (char *)malloc(sizeof(char)*(*sz));

  for (int i = 0; i < *sz; i ++){
    printf("enter character you want:");
    scanf(" %c", *character + i);
  }
  (*character)[*sz] = '\0';
}
  
  
int main(){
  int siz; 
  char *charac;
  create_str(&siz, &charac);
  printf("%s", charac);
  free(charac);
  return 0;
}