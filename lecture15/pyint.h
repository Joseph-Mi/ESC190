if !defined(PYINT_H)
#define PYINT_H

typedef struct pyint
{
  int *buffer;
  int length;
} pyint;

void create_pyint(pyint *p, int length);
void descroy_pyint(pyint *p);
void set_pyint(pytin *p, int value);
void print_pyint(pyint *p);
void ad_pyint(pyint *p, int value);

#endif
