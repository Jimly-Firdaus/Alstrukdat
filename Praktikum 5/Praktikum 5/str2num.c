/*
Nama    : Jimly Firdaus
NIM     : 13521102
Topik   : ADT Mesin Kata
*/

#include <stdio.h>
#include "boolean.h"
#include "wordmachine.h"

boolean isInside(char *word, Word cw)
{
	int panjang = 0;
    while (word[panjang] != '\0')
    {
        panjang++;
    }
    if (panjang != cw.Length)
    {
        return false;
    }
    else
    {
        int i = 0;
        for (i; i < panjang; i++)
        {
            if (word[i] != cw.TabWord[i])
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
	// edge cases
    char sepuluh[] = "sepuluh";
    char sebelas[] = "sebelas";
	char seratus[] = "seratus";
    char belas[] = "belas";
    char puluh[] = "puluh";
    char ratus[] = "ratus";
	// normal cases
    char nol[] = "nol";
    char satu[] = "satu";
    char dua[] = "dua";
    char tiga[] = "tiga";
    char empat[] = "empat";
    char lima[] = "lima";
    char enam[] = "enam";
    char tujuh[] = "tujuh";
    char delapan[] = "delapan";
    char sembilan[] = "sembilan";
    

    STARTWORD();

    int value = 0;
    boolean isCurrentAngka = false;

    while (!endWord)
    {
        IgnoreBlanks();
        if (isInside(sepuluh, currentWord))
        {
            value += 10;
            isCurrentAngka = true;
        }
        else if (isInside(sebelas, currentWord))
        {
            value += 11;
            isCurrentAngka = true;
        }
        else if (isInside(belas, currentWord))
        {
            value += 10;
            isCurrentAngka = true;
        }
        else if (isInside(puluh, currentWord))
        {
            value = value - (value % 100) + (value % 100) * 10;
            isCurrentAngka = true;
        }
        else if (isInside(ratus, currentWord))
        {
            value *= 100;
            isCurrentAngka = true;
        }
        else if (isInside(seratus, currentWord))
        {
            value += 100;
            isCurrentAngka = true;
        }
        else if (isInside(nol, currentWord))
        {
            isCurrentAngka = true;
        }
        else if (isInside(satu, currentWord))
        {
            value += 1;
            isCurrentAngka = true;
        }
        else if (isInside(dua, currentWord))
        {
            value += 2;
            isCurrentAngka = true;
        }
        else if (isInside(tiga, currentWord))
        {
            value += 3;
            isCurrentAngka = true;
        }
        else if (isInside(empat, currentWord))
        {
            value += 4;
            isCurrentAngka = true;
        }
        else if (isInside(lima, currentWord))
        {
            value += 5;
            isCurrentAngka = true;
        }
        else if (isInside(enam, currentWord))
        {
            value += 6;
            isCurrentAngka = true;
        }
        else if (isInside(tujuh, currentWord))
        {
            value += 7;
            isCurrentAngka = true;
        }
        else if (isInside(delapan, currentWord))
        {
            value += 8;
            isCurrentAngka = true;
        }
        else if (isInside(sembilan, currentWord))
        {
            value += 9;
            isCurrentAngka = true;
        }
        else
        {
            if (isCurrentAngka)
            {
                printf("%d ", value);
                value = 0;
                isCurrentAngka = false;
            }

            int i = 0;
            for (i; i < currentWord.Length; i++)
            {
                printf("%c", currentWord.TabWord[i]);
            }
        }

        ADVWORD();

        if (!isCurrentAngka && !endWord)
        {
            printf(" ");
        }
    }

    if (isCurrentAngka)
    {
        printf("%d", value);
    }

    printf("\n");

    return 0;
}