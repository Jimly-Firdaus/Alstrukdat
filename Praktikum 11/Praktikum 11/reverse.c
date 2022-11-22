#include <stdio.h>
#include "listrec.h"

void splitAtIndex(List l, int index, int looper, List *lout) {
	if (length(l) < index && looper == 0) {
		if (isEmpty(l)) return;
		else {
			*lout = konso(*lout, l->info);
			return splitAtIndex(l->next, index, looper, lout);
		}
	}
    else {
    	if (looper < index) {
    		*lout = konso(*lout, l->info);
    		return splitAtIndex(l->next, index, looper + 1, lout);	
    	} else {
    		return;
    	}
    }
}

List skipTillIndex(List l, int indexStop) {
	if (indexStop == 0 || length(l) < indexStop) return l;
	else {
		return skipTillIndex(l->next, indexStop - 1);
	}
}

void displayListv2(List l) {
/* I.S. List l mungkin kosong */
/* F.S. Jika list tidak kosong, nilai list dicetak ke bawah */
/*      Dipisahkan dengan newline (\n) dan diakhiri dengan newline */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak:
  1
  20
  30
 */
/* Jika list kosong, tidak menuliskan apa-apa  */
    if (isOneElmt(l)) {
		printf("%d", l->info);
	} else {
		printf("%d ", l->info);
        displayListv2(tail(l));
	}
}


int main() {
	int nMahasiswa;
	int nPartisi;
	scanf("%d %d", &nMahasiswa, &nPartisi);
	List mahasiswa;
	mahasiswa = NULL;
	int i = 0, nim;
	while (i < nMahasiswa) {
		scanf("%d", &nim);
		mahasiswa = konsb(mahasiswa, nim);
		i++;
	}

	List sectionPart, result;
	sectionPart = NULL;
	result = NULL;
	boolean endLoop = false;
	// int j = 0;
	// splitAtIndex(mahasiswa, 4, 0, &sectionPart);
	// displayListv2(sectionPart);
	// printf("\n");
	// result = concat(result, sectionPart);
	// printf("res: ");
	// displayListv2(result);
	// sectionPart = NULL;
	// mahasiswa = skipTillIndex(mahasiswa, 4);
	// printf("\n");
	// displayListv2(mahasiswa);
	// printf("\n");
	// splitAtIndex(mahasiswa, 4, 0, &sectionPart);
	// displayListv2(sectionPart);
	// printf("\n");
	// printf("res: ");
	// result = concat(result, sectionPart);
	// displayListv2(result);
	// printf("\n");
	while(!endLoop && !isEmpty(mahasiswa)) {
		if (length(mahasiswa) == nPartisi || length(mahasiswa) < nPartisi) endLoop = true;
		splitAtIndex(mahasiswa, nPartisi, 0, &sectionPart);
		displayListv2(sectionPart);
		sectionPart = NULL;
		if (length(mahasiswa) > nPartisi) {
			printf(" ");
			mahasiswa = skipTillIndex(mahasiswa, nPartisi);
		} else mahasiswa = NULL;
	}
	// displayListv2(result);
	printf("\n");
	return 0;
}