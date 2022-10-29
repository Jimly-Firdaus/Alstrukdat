// NIM : 13521102
// Nama : Jimly Firdaus
// Tanggal : 27 Oktober 2022
// Topik praktikum : ADT Linked List
// Deskripsi : 
#include <stdio.h>
#include "listlinier.h"

int main() {
	// mengambil ukuran cache
	int max_size;
	scanf("%d", &max_size);
	int ctr_size = 0;

	// init cache
	List cache;
	CreateList(&cache);

	//mengambil jumlah opr
	int N;
	scanf("%d", &N);
	int temp = N;
	// hit & miss & ratio
	int hit = 0;
	int miss = 0;
	float ratio;

	int x, index_x;

	int dummy;
	// proses
	while (N > 0) {
		// 
		scanf("%d", &x);
		index_x = indexOf(cache, x);
		if (max_size == 0) {
			printf("miss ");
			displayList(cache);
			printf("\n");
			miss++;
		} else {
		if (index_x == IDX_UNDEF) {
			if (ctr_size == max_size){
				deleteLast(&cache, &dummy);
				insertFirst(&cache, x);
			} else {
				insertFirst(&cache, x);
				ctr_size++;
			}
			miss++;
			printf("miss ");
			displayList(cache);
			printf("\n");
		}
		else {
			deleteAt(&cache, index_x, &dummy);
			insertFirst(&cache, x);
			hit++;
			printf("hit ");
			displayList(cache);
			printf("\n");
		}
		}
		N--;
	}


	if (temp == 0) {
		ratio = 0;
	} else {
		ratio = (float) hit /(float) (miss+hit);
	}
	printf("hit ratio: %.2f\n", ratio);
	
	return 0;
}

