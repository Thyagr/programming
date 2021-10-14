
#include <stdio.h>
#include <stdlib.h>

void print_matrix(int** mat, int rows, int cols)
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
            printf("%d ", mat[r][c]);
        printf("\n");
    }
}

void print_transpose(int** mat, int rows, int cols)
{
    int mat2[cols][rows];
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
            mat2[c][r] = mat[r][c];
    }
    
    print_matrix(mat2, cols, rows);
}

void print_row(int** mat, int row, int cols)
{
    printf("row: %d\n", row);
    for (int c = 0; c < cols; c++)
        printf("%d ", mat[row][c]);
    printf("\n");
}

void print_col(int** mat, int rows, int col)
{
    printf("col: %d\n", col);
    for (int r = 0; r < rows; r++)
        printf("%d\n", mat[r][col]);
}

int main()
{
    
    int* mat[2];
    
    int arr1[] = {1, 2, 3};
    int arr2[] = {3, 4, 5};
    mat[0] = arr1;
    mat[1] = arr2;
    
    print_matrix(mat, 2, 3);
    print_row(mat, 1, 2);
    print_col(mat, 2, 1);
    print_transpose(mat, 2, 3);

    return 0;
}
