// NIM : 13521102
// Nama : Jimly Firdaus
// Tanggal : 29 September 2022
// Topik : Mesin kata


#include <stdio.h>
#include "wordmachine.h"
#include "charmachine.h"

char currentChar;
boolean EOP;

boolean EndWord;
Word currentWord;

int main () {
	int max_len = 0;
	int temp = 0;
	int i;

	STARTWORD();
	// printf("passed\n");
	while(!EndWord){
		temp = currentWord.Length;
		if (temp > max_len)  {
			max_len = temp;
		}
		ADVWORD();
	}

	printf("%d\n", max_len);
	// printf("passed here\n");
	return 0;
}
