// NIM : 13521102
// Nama : Jimly Firdaus
// Tanggal : 6 Oktober 2022
// Topik praktikum : ADT Queue
// Deskripsi : sjf.c

#include <stdio.h>
#include "prioqueuetime.h"
#include <stdlib.h>

int main(){
    int N, looper = 0;
    scanf("%d", &N);
    PrioQueueTime PQ;
    MakeEmpty(&PQ, N);
    infotype* arr = (infotype*) malloc (N * sizeof(infotype));
    infotype X, val;
    PQ.MaxEl = N;
    int current_time = 0;
    int total_elapsed = 0;
    int time, idx = 0;
    char info;
    boolean processing = true, endProcess = false;
    scanf("%d", &time);
    scanf("%c", &info);
    arr[idx].time = current_time;
    arr[idx].info = info;
    current_time = 1;
    total_elapsed = time;
    idx++;
    while (!endProcess) {
        if (looper < (N)){
            scanf("%d", &time);
            scanf("%c", &info);
            X.info = info;
            X.time = time;
            Enqueue(&PQ, X);
            looper++;
        }
        if (current_time == total_elapsed){
            processing = false;
            total_elapsed += InfoHead(PQ).time;
        }
        if (!processing) {
            Dequeue(&PQ, &val);
            arr[idx].info = val.info;
            arr[idx].time = current_time;
            idx++;
            processing = true;
        }
        if (IsEmpty(PQ) && (looper >= (N - 1))){
            printf("%d", looper);
            endProcess = true;
        }
        current_time++;
    }

    int j;
    for (j = 0; j < N; j++){
        printf("%d %c\n", arr[j].time, arr[j].info);
    }

    return 0;
}
