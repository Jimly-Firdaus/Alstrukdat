#include <stdio.h>
#include "stack.h"

int main () {
    Stack S1, S2, SPlus;
    CreateEmpty(&S1);
    CreateEmpty(&S2);
    CreateEmpty(&SPlus);
    char N[100] = {'#'};
    scanf("%s", &N);
    int i = 0, num_1, num_2;
    while (N[i] != '#' && i < 100) {
        num_1 = ((int) N[i]) - 48;
        Push(&S1, num_1);      
        i++;
    }
    // Length (S1)
    i--;
    char M[100] = {'#'};
    scanf("%s", &M);
    int j = 0;
    while (M[j] != '#' && j < 100) {
        num_2 = ((int) M[j]) - 48;
        Push(&S2, num_2);      
        j++;
    }
    // Length (S2)
    j--;
    int c1 , c2;
    int res;
    int length = i > j ? j : i;
    int looper = 0, carry = 0;
    while (looper <= length) {
        Pop(&S1, &c1);
        Pop(&S2, &c2);
        res = c1 + c2 + carry;
        carry = 0;
        if (res >= 10) {
            res -= 10;
            carry++;
        }
        Push(&SPlus, res);
        looper++;
        printf("%d\n", res);
    }
    if (i == j && carry != 0){
        Push(&SPlus, carry);
    }
    int remainder;
    if (length == i && i != j) {
        while(!IsEmpty(S2)){
            Pop(&S2, &remainder);
            if (carry != 0){
                remainder += carry;
            }
            carry = 0;
            if (remainder >= 10) {
                remainder -= 10;
                carry++;
            }
            Push(&SPlus, remainder);
        }
    }
    if (length == j && i != j) {
        while(!IsEmpty(S1)){
            Pop(&S1, &remainder);
            if (carry != 0){
                remainder += carry;
            }
            carry = 0;
            if (remainder >= 10) {
                remainder -= 10;
                carry++;
            }
            Push(&SPlus, remainder);
        }
    }
    int print;
    while (!IsEmpty(SPlus))
    {
        Pop(&SPlus, &print);
        printf("%d",print);
    }
    printf("\n");

    return 0;
}


