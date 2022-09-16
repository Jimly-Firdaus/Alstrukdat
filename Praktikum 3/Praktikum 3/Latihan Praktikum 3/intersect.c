// NIM : 13521102
// Nama : Jimly Firdaus
// Tanggal : 16 September 2022
// Topik praktikum : ADT List
// Deskripsi : Intersect
// Score : 100/100
#include <stdio.h>
#include "liststatik.h"

int main (){
    ListStatik l1 , l2 , l3;
    CreateListStatik(&l1);
    CreateListStatik(&l2);
    CreateListStatik(&l3);
    readList(&l1);
    readList(&l2);
    int i, j;
    for (i = 0; i < listLength(l1); i++){
        for (j = 0; j < listLength(l1); j++){
            if (ELMT(l1, i) == ELMT(l2, j)) insertLast(&l3, ELMT(l1, i));
        }   
    }
    sortList(&l3, true);
    printf("%d\n", listLength(l3));
    printList(l3);
    printf("\n");
    return 0;
}