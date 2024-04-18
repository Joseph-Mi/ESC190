#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mystr.h"
//const char *str = "akjd";

void create_mystr(mystr /***/*p_s, const char *str, int len){

  /*
  (*p_s) = (mystr *)malloc(sizeof(mystr));
  (*p_s)->len = len;
  (*p_s)->str = (char *)malloc((len + 1) * sizeof(char));
  */

  //s has to be a pointer as we will change its properties globally
  p_s->len = len; //same as (*p_s).len = len;
  //could sa p_s->str = str, but if str us a const char*, wont know that we're not allowed to modify p_s->str (could crash)
  //also dont know if we need to free p_s->str later
  p_s->str = (char *)malloc((len+1) * (sizeof(char)));

  if (p_s->str == NULL){
    printf("MALLOC FAILED\n");
    exit(1);
  }

  //strcpy(p_s->str, str);  
  memcpy(p_s->str, str, len); //copy to p_s->str from str, copy len bytes
  p_s->str[len] = '\0';
}


void cat_mystr(mystr *p_dest, const mystr *p_src){
  p_dest->str = (char *)realloc(p_dest->str, (p_dest->len + p_src->len + 1) * sizeof(char));
  if (p_dest->str == NULL){
    printf("Reallac failed\n");
    exit(1);
  } 

  p_dest->len += p_src->len;
  strcat(p_dest->str, p_src->str);
}

void destroy_mystr(mystr *p_s){
  free(p_s->str);
  //cant malloc array as they already exist with specific size
  p_s->str = NULL;
  p_s->len = 0;
}
/*
void create_mystr(mystr s, const char *str, int len){
  len = 192894;
  s.len = len;
  //compiles but will not have an effect outside the function
}
*/

mystr mystr_substr(mystr *p_s, int i, int j) {
    mystr newstr;
    create_mystr(&newstr, p_s->str + i, j - i);
    return newstr;
}

int main(){
  mystr *s;
  create_mystr(&s, "EngSci", 6);
}