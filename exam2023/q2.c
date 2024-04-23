#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void replace_ws(char *s){
    const char *old_word = "winter";
    const char *new_word = "summer";
    int len = strlen(s);

    //find how many times winter appears
    // int count = 0;
    // for (int i = 0; i <= (len - 6); i++){
    //     if (strcmp(s + i, old_word, 6) == 0){
    //         count++;
    //     }
    // }

    char *p = s;
    int index = 0;

    for (int i = 0; i <= (len - 6); i++){
        if (strncmp(s + i, old_word, 6) == 0){
            memcpy(s + i, new_word, 6);
        }
    }

}

int main() {
    char s[] = "In the winter, I will rest and enjoy the sun. Winter is great! Wait, actually I mean winter.";
    replace_ws(s);
    printf("%s\n", s);
    return 0;
}