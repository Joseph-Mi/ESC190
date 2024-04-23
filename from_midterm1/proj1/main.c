#include <stdio.h>
#include "autocomplete.h"

/*
typedef struct term{
    char term[200]; // assume terms are not longer than 200
    double weight;
} term;
*/

int main()
{
    struct term *terms;
    int nterms = 93827;
    read_in_terms(&terms, &nterms, "cities.txt");

    // for (int i = 0; i < 93827; i++){
    //     printf("%s\n", terms[i]);
    // } 
    
    // int low = lowest_match(terms, nterms, "Tor");
    // int high = highest_match(terms, nterms, "Tor");
    // int res = high - low;

    // for (int i = 82640; i < 82821; i++){
    //     printf("%s\t", terms[i].term);
    //     printf("%d\n", terms[i].weight);
    // }
    
    // printf("low:%d \nhigh: %d \nres:%d", low, high, res);

    struct term *answer;
    int n_answer;
    autocomplete(&answer, &n_answer, terms, nterms, "Tor");

    // for (int i = )

    // for (int i = 0; i < n_answer; i++){
    //     printf("%s\t", answer[i].term);
    //     printf("%f\n", answer[i].weight);
    // }

    //free allocated blocks here -- not required for the project, but good practice
    // free(terms);
    return 0;
}

