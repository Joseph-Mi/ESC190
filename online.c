#include <stdio.h>

int linear_search(int *a, int sz, int elem){
  for (int i = 0; i < sz; i++){
    if (*(a + i) == elem){
      return i;
    }
  }
  return -1;
}

void reverse_arr(int *arr, int sz){
  int temp;
  //int *rev_array = (int *)malloc(sz * sizeof(int));
  for (int i = 0; i < sz/2; i++){
    temp = *(arr + i);
    *(arr + i) = *(arr + sz - 1 - i);
    *(arr + sz -1 - i) = temp;
  }
}

int main(){
  /////q1
  //printf("Hello World");

  /////q2
  int arr[] = {1,2,3,4,5,6};
  printf("%d", linear_search(arr, 6, 4));

  int array1[] = {1,2,3,4,5};
  printf("old array: %d %d %d %d %d\n", array1[0], array1[1], array1[2], array1[3], array1[4]);

  reverse_arr(array1, 5);
  printf("old array: %d %d %d %d %d\n", array1[0], array1[1], array1[2], array1[3], array1[4]);

  return 0;
}