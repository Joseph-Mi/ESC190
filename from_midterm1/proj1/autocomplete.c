#include "autocomplete.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_terms(const void *a, const void *b) {
  const term *term_a = (const term *)a;
  const term *term_b = (const term *)b;
  return strcmp(term_a->term, term_b->term);
}

int compare_values(const void *a, const void *b) {
  const term *val1 = (term *)a;
  const term *val2 = (term *)b;

  if (val1->weight > val2->weight) {
    return -1;
  } else if (val1->weight < val2->weight) {
    return 1;
  } else {
    return 0;
  }
}

void read_in_terms(term **terms, int *pnterms, char *filename) {
  // initialize file opening
  char line[500];
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening %s file\n", filename);
    exit(0);
  }

  // read first line to obtain length
  *pnterms = atoi(fgets(line, 500, file));

  // malloc space for lines
  *terms = (term *)malloc(sizeof(term) * (*pnterms));
  if (*terms == NULL) {
    printf("malloc error");
    exit(0);
  }

  // extract city names
  for (int i = 0; i < *pnterms; i++) {
    char city[200];
    int num;

    if (fgets(line, 200, file) == NULL) {
      printf("error reading term %d\n", i);
      exit(0);
    }

    sscanf(line, "%d %199[^\n]", &num, city);
    strncpy((*terms)[i].term, city, 200);
    (*terms)[i].term[strlen(city) + 1] = '\0';
    (*terms)[i].weight = num;
    // printf("%lf\t %s\n", (*terms)[i].weight, (*terms)[i].term);
  }

  // sort in lexicographic
  qsort(*terms, *pnterms, sizeof(term), compare_terms);
  fclose(file);
}

int lowest_match(term *terms, int nterms, char *substr) {
  int low = 0;
  int high = nterms - 1;
  int size = strlen(substr);

  while (high >= low) {
    int i = low + (high - low) / 2;

    if ((strncmp(substr, terms[i].term, size) == 0) && (strncmp(substr, terms[i - 1].term, size) > 0)) {
      return i;
    } else if (strncmp(substr, terms[i].term, size) <= 0) {
      high = i - 1;
    } else {
      low = i + 1;
    }
  }
  printf("Substring not found\n");
  exit(0);
}

int highest_match(term *terms, int nterms, char *substr) {
  int low = 0;
  int high = nterms - 1;
  int size = strlen(substr);

  while (high >= low) {
    int i = low + (high - low) / 2;
    
    if ((strncmp(substr, terms[i].term, size) == 0) && (strncmp(substr, terms[i + 1].term, size) < 0)) {
      return i;
    } else if (strncmp(substr, terms[i].term, size) >= 0) {
      low = i + 1;
    } else {
      high = i - 1;
    }
    printf("%d\t", i);
  }
  printf("Substring not found\n");
  exit(0);
}

void autocomplete(term **answer, int *n_answer, term *terms, int nterms,
                  char *substr) {
  // use your functions to compute number of cities that match query string
  int low = lowest_match(terms, nterms, substr);
  int high = highest_match(terms, nterms, substr);
  *n_answer = high - low + 1;

  // malloc space for answers
  *answer = (term *)malloc(sizeof(term) * (*n_answer));

  void *temp = *answer;

  // put .terms that have matched into answers
  for (int i = low; i <= high; i++) {
    (*answer)[i - low].weight = terms[i].weight;
    strcpy((*answer)[i - low].term, terms[i].term);
    // printf("%s\t %lf\n", (*answer)[i-low].term, terms[i].weight);
  }

  *answer = temp;

  // sort by weight this time instead of by term value
  qsort(*answer, *n_answer, sizeof(term), compare_values);
}