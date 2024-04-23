#include <stdio.h>
#include <string.h>
#include <ctype.h>

void set_even_to_zero(int *block, int size){
    for (int i = 1; i < size; i = i + 2){
        *(block + i) = 0;
    }
    for (int i = 0; i < size; i++){
        printf(" %d", block[i]);
    }
}

/*
void strcat_1(char *dest, char *src){
    int destlen = 0;
    int srclen = 0;

    while(dest[destlen] != NULL){
        destlen++;
    }
    while(src[srclen] != NULL){
        srclen++;
    }

    for (int i = 0; i <srclen; i++){
        dest[destlen + i] = src[i];    
    }
}

void strcat_2(char *dest, char *src){
    int destlen = 0;
    int srclen = 0;

    while(dest[destlen] != NULL){
        destlen++;
    }
    while(src[srclen] != NULL){
        srclen++;
    }

    for (int i = 0; i < srclen; i++){
        *(dest + destlen + i) = *(src + i);
    }
}
*/

int my_strcmp_rec(char *str1, char *str2){
    if (*str1 == '\0' && *str2 == '\0' || str1 == str2 ){
    return 0;
  } else if (*(str1) != *(str2)){
    return *str1 - *str2;
  } else {
      return strcmp(str1+1, str2+1);
  }
}

int binary_search_start(int set[], int left, int right, int mid, int target){
    int res;
    while (left <= right){
        if (set[mid] == target && set[mid - 1] < target){
            return mid;
        }   else if (set[mid] == target && set[mid - 1] == target || set[mid] > target){
            right = mid;
            mid = (left + right)/2;
        }   else if (set[mid] < target){
            left = mid;
            mid = (left + right)/2;
        }
    }
    res = mid;
    return res;
}
int binary_search_end(int set[], int left, int right, int mid, int target){
    int res;
    while (left <= right){
        if (set[mid] == target && set[mid + 1] > target){
            return mid;
        }   else if (set[mid] == target && set[mid + 1] == target || set[mid] < target){
            left = mid;
            mid = (left + right)/2;
        }   else if (set[mid] > target){
            right = mid;
            mid = (left + right)/2;
        }
    }
    res = mid;
    return res;
}

void binary_search_deluxe(int arr[], int target, int size){
    int start, end;

    int left = 0;
    int right = size - 1;
    int mid = (int)(left + right)/2;

    start = binary_search_start(arr, left, right, mid, target);
    end = binary_search_end(arr, left, right, mid, target);
    printf("[%d, %d]", start, end);
}

int my_atoi(char *str){
    int sum = 0;
    while(*str != '\0'){
        if (isdigit(*str)){
            sum = (10*sum) + (*str - '0');
        }
        str++;
    }
    return sum;
}

int main(){
    // int block1[] = {1,2,3,4,5};
    // set_even_to_zero(block1, 5);

    // char str1[100] = "This is ", str2[] = "programiz.com";
    // strcat_2(str1, str2);
    // printf("new str: %s \n", str1);

    // char *str1 = "abcd", *str2 = "abEf";
    // int result;

    // result = my_strcmp_rec(str1, str2);
    // printf("my str compare %d", result);
    // printf("%d", strcmp(str1, str2));
    // int set[] = {1, 2, 3, 10, 10, 10, 12, 12};
    // int size = sizeof(set)/sizeof(set[0]);
    // binary_search_deluxe(set, 10, size);

    char *str = "12545";
    int value = my_atoi(str);
    printf("the value of my string is: %d", value);
}