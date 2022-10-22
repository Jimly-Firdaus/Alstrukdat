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

boolean isNum1GTNum2 (int arr1[], int arr2[], int length){
	// Prerequisite : length of the two must be same
	int i = 0;
	if (arr1[0] > arr2[0]) {
		return false;
	} 
	else if (arr1[0] == arr2[0]) {
		boolean foundGT = false;
		while (i < length + 1){
			if (arr1[i] < arr2[i]) {
				foundGT = true;
				break;
			}
			else {
				i++;
			}
		}
	return foundGT;
	} else {
		return true;
	}
}


int main() {
	char N[101];
	char M[101];
	int arr_num1[101];
	int arr_num2[101];
	scanf("%s", &N);
	Stack S1, S2, SSub;
	int i = 0, j = 0, num_1, num_2;
	CreateEmpty(&S1);
	CreateEmpty(&S2);
	CreateEmpty(&SSub);
	boolean num2_gt_num1 = false;
	while (N[i] != '\0' && i < 100) {
		num_1 = ((int) N[i]) - 48;
		Push(&S1, num_1);
		arr_num1[i] = num_1;
		i++;
	}
	i--;
	scanf("%s", &M);
	while (M[j] != '\0' && j < 100) {
		num_2 = ((int) M[j]) - 48;
		Push(&S2, num_2);
		arr_num2[j] = num_2;
		j++;
	}
	j--;
	int factor = i < j ? (-1) : 1;
	if (i == j) {
		num2_gt_num1 = isNum1GTNum2(arr_num1, arr_num2, i);
	}
	if (i < j){
		num2_gt_num1 = true;
	}
	boolean result = true;
	if (i == j){
		result = isNotSame(S1, S2, true);
	}
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
		Push(&SSub, res);
		length_sub++;
		looper++;
	}
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
	}
	int checker;
	for (int k = 0; k < length_sub; k++) {
		Pop(&SSub, &checker);
		if (checker != 0){
			Push(&SSub, checker);
			break;
		}
	}
	int print;
	if (result){
		if (num2_gt_num1) {
			printf("-");
			while(!IsEmpty(SSub)){
				Pop(&SSub, &print);
				printf("%d", print);
			}
		} else {
			while(!IsEmpty(SSub)){
				Pop(&SSub, &print);
				printf("%d", print);
			}
		}
		printf("\n");
	} else {
		printf("0\n");
	}
}