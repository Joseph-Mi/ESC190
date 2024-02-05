#include <stdio.h>
// #2

void change_a(int *p_a){
  *p_a = 10; 
}

// #3
char change_array(char arr[], int size){
  if (size > 0)
  {
    arr[0] = 'x';
  }
}

// #4
int insertion_sort(int arr[], int n){
  for (int i = 1; i < n; i++)
  {
    int j = i - 1;
    int key = arr[i];
    while (arr[j] > key)
    {
      arr[j+1] = arr[j];
      arr[j] = key;
      j--;
    }
    arr[j+1] = key;
  }
}

// #5
int str_len(char array[]) {
    int length = 0, i = 0;
    while (array[i] != '\0') {
        length++;
        i++;
    }
    return length;
}

// #6
void seq_replace(int *arr1, unsigned long arr1_sz, int *arr2, unsigned long arr2_sz){
  
}

int findStringLength(const char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int main(){
  int a = 5;
  printf("%d\n", a);

  int *p_a = &a; 
  printf("%d\n", *p_a);
  change_a(p_a); 
  printf("%d\n", *p_a);
  printf("%d\n", p_a);
  printf("%d\n", a);

  char ar1[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};

  for (int i = 0; i < sizeof(ar1) / sizeof(ar1[0]); i++) 
  {
    printf("%c ", ar1[i]);
  }

  change_array(ar1, 9);
  
  for (int i = 0; i < sizeof(ar1) / sizeof(ar1[0]); i++) 
  {
    printf("%c ", ar1[i]);
  }

  int n=0;
  int ar2[] = {1,5,7,2,9,4,3};
  for (int i = 0; i < sizeof(ar2) / sizeof(ar2[0]); i++) 
  {
    printf("%d ", ar2[i]);
    n++;
  }

  insertion_sort(ar2, n);
  printf("\n");

  for (int i = 0; i < sizeof(ar2) / sizeof(ar2[0]); i++) 
  {
    printf("%d\n", ar2[i]);
  }

  const char str[] = "helloo, 1fwdwq";
  int *p_str = &str;
  printf("%s\n", str);
  printf("%d\n", p_str);

  printf("%d\n", str_len(str));
}






