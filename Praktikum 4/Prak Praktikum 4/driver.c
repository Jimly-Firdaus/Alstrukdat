#include <stdio.h>
#include "matrix.c"
#include "opmatrix.c"


int main () {
    Matrix m;
    createMatrix(3, 3, &m);
    readMatrix(&m, 3, 3);
    printf("\n");
    printf("Avg dari baris 1: %.2f\n", rowMean(m, 0));
    printf("Avg dari baris 2: %.2f\n", rowMean(m, 1));
    printf("Avg dari baris 3: %.2f\n", rowMean(m, 2));
}