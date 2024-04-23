#include <stdio.h>
#include "q5.h"

int main(){
    matrix *m1 = create_matrix(2,2);
    matrix *m2 = create_matrix(2,2);

    matrix *sum = create_matrix(m1->rows, m1->columns);

    m1->data[0][0] = 1;
    m1->data[1][0] = 1;
    m1->data[0][1] = 1;
    m1->data[1][1] = 1;

    m2->data[0][0] = 2;
    m2->data[1][0] = 1;
    m2->data[0][1] = 2;
    m2->data[1][1] = 4;

    if (m1->rows != m2->rows || m1->columns != m2->columns){
        printf("sum of matrix cannot be computed");
        return 0;
    }

    for (int i = 0; i < m1->rows; i++){
        for (int j = 0; j < m1->columns; j++){
            int one = get_elem(m1, i, j);
            int two = get_elem(m2, i, j);
            int s = one + two;

            set_elem(sum, i, j, s);
        }
    }

    for (int i = 0; i < m1->rows; i++){
        printf("\n");
        for (int j = 0; j < m1->columns; j++){
            printf("%d", sum->data[i][j]);
        }
    }
}