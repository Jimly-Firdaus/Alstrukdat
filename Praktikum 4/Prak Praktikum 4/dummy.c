#include <stdio.h>
#include "math.h"
#define x 4

float determinant(int m[x][x], int n);
// void getCofactor(int m[x][x], int temp[x][x], int permitted_row, int permitted_col, int n);

int main()
{
    int m[4][4] = {
        {1, 2, 5, 7},
        {9, 6, 3, 1},
        {-2, 7, 8, 6},
        {9, 3, 1, 1}
        };
    printf("%.2f", determinant(m, 4));
    return 0;
}
// void getCofactor(int m[x][x], int temp[x][x], int permitted_row, int permitted_col, int n)
// {
//     int i = 0, j = 0, current_row, current_col;
//     for (current_row = 0; current_row < n; current_row++)
//     {
//         for (current_col = 0; current_col < n; current_col++)
//         {
//             if (current_row != permitted_row && current_col != permitted_col)
//             {
//                 temp[i][j++] = m[current_row][current_col];
//                 if (j == n - 1)
//                 {
//                     j = 0;
//                     i++;
//                 }
//             }
//         }
//     }
// }

// int determinant(int m[x][x], int n)
// {
//     int result = 0;
//     //  Base case
//     if (n == 1)
//         return m[0][0];

//     int temp[x][x]; // store cofactors

//     int sign = 1; // sign multiplier

//     for (int permitted_col = 0; permitted_col < n; permitted_col++)
//     {
//         // Getting Cofactor of A[0][f]
//         getCofactor(m, temp, 0, permitted_col, n);
//         result += sign * m[0][permitted_col] * determinant(temp, n - 1);

//         // terms are to be added with alternate sign
//         sign = -sign;
//     }

//     return result;
// }

float determinant(int m[x][x], int n)
{
    float result = 0;
    //  Base case
    if (n == 1)
        return m[0][0];

    int temp[x][x]; // store cofactors

    float sign = 1; // -1 multiplier

    for (int permitted_col = 0; permitted_col < n; permitted_col++)
    {
        // Cofactor of A[permitted_row][permitted_col]
        int i = 0, j = 0, current_row, current_col, permitted_row = 0;
        for (current_row = 0; current_row < n; current_row++)
        {
            for (current_col = 0; current_col < n; current_col++)
            {
                if (current_row != permitted_row && current_col != permitted_col)
                {
                    temp[i][j++] = m[current_row][current_col];
                    if (j == n - 1)
                    {
                        j = 0;
                        i++;
                    }
                }
            }
        }
        result += sign * (float) m[0][permitted_col] * determinant(temp, n - 1);

        // terms are to be added with alternate sign
        sign = -sign;
    }

    return result;
}