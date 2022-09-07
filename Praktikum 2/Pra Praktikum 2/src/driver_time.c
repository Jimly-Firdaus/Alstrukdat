#include <stdio.h>
#include "time.c"

void main()
{
    TIME time;
    printf("\nMasukkan time Awal: \n");
    BacaTIME(&time);
    TulisTIME(time);
    printf("\ntime Awal to detik: %ld\n", TIMEToDetik(time));

    TIME time2;
    printf("\nMasukkan time Akhir: ");
    BacaTIME(&time2);
    TulisTIME(time2);

    long waktu = 0;
    printf("\nMasukkan detik X: ");
    scanf("%ld", &waktu);
    TulisTIME(DetikToTIME(waktu));

    if (TEQ(time, time2))
        printf("\n\n\ntime Awal == time Akhir");
    if (TNEQ(time, time2))
        printf("\ntime Awal != time Akhir");
    if (TLT(time, time2))
        printf("\ntime Awal < time Akhir");
    if (TGT(time, time2))
        printf("\ntime Awal > time Akhir");

    printf("\nSatu detik kemudian untuk time Awal:\n");
    time = NextDetik(time);
    TulisTIME(time);

    printf("\nLima detik kemudian untuk time Akhir:\n");
    time2 = NextNDetik(time2, 5);
    TulisTIME(time2);

    // Mengembalikan ke semula
    time = PrevDetik(time);
    time2 = PrevNDetik(time2, 5);

    printf("\nPrev detik: \n");
    time = PrevDetik(time);
    time2 = PrevNDetik(time2, 5);
    TulisTIME(time);
    TulisTIME(time2);

    printf("\nDurasi dari time Awal ke time Akhir: %ld\n", Durasi(time, time2));
}