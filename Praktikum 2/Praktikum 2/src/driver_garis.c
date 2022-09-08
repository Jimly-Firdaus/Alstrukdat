#include <stdio.h>
#include "garis.c"

void main (){
    GARIS L1 ,L2 ;
    printf("Masukkan garis 1: \n");
    BacaGARIS(&L1);
    printf("Masukkan garis 2: \n");
    BacaGARIS(&L2);
    printf("\n");
    printf("Garis 1 : ");
    TulisGARIS(L1);
    printf("\n");
    printf("Garis 2 : ");
    TulisGARIS(L2);
    printf("\n");
    printf("Panjang garis 1: %f",PanjangGARIS(L1));
    printf("\n");
    printf("Gradien garis 2: %f\n", Gradien(L2));
    printf("Garis 1 digeser 2 ke kanan dan 2 ke atas: \n");
    GeserGARIS(&L1, 2, 2);
    printf("Sekarang Garis 1 menjadi : ");
    TulisGARIS(L1);
    printf("\n");
    if (IsTegakLurus(L1, L2)){
        printf("Tegak Lurus");
    } else {
        printf("Tidak tegak lurus");
    }
    printf("\n");
    if (IsSejajar(L1, L2)){
        printf("Sejajar");
    }else {
        printf("Tidak sejajar");
    }
}

