#include "q5.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

matrix *create_matrix(int i, int j){
    matrix *m1 = malloc(sizeof(matrix));
    if (m1 == NULL) {
        return NULL; // Memory allocation failed
    }
    
    m1->rows = i;
    m1->columns = j;

    m1->data = (int **)malloc(i * sizeof(int *));

    for (int row = 0; row < i; row++){
        m1->data[row] = (int *)malloc(j * sizeof(int));
    }
    return m1;
}

void free_matrix(matrix *m1){
    for (int i = 0; i < m1->rows; i++){
        free(m1->data[i]);
    }
    free(m1->data);
    free(m1);
}

int get_elem(matrix *M, int row, int col){
    if (M == NULL || row < 0 || row > M->rows || col < 0 || col > M->columns){
        return 0;
    }
    return M->data[row][col];
}

void set_elem(matrix *m, int row, int col, int val){
    if (m == NULL || row < 0 || row > m->rows || col < 0 || col > m->columns){
        printf("invalid location");
        return;
    }

    m->data[row][col] = val;
}



