// NIM : 13521102
// Nama : Jimly Firdaus
// Tanggal : 6 Oktober 2022
// Topik praktikum : ADT Queue
// Deskripsi : antrianSix

#include <stdio.h>
#include "queue.h"

int main () {
	Queue q;
	CreateQueue(&q);
	int opr, sum = 0, temp_min;
	int max = 0, min;
	int banyak_mahasiswa = 0;
	ElType val;
	ElType el;
	do {
		scanf("%d", &opr);
		if (opr == 1){
			if (!isFull(q)){
			scanf("%d", &el);
			enqueue(&q, el);
			min = HEAD(q);
		} else {
			printf("Queue penuh\n");
		}
		}
		if (opr == 2){
			if (!isEmpty(q)){
			dequeue(&q, &val);
			if (max < val) {
				max = val;
			}
			if (min > val){
				min = val;
			}
			sum += val;
			banyak_mahasiswa++;
		} else {
			printf("Queue kosong\n");
		}
		}
	} while (opr != 0);
	if (banyak_mahasiswa > 0){
	printf("%d\n", banyak_mahasiswa);
	printf("%d\n", min);
	printf("%d\n", max);
	printf("%.2f\n", (float) sum / (float) banyak_mahasiswa);
} else {
	printf("%d\n", banyak_mahasiswa);
	printf("Tidak bisa dihitung\n");
	printf("Tidak bisa dihitung\n");
	printf("Tidak bisa dihitung\n");
}
	return 0;
}


