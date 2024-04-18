#if !defined(MYSTR_H)
#ifndef MYSTR_H
#define MYSTR_H

typedef struct mystr
{
  char *str;
  int len;
} mystr;

void create_mystr(mystr *p_s, const char *str, int len);
void cat_mystr(mystr *p_dest, const mystr *p_src);
void destroy_mystr(mystr *p_s);
mystr mystr_substr(mystr *p_s, int i, int j);

#endif
#endif