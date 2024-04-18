#include <string.h>
#include <stdio.h>
#include <stdlib.h>

double fact(int n){
    if (n == 0){
        return 1;
    } else{
        return (n * fact(n-1));
    }
}

int main(){
    int n = 5;
    printf("%lf", fact(n));
}