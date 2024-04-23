#include <stdio.h>

int main(){
    int arr[] = {1, 2, 3, 4}; // defining an array
    int size = sizeof(arr) / sizeof(int);
    printf("size is: %d", size);
    return 0;
}