#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double my_atof(char *str){
    //implement turning char(int) to actual int
    int sum = 0;
    int tens = 0;
    int count = 0;

    for (int i = 0; i < strlen(str); i++){
        if (str[i] == '.'){
            tens = count;
            continue;
        }
        count++;
        sum = (sum*10) + (str[i] - '0');
    }
    return sum/(pow(10, tens));
}

int my_strcmp(char *str1, char *str2, int num ){
    if (strlen(str1) < num || strlen(str2) < num){
        printf("error");
        exit(-1);
    }

    if (num == 1){
        return *str1 - *str2;
    }   else{
        if (*str1 != *str2){
            return *str1 - *str2; 
        }   else{
            return my_strcmp(str1 + 1, str2 + 1, num - 1);
        }
    }
    
}



int main(){
    // char *num = "123.56";
    // double res = my_atof(num);
    // printf("%f", res);

    char *one = "aaaaa";
    char *two = "aaaaf";
    int res = my_strcmp(one, two, 3);
    printf("result is: %d", res);
}