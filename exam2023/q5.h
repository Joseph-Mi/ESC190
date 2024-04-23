#if !defined(Q5_H)
#define Q5_H

typedef struct matrix{
    int rows;
    int columns;
    int **data;
} matrix;

matrix *create_matrix(int i, int j);
void free_matrix(matrix *m1);
int get_elem(matrix *M, int row, int col);
void set_elem(matrix *m1, int row, int col, int val);

#endif