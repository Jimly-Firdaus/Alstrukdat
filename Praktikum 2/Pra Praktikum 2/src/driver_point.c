/* File: driver_point.c */
/* Tanggal: 5 September*/
/* Driver ABSTRACT DATA TYPE POINT */

#include <stdio.h>
#include <math.h>
#include "point.c"

int main(){
    POINT P1, P2;
    printf("Input Point default: \n");
    BacaPOINT(&P1);
    TulisPOINT(P1);
    printf("\nMasukkan Point anda: ");
    BacaPOINT(&P2);

    printf("Point anda berada pada kuadran %d\n", Kuadran(P2));
    if(EQ(P1, P2)){
        printf("Point pertama dan kedua sama\n");
    }
    if(NEQ(P1, P2)){
        printf("Point pertama dan kedua beda\n");
    }

    printf("Apabila digeser satu ke kanan, koordinatnya: ");
    TulisPOINT(NextX(P2));printf("\n");
    printf("Digeser satu ke atas, koordinatnya: ");
    TulisPOINT(NextY(P2));printf("\n");
    printf("Digeser satu ke kiri dan bawah, koordinatnya: ");
    TulisPOINT(PlusDelta(P2, -1, -1));printf("\n");
    printf("Dicerminkan sumbu X, koordinatnya: ");
    TulisPOINT(MirrorOf(P2, true));printf("\n");
    printf("Dicerminkan sumbu Y, koordinatnya: ");
    TulisPOINT(MirrorOf(P2, false));printf("\n");

    printf("Point anda akan ditranslasi sebesar P1\n");
    Geser(&P2, P1.X, P1.Y);
    printf("Point anda dicerminkan sumbu Y, kemudian sumbu X, lalu diputar 90 derajat berlawanan jarum jam\n");

    Mirror(&P2, false);
    Mirror(&P2, true);
    Putar(&P2, 90);
    printf("Lokasi titik P2 sekarang ada di: "); TulisPOINT(P2);

    printf("Jarak P1 dengan origin ialah %f, sedangkan dengan P2 ialah %f\n", Jarak0(P1), Panjang(P1, P2));

    if(IsOnSbX(P2)){
        printf("Point anda sudah di sumbu x\n");
    }else{
        printf("Point anda akan digeser ke sumbu x\n");
        GeserKeSbX(&P2);
    }
    if(IsOnSbY(P2)){
        printf("Point anda sudah di sumbu y\n");
    }else{
        printf("Point anda akan digeser ke sumbu y\n");
        GeserKeSbY(&P2);
    }
    if(IsOrigin(P2)){
        printf("Sekarang point 2 ada di origin\n");
    }

}