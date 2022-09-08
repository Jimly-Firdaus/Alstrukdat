// NIM : 13521102
// Nama : Jimly Firdaus
// Tanggal : 8 September 2022
// Topik praktikum : ADT Sederhana
// Deskripsi : Time
// Score : 40 / 40
#include <stdio.h>
#include "time.h"

int main()
{
    int N;
    int i;
    long min = 86400, max = 0;
    scanf("%d", &N);

    for (i = 1; i <= N; i++)
    {
        printf("[%d]\n", i);
        TIME T1, T2;
        BacaTIME(&T1);
        BacaTIME(&T2);
        if (TIMEToDetik(T1) < min)
            min = TIMEToDetik(T1);
        if (TIMEToDetik(T2) < min)
            min = TIMEToDetik(T1);
        if (TIMEToDetik(T1) > max)
            max = TIMEToDetik(T1);
        if (TIMEToDetik(T2) > max)
            max = TIMEToDetik(T2);
        printf("%ld\n", (TGT(T1, T2) ? Durasi(T2, T1) : Durasi(T1, T2)));
    }
    TulisTIME(DetikToTIME(min));
    printf("\n");
    TulisTIME(DetikToTIME(max));
    printf("\n");
    return 0;
}
