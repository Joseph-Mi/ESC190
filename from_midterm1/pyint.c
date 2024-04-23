#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pyint
{
  int *buffer;
  int length;
} pyint;

void create_pyint(pyint **p, int length){
  (*p) = (pyint *)malloc(sizeof(pyint));
  (*p)->buffer = (int *)malloc(length * sizeof(int));

  (*p)->length = length;
  int i;
  for (i = 0; i < length; i++){
    (*p)->buffer[i] = 0;
  }
}

void destroy_pyint(pyint *p){
  free(p->buffer);
  free(p);
}


void set_pyint(pyint *p, int value){
  int i = 0;

  //value :190
  //buffer: 0 9 1

  while(value > 0){
    p->buffer[i] = value % 10;
    value = value /10;
    i++;
  }
}

void plusplus(pyint *n1){
    int i = 0;
    n1->buffer[i]++;
    while (n1->buffer[i] >= 10){
        
        if (i >= n1->length - 1){
            n1->buffer = realloc(n1->buffer, sizeof(int) * (n1->length + 1));
            n1->length;
            n1->buffer[i+1] = 0;
            n1->length++;
            // printf("size:%d", n1->length);
        }
        n1->buffer[i] = n1->buffer[i] % 10;
        n1->buffer[i+1]++;
        i++;
        // printf("%d", n1->buffer[i]);
    }
}

void add(pyint *n1, pyint *n2, pyint **sum){
  int len1 = n1->length;
  int len2 = n2->length;
  int sum_len = 0;
  int val1 = 0;
  int val2 = 0;
  int sum_val = 0;

  //O(n)
  for (int i = len1 - 1; i >= 0; i--){
    val1 = val1*10 + n1->buffer[i];
  }
  printf("\n%d", val1);
  for (int i = len2 - 1; i >= 0; i--){
    val2 = val2*10 + n2->buffer[i];
  }
  printf("\n%d", val2);
  sum_val = val1 + val2;

  while (sum_val > 0){
    sum_val = sum_val/10;
    sum_len++;
  }
  sum_val = val1 + val2;
  printf("\n%d",sum_len);
  printf("\n%d",sum_val);

  create_pyint(sum, sum_len);
  set_pyint(*sum, sum_val);
}

int main(){
    pyint *integer;
    int length = 3;
    int value = 999;
    create_pyint(&integer, length);
    set_pyint(integer, value);
    for (int i = 0; i < (integer)->length; i++){
        printf("%d", (integer)->buffer[i]);
    }
    // plusplus(integer);
    // printf("%d", integer->length);
    // for (int i = 0; i < (integer)->length; i++){
    //     printf("%d", (integer)->buffer[i]);
    // }
    pyint *int2;
    int len2 = 4;
    int val2 = 2103;
    create_pyint(&int2, len2);
    set_pyint(int2, val2);
    for (int i = 0; i < (int2)->length; i++){
        printf("%d", (int2)->buffer[i]);
    }

    pyint *sum;
    add(integer, int2, &sum);
    printf("\nhi");
    for (int i = 0; i < (sum)->length; i++){
        printf("%d", (sum)->buffer[i]);
    }
}