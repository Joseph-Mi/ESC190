#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct mystr
{
  char *str;
  int len;
} mystr;

void create_mystr(mystr *p_s, const char *str, int len){
    (p_s)->len = len;
    (p_s)->str = (char *)malloc(sizeof(char) * (len+1));

    memcpy((p_s)->str, str, len);
    (p_s)->str[len] = '\0';
}

void destroy(mystr *p_s){
    free(p_s->str);
    free(p_s);
}

void cat_mystr(mystr *p_dest, const mystr *p_src){
    // if (p_src->str[0] == '/0'){
    //     return p_dest;
    // }
    p_dest->str = realloc(p_dest->str, (sizeof(char)) * (p_dest->len + p_src->len + 1));
    p_dest->len = p_dest->len + p_src->len;

    strcat(p_dest->str, p_src->str);
    p_dest->str[p_dest->len] = '\0';
}

mystr mystr_substr(mystr *p_s, int i, int j){
    mystr new;
    create_mystr(&new, p_s->str+1, j-i+1);
    return new;
}

int main(){
    mystr *fname = malloc(sizeof(mystr)); // Allocate memory for mystr structure
    int len = 4;

    mystr *lname = malloc(sizeof(mystr));

    create_mystr(fname, "jack", len);
    create_mystr(lname, "sparrow", 7);

    cat_mystr(fname, lname);

    printf("%s\n", fname->str);

    mystr new = mystr_substr(fname, 1, 3);
    printf("%s\n", new.str);

    
}