// NIM : 13521102
// Nama : Jimly Firdaus
// Tanggal : 20 Oktober 2022
// Topik praktikum : ADT Stack
// Deskripsi : bigint.c
#include <stdio.h>
#include "stack.h"

boolean isNotSame (Stack S1, Stack S2, boolean samelength){
	int c1,c2;
	boolean found = false;
	if (samelength) {
		while(!IsEmpty(S1) && !found){
			Pop(&S1, &c1);
			Pop(&S2, &c2);
			if (c1 != c2){
				found = true;
			}
		}
	} else {
		found = true;
	}
	return found;
}



int main() {
	char N[100];
	char M[100];
	scanf("%s", &N);
	Stack S1, S2, SSub;
	int i = 0, j = 0, num_1, num_2;
	CreateEmpty(&S1);
	CreateEmpty(&S2);
	CreateEmpty(&SSub);
	int num2_gt_num1 = 0;
	while (N[i] != '\0' && i < 100) {
		num_1 = ((int) N[i]) - 48;
		Push(&S1, num_1);
		i++;
	}
	i--;
	scanf("%s", &M);
	while (M[j] != '\0' && j < 100) {
		num_2 = ((int) M[j]) - 48;
		Push(&S2, num_2);
		j++;
	}
	j--;
	int factor = i < j ? (-1) : 1;
	if (((((int) N[0]) - 48) < (((int) M[0]) - 48) && i == j) || (factor == (-1))){
		num2_gt_num1 = 1;
	}
	boolean result = true;
	if (i == j){
		result = isNotSame(S1, S2, true);
	}
	// printf("%d", num2_gt_num1);
	infotype c1,c2;
	int length = i > j ? j : i;
	int looper = 0;
	int res;
	int carry = 0;
	int length_sub = 0;
	while(looper <= length) {	
		Pop(&S1, &c1);
		Pop(&S2, &c2);
		if (num2_gt_num1) {
			res = c2 - c1 + carry;
			carry = 0;
		} else {
			res = c1 - c2 + carry;
			carry = 0;
		}
		if (res < 0){
			carry = (-1);
			res += 10;
		}
		// printf("%d %d", c1,c2);
		Push(&SSub, res);
		length_sub++;
		looper++;
	}
	if (res == 0) {
		Pop(&SSub, &res);
		length_sub--;
	}
	// length_sub--;
	int remainder;
	if (j == length && i != j) {
		while (!IsEmpty(S1)){
			Pop(&S1, &remainder);
			if (carry == -1){
				if (remainder == 0) {
					remainder = remainder + 10 + carry;
				} else {
					remainder = remainder + carry;
					carry = 0;
				}
			}
			Push(&SSub, remainder);
			length_sub++;
		}
		// length_sub--;
	}
	
	if (i == length && i != j) {
		while (!IsEmpty(S2)){
			Pop(&S2, &remainder);
			if (carry == -1){
				if (remainder == 0) {
					remainder = remainder + 10 + carry;
				} else {
					remainder = remainder + carry;
					carry = 0;
				}
			}
			Push(&SSub, remainder);
			length_sub++;
		}
		// length_sub--;
	}
	int print;
	// printf("\n");
	// // length_sub--;
	// printf("%d", length_sub);
	// printf("\n");
	int trailing_zeros_idx = 0;
	if (result){
		if (num2_gt_num1) {
			printf("-");
			while(!IsEmpty(SSub)){
				Pop(&SSub, &print);
				if (trailing_zeros_idx == length_sub){
					if (print != 0){
						printf("%d", print);
					}
				} else {
					printf("%d", print);
				}
				trailing_zeros_idx++;
			}
		} else {
			while(!IsEmpty(SSub)){
				Pop(&SSub, &print);
				if (trailing_zeros_idx == length_sub){
					if (print != 0){
						printf("%d", print);
					}
				} else {
					printf("%d", print);
				}
				trailing_zeros_idx++;
			}
		}
		printf("\n");
	} else {
		printf("0\n");
	}
	
}


