#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *dec2bin(const char *decimal){
    int num = atoi(decimal);
    int temp = num;

    int rem = 0;
    int bin = 0;
    int digits = 0;
    while (num != 0){
        rem = num % 2;
        num = num / 2;
        bin = 10 * bin + rem;
        digits++;
    }

    printf("%d", bin);
    
    char *binary = (char *)malloc((digits+1) * sizeof(char));
    for (int i = 0; i < digits; i++){
        binary[i] = (bin%10) + '0';
        bin = bin / 10;
    }
    binary[digits] = '\0';

    return binary;
}

int main() {
    const char *decimal = "13"; // Example decimal number as a string
    char *binary = dec2bin(decimal);
    if (binary != NULL) {
        printf("Binary representation of %s: %s\n", decimal, binary);
        free(binary); // Free the memory allocated for binary
    }
    return 0;
}