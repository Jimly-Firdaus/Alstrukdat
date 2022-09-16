// NIM : 13521102
// Nama : Jimly Firdaus
// Tanggal : 16 September 2022
// Topik praktikum : ADT List
// Deskripsi : Merge
// Score : 100/100
#include <stdio.h>
#include "listdin.h"
int main()
{
    ListDin l1, l2, l3;
    CreateListDin(&l1, 200);
    CreateListDin(&l2, 200);
    CreateListDin(&l3, 400);
    readList(&l1);
    NEFF(l3) = NEFF(l1);
    readList(&l2);
    int i, j, ctr = 0;

    for (i = 0; i < listLength(l1); i++)
    {
        ELMT(l3, i) = ELMT(l1, i);
    }

    for (i = 0; i < listLength(l2); i++)
    {
        if (indexOf(l3, ELMT(l2, i)) == IDX_UNDEF)
        {
            insertLast(&l3, ELMT(l2, i));
        } else ctr++;
    }
        NEFF(l3) = NEFF(l1) + NEFF(l2) - ctr;
        sort(&l3, true);
        printf("%d", listLength(l3));
        printf("\n");
        printList(l3);
        printf("\n");
        return 0;
    }