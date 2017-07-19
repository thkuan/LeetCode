#include <stdio.h>
#include <stdlib.h>

void swap(int *e1, int *e2) {
    int tmp = *e1;
    *e1 = *e2;
    *e2 = tmp;

    return ;
}

void rotate(int **matrix, int matrix_row_size, int matrix_col_size) {
    int i = 0, j = 0;
    /* Target: rotate 90 degree clockwise */

    /* Switch elements based on antidiagonal */
    for (i = 0; i < matrix_row_size - 1; i++) {
        for (j = 0; j < matrix_col_size - 1 - i; j++) {
            swap(&matrix[i][j], &matrix[(matrix_row_size-1)-j][(matrix_col_size-1)-i]);
        }
    }

    /* Switch elements according to horizontal line in the middle */
    for (i = 0; i < matrix_row_size/2; i++) {
        for (j = 0; j < matrix_col_size; j++) {
            swap(&matrix[i][j], &matrix[(matrix_row_size-1)-i][j]);
        }
    }

    return ;
}

void print_matrix(int mat[][4], int row_size, int col_size) {
    for (int i = 0; i < row_size; i++) {
        printf("[");
        for (int j = 0; j < col_size; j++) {
            printf("%2d", mat[i][j]);
            if (j != col_size - 1) {
                printf(", ");
            }
        }
        printf("],\n");
    }
    printf("\n");

    return ;
}

int main()
{
    int **ptr_matrix;
    int *ptr_arr[4];
    int mat[4][4] = {
        { 1,  2,  3,  4}, 
        { 5,  6,  7,  8},
        { 9, 10, 11, 12},
        {13, 14, 15, 16}};

    for (int i = 0; i < 4; i++) {
        ptr_arr[i] = &mat[i][0];
    }
    ptr_matrix = &ptr_arr[0];

    print_matrix(mat, 4, 4);
    rotate(ptr_matrix, 4, 4);
    print_matrix(mat, 4, 4);

    return 0;
}
