#include <stdio.h>
#include "matrix.c"

int main()
{
    Matrix m;
    readMatrix(&m, 3, 3);
    printf("\n");
    // Matrix m1, m3;
    // readMatrix(&m1, 3, 3);
    // createMatrix(3, 3 , &m3);
    // printf("\n");
    // printf("%.2f", determinant(m));
    // printf("\n");
    // isIdentity(m) ? printf("Identitas") : printf("Tidak");
    // pTranspose(&m);
    // printf("\n");
    // displayMatrix(m);
    // printf("\n");
    // isMatrixEqual(m, m1) ? printf("Iya") : printf("Tidak");
    // m3 = transpose(m);
    // displayMatrix(m3);

    float fm[ROW_CAP][ROW_CAP];
    for (int i = 0; i < ROW_EFF(m); i++)
    {
        for (int j = 0; j < ROW_EFF(m); j++)
        {
            fm[i][j] = ELMT(m, i, j);
        }
    }

    float factor;
    for (int i = 0; i < ROW_EFF(m); i++)
    {
        for (int j = i + 1; j < ROW_EFF(m); j++)
        {
            float num = fm[j][i];
            float denum = fm[i][i];
            if (denum == 0){
                factor = 1;
            } else {
            factor = num / denum;
            }
            for (int k = 0; k < COL_EFF(m); k++)
            {
                fm[j][k] -= fm[i][k] * factor;
            }
        }
    }
    for (int i = 0; i < ROW_EFF(m); i++)
    {
        for (int j = 0; j < ROW_EFF(m); j++)
        {
            printf("%.2f\t", fm[i][j]);
        }
        printf("\n");
    }
    return 0;
}
