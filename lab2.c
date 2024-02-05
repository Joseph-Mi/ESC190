#include <stdio.h>
#include <ctype.h>
#include <string.h>

void f(int *p_int, char **s){
  scanf(" %d", p_int);
  *s = (char *)malloc((*p_int + 1) * sizeof(char));
  for (int i = 0; i < *p_int; i++){
    scanf(" %c", &(*s)[i]);
    printf("%d\n", i);
  }
  (*s)[*p_int] = '\0';
}

char *strcat1(char *destination, const char *source){
//use pointer arithmetic
  char *str; 
  str = (char *)malloc((strlen(destination) + strlen(source) + 1) * sizeof(char));

  for (int i = 0; i < (strlen(destination) + strlen(source)); i++){
    if (i < strlen(destination)){
      str[i] = *(destination + i);
    } else {
      str[i] = *(source + i - strlen(source) - 1); //pointer arithmetic 
    }
  }
  str[strlen(destination) + strlen(source)] = '\0';
  return str;
}

char *strcat2(char *destination, const char *source){
//use the index i to access elements of strings
  char *str; 
  str = (char *)malloc((strlen(destination) + strlen(source) + 1) * sizeof(char));
  
  for (int i = 0; i < (strlen(destination) + strlen(source)); i++){
    if (i < strlen(destination)){
      str[i] = destination[i];
    } else {
      str[i] = source[i - strlen(destination)]; //pointer arithmetic 
    }
  }
  str[strlen(destination) + strlen(source)] = '\0';
  return str;
}

int strcmp(const char* str1, const char* str2){
  if (*str1 == '\0' && *str2 == '\0' || str1 == str2 ){
    return 0;
  } else if (*(str1) != *(str2)){
    return *str1 - *str2;
  } else {
      return strcmp(str1+1, str2+1);
  }
}

/*
binary_search_deluxe(int *arr, int a){
  int *ind; 
  for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
    
    } 
}
*/

int my_atoi(char *str){
  int sum = 0;
 while (*str != '\0'){
  if (isdigit(*str)){
    sum =  sum*10 + *str - '0';
  }
  str++;
 }
 return sum;
}


int main(){
  /* int a;
  char *letter;
  f(&a, &letter);
  printf("%s", letter);
  free(letter);

  char *word1 = "Hello ";
  char *word2 = "World";

  printf("%s", strcat2(word1, word2));

  char *s1 = "abc";
  char *s2 = "abb";
  printf("%d", strcmp(s1, s2));
  */
 char *str = "666";
 int x = my_atoi(str);
 printf("%d", x);

  return 0;
}

