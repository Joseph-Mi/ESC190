#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//recursive str_cat()

char *strcat_r(char *s1, char *s2){
    if (strlen(s2) == '\0'){
        return s1;
    } else{
        if (s1[0] != '\0'){
            return strcat_r(s1 + 1, s2);
        } else{
            s1[0] = s2[0];
            s1[1] = '\0';
            return strcat_r(s1 + 1, s2 + 1);
        }
    }
}
//recursive strcmp()
int my_strcmp(char *s1, char *s2){
    if (s1[0] == '\0' && s2[0] == '\0'){
        return 0;
    } else{
        if (s1[0] == s2[0]){
            return my_strcmp(s1 + 1, s2 + 1);
        } else if (s1[0] < s2[0]){
            return -1;
        } else if (s1[0] > s2[0]){
            return +1;
        }
        
    }
}

//linkedlist

int main(){
    char one[100] = "12345";
    char *two = "678";
    strcat_r(one, two);

    printf("%s", one);

    char *s1 = "abcd";
    char *s2 = "abcf";
    printf("%d", my_strcmp(s1, s2));
}
