#include <stdio.h>
#include "queue.c"



int main(){
    Queue q;
    int n,i;
    ElType val;
    CreateQueue(&q);
    printf("Masukkan n: ");
    scanf("%d", &n);
    printf("\n");
    for (i = 0; i < n; i++){
        printf("Masukkan elemen ke-%d: ",i+1);
        scanf("%d", &val);
        enqueue(&q, val);
    }
    printf("Hasil queue yang dibuat: ");
    displayQueue(q);
    printf("\n");
    printf("panjang : %d", length(q));
    printf("\n");
    printf("Masukkan n (banyak yang mau dequeue): ");
    scanf("%d", &n);
    printf("\n");
    for (i = 0; i < n; i++){
        dequeue(&q, &val);
        printf("%d didequeue: \n", val);
    }
    printf("\n");
    printf("Queue sekarang: ");
    displayQueue(q);
    printf("\n");
    printf("Panjang : %d", length(q));
}