#include "stdio.h"
#include "string.h"

int main(){
    int arr = {4,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    g(arr, n);
    return 0;
}