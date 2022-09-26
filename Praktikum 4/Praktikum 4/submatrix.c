// NIM : 13521102
// Nama : Jimly Firdaus
// Tanggal : 24 September 2022
// Topik praktikum : ADT Matrix
// Deskripsi : SubMatrix

#include <stdio.h>
#include "matrix.h"

ElType sum0subMatrix(Matrix m, int row, int col, int M)
{
    ElType sum = 0;
    for (int i = row; i < row + M; i++)
    {
        for (int j = col; j < col + M; j++)
        {
            if (ELMT(m, i, j) == 0)
            {
                sum++;
            }
        }
    }
    return sum;
}

int main()
{
    Matrix m;
    int N, M;
    scanf("%d %d", &N, &M);
    readMatrix(&m, N, N);

    int maxIdxSubMatrix = N - M + 1;
    
    int best_position = 1;
    int min = sum0subMatrix(m, 0, 0, M);
    for (int i = 0; i < ROW_EFF(m) - 1; i++)
    {
        for (int j = 0; j < COL_EFF(m) - 1; j++)
        {
            if (min > sum0subMatrix(m, i, j, M))
            {
                min = sum0subMatrix(m, i, j, M);
                best_position = maxIdxSubMatrix*i + j + 1;
            }
                   
        }

    }
    printf("%d\n", best_position);
    return 0;
}
