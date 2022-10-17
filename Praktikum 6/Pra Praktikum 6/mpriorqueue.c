#include <stdio.h>
#include "priorqueue.h"


int main () {
    int N;
    PrioQueue q;
    CreatePrioQueue(&q);
    scanf("%d", &N);
    int i = 0, tArrival, id, score, dService;
    ElType val;
    while (i < N){
        scanf("%d %d %d %d", &tArrival, &id, &score, &dService);
        val.tArrival = tArrival;
        val.id = id;
        val.score = score;
        val.dService = dService;
        enqueue(&q, val);
        i++;
    }
    // After inputs
    int j, start = 0, total = 0, total_service_before = 0;
    for (j = 0; j < length(q); j++){
        i = j;
        while (i <= IDX_TAIL(q)){
            total_service_before += q.buffer[i].dService;
            i++;
        }
        start = total_service_before + 1;
        total = start - q.buffer[j].tArrival;
        printf("%d %d %d", start, q.buffer[j].id, total);
        printf("\n");
    }
    // for (int j = 0; j < length(q); j++){
    //     printf("%d ", q.buffer[j].tArrival);
    //     printf("%d ", q.buffer[j].id);
    //     printf("%d ", q.buffer[j].score);
    //     printf("%d", q.buffer[j].dService);
    //     printf("\n");
    // }

    return 0;
}

