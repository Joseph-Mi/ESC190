#include <stdio.h>
#include "q5.h"

int main() {
    // Create two matrices of the same size
    matrix *m1 = create_matrix(2, 2);
    matrix *m2 = create_matrix(2, 2);

    if (m1 == NULL || m2 == NULL) {
        printf("Failed to create matrices\n");
        return 1; // Exit with failure code
    }

    // Populate matrices with sample data
    m1->data[0][0] = 1;
    m1->data[0][1] = 2;
    m1->data[1][0] = 3;
    m1->data[1][1] = 4;

    m2->data[0][0] = 5;
    m2->data[0][1] = 6;
    m2->data[1][0] = 7;
    m2->data[1][1] = 8;

    // Create a matrix to store the sum
    matrix *sum = create_matrix(m1->rows, m1->columns);

    if (sum == NULL) {
        printf("Failed to create sum matrix\n");
        // Clean up previously allocated matrices
        free_matrix(m1);
        free_matrix(m2);
        return 1; // Exit with failure code
    }

    // Perform matrix addition
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            int one = get_elem(m1, i, j);
            int two = get_elem(m2, i, j);
            int s = one + two;

            set_elem(sum, i, j, s);
        }
    }

    // Print the matrices
    printf("Matrix 1:\n");
    for (int i = 0; i < m1->rows; i++) {
        for (int j = 0; j < m1->columns; j++) {
            printf("%d ", get_elem(m1, i, j));
        }
        printf("\n");
    }

    printf("\nMatrix 2:\n");
    for (int i = 0; i < m2->rows; i++) {
        for (int j = 0; j < m2->columns; j++) {
            printf("%d ", get_elem(m2, i, j));
        }
        printf("\n");
    }

    printf("\nSum Matrix:\n");
    for (int i = 0; i < sum->rows; i++) {
        for (int j = 0; j < sum->columns; j++) {
            printf("%d ", get_elem(sum, i, j));
        }
        printf("\n");
    }

    // Clean up dynamically allocated memory
    free_matrix(m1);
    free_matrix(m2);
    free_matrix(sum);

    return 0; // Exit with success code
}
