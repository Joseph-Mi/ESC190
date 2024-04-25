#include <string.h>
#include <stdio.h>
#include <stdlib.h>

double fact(int n){
    if (n == 0){
        return 1;
    } else{
        return (n * fact(n-1));
    }
} // Runtime complexity of this function: O(n)


int main(){
    int n = 1;
    printf("%lf", fact(n));
}