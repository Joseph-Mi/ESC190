#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mystr.h"
//#include "mystr.c" // should not include c files // gcc would see the code from mystr.c twice

int  main(){
  mystr s;
  create_mystr(&s, "Engsci", 6);
  //now s.str points to a string "Engsci", s.len is 6
  mystr praxus;
  create_mystr(&praxus, "PRAXIS!", 7);

  cat_mystr(&s, &praxus);
  //printf("%s\n", s.str); // (&s)->str <=> (*(&s)).str

  mystr sub = mystr_substr(&s, 6, 12);
  printf("%s\n", sub.str); // same as (&sub)->str
  //a->b is the same as (*a).b //deref and then take 
  destroy_mystr(&s);
  destroy_mystr(&praxus);
}