#include <stdio.h>
#include "matrix.h"

void main () {
    Matrix m;
    int n;
    scanf("%d", &n);
    createMatrix(n, n, &m);
    readMatrix(&m, n, n);
    RotateMat(&m);
    displayMatrix(m);
}