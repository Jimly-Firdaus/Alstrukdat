#include <stdio.h>

#include "wordmachine.h"
#include "charmachine.h"

char currentChar;
boolean EOP;

boolean EndWord;
Word currentWord;


int main () {

	STARTWORD();
	while(!endWord){
		LowerCase();
		int i;
		for (i = 0; i < currentWord.Length; i++)
		printf("%c", currentWord.TabWord[i]);
		ADVWORD();
		printf(" ");
	}
	return 0;
}