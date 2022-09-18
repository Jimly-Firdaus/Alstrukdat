// NIM : 13521102
// Nama : Jimly Firdaus
// Tanggal : 16 September 2022
// Topik praktikum : ADT List
// Deskripsi : Olist
// Score : 100/100
#include <stdio.h>
#include "liststatik.h"
int countX(int x, ListStatik l);
int main()
{
    ListStatik l1;
    CreateListStatik(&l1);
    readList(&l1);
    int X;
    scanf("%d", &X);
    int i, count = 0;
    for (i = 0; i < listLength(l1); i++)
    {
        if (ELMT(l1, i) == X)
            count++;
    }
    printList(l1);
    printf("\n");
    printf("%d\n", count);
    if (count != 0)
    {
        int idx;
        for (i = listLength(l1) - 1; i >= 0; i--)
        {
            if (ELMT(l1, i) == X)
            {
                idx = i;
                break;
            }
        }
        printf("%d\n", idx);
        int max, min;
        extremeValues(l1, &max, &min);
        if (X == max)
            printf("maksimum\n");
        if (X == min)
            printf("minimum\n");
        sortList(&l1, true);
        if (listLength(l1) % 2 != 0)
        {
            if (X == ELMT(l1, (listLength(l1) / 2)))
                printf("median\n");
        }
        else
        {
            if (X == ELMT(l1, (listLength(l1) / 2) - 1))
                printf("median\n");
        }
    }
    else
    {
        printf("%d tidak ada\n", X);
    }

    return 0;
}
