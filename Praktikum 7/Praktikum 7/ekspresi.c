// NIM : 13521102
// Nama : Jimly Firdaus
// Tanggal : 20 Oktober 2022
// Topik praktikum : ADT Stack
// Deskripsi : ekspresi.c
#include <stdio.h>
#include "wordmachine.h"
#include "charmachine.h"
#include <math.h>
#include "boolean.h"
#include "stack.h"

char currentChar;
boolean EOP;

boolean endWord;
Word currentWord;

boolean isOperator(char cc) {
	if (cc == '+' || cc == '-' || cc == '*' || cc == '/' || cc == '^'){
		return true;
	} else {
		return false;
	}
}

int power (int num_1, int num_2){
	int ans = 1;
	for (int i = 0; i < num_2; i++){
		ans *= num_1;
	}
	return ans;
}

int evaluate(int num_1, int num_2, char opr){
	int ans;
	if (opr=='+'){
		ans = num_1 + num_2;
	}
	else if (opr=='-'){
		ans = num_1 - num_2;
	}
	else if (opr=='*'){
		ans = num_1 * num_2;
	}
	else if (opr=='/'){
		ans = num_1 / num_2;
	}
	else {
		ans = pow(num_1, num_2); 
	}
	return ans;
}

int main () {
	Stack S1;
	CreateEmpty(&S1);
	STARTWORD();
	int long_word = 0;
	if (endWord) {
		printf("Ekspresi kosong\n");
	} else {
		int i = 0, currentInt = 0;
		int operand_1, operand_2;
		while (!endWord){
			if(!isOperator(currentWord.TabWord[i])){
				for (int j = 0; j < currentWord.Length; j++){
					if (j == 0){
						currentInt += (((int) currentWord.TabWord[j]) - 48);
					} else {
					currentInt *= 10;
					currentInt += (((int) currentWord.TabWord[j]) - 48);
					}
				}
				Push(&S1, currentInt);
				printf("%d\n", currentInt);
				currentInt = 0;
			} else {
				Pop(&S1, &operand_1);
				Pop(&S1, &operand_2);
				Push(&S1, evaluate(operand_2, operand_1, currentWord.TabWord[i]));
				printf("%d %c %d\n", operand_2, currentWord.TabWord[i] ,operand_1);
				printf("%d\n", evaluate(operand_2, operand_1, currentWord.TabWord[i]));
			}
			ADVWORD();
			long_word++;
			}	
		}
		int result;
		Pop(&S1, &result);
		if (long_word == 1){
			printf("%d\n", result);
		}
		if (long_word != 0){
			printf("Hasil=%d\n", result);
		}

	return 0;
}
