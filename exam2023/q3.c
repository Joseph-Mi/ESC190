#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int comp_arrays(int *arr1, int *arr2, int len1, int len2){
    if (len1 != len2){
        return 0;
    }

    if (len1 == len2 && len1 == 0){
        return 1;
    } 
    if (arr1[0] == arr2[0]){
        return comp_arrays(arr1 + 1, arr2 + 1, len1-1, len2-1);
    } else{
        return 0;
    }
}

int main(){
    int arr1[] = {7, 8, 9};
    int arr2[] = {7, 9, 9};
    int arr3[] = {7, 8};

    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    int len2 = sizeof(arr2) / sizeof(arr2[0]);
    int len3 = sizeof(arr3) / sizeof(arr3[0]);
    
    int val = comp_arrays(arr1, arr3, len3, len3);
    printf("%d", val);
}