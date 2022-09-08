// NIM : 13521102
// Nama : Jimly Firdaus
// Tanggal : 8 September 2022
// Topik praktikum : ADT Sederhana
// Deskripsi : ADT Vector
// Score : 160 / 190

#include <stdio.h>
#include "vector.h"
#include <math.h>

void CreateVector(VECTOR *v, float x, float y)
{
    /* Membentuk sebuah VECTOR dengan komponen absis x dan
       komponen ordinat y */
    Absis(*v) = x;
    Ordinat(*v) = y;
}
/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void TulisVector(VECTOR v)
{
    /* Nilai v ditulis ke layar dengan format "<X,Y>"
       tanpa spasi, enter, atau karakter lain di depan, belakang, atau di antaranya
       Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
    */
    /* I.S. v terdefinisi */
    /* F.S. v tertulis di layar dengan format "<X,Y>" */
    printf("<%.2f,%.2f>", Absis(v), Ordinat(v));
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
float Magnitude(VECTOR v)
{
    /* Menghasilkan magnitudo dari vector, yakni sqrt(v.x^2+v.y^2) */
    return (sqrt(pow(Absis(v), 2) + pow(Ordinat(v), 2)));
}
VECTOR Add(VECTOR a, VECTOR b)
{
    /* Menghasilkan sebuah vector yang merupakan hasil a + b.
       Komponen absis vector hasil adalah vector pertama
       ditambah vector kedua, begitu pula dengan ordinatnya */
    VECTOR new;
    Absis(new) = Absis(a) + Absis(b);
    Ordinat(new) = Ordinat(a) + Ordinat(b);
    return new;
}
VECTOR Substract(VECTOR a, VECTOR b)
{
    /* Menghasilkan sebuah vector yang merupakan hasil a - b.
       Komponen absis vector hasil adalah vector pertama
       dikurangi vector kedua, begitu pula dengan ordinatnya */
    VECTOR sub;
    Absis(sub) = Absis(a) - Absis(b);
    Ordinat(sub) = Ordinat(a) - Ordinat(b);
    return sub;
}
float Dot(VECTOR a, VECTOR b)
{
    /* Menghasilkan perkalian dot vector, yakni a.x * b.x + a.y * b.y */
    return ((Absis(a) * Absis(b)) + (Ordinat(a) * Ordinat(b)));
}
VECTOR Multiply(VECTOR v, float s)
{
    /* Menghasilkan perkalian skalar vector dengan s, yakni
       (s * v.x, s * v.y) */
    VECTOR mul;
    Absis(mul) = Absis(v)*s;
    Ordinat(mul) = Ordinat(v)*s;
    return mul;
}