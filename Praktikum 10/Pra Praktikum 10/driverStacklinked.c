#include "stacklinked.h"
#include <stdio.h>

boolean containsSame (Stack A, Stack B) {
    boolean same = true;
    while ((!isEmpty(A) || !isEmpty(B)) && same) {
        if (isEmpty(A)) {
            same = false;
        }
        if (isEmpty(B)) {
            same = false;
        }
        int num1,num2;
        pop(&A, &num1);
        pop(&B, &num2);
        if (num1 != num2) {
            same = false;
        }
    }
    return same;
}

int main () {
    int N1, N2;
    Stack A, B;
    CreateStack(&A);
    CreateStack(&B);
    scanf("%d %d", &N1, &N2);
    if (N1 == 0 && N2 == 0) {
        printf("sama\n");
    }
    else {
        // loooper 1
        int num1;
        int trash1;
        int i = 0;
        while (i < N1 + N2) {
            scanf("%d", &num1);
            if (i < N1) {
                if (num1 != 0) {
                    push(&A, num1);
                } else {
                    if (!isEmpty(A)){
                        pop(&A, &trash1);
                    }
                }
            } else {
                if (num1 != 0) {
                push(&B, num1);
                } else {
                    if (!isEmpty(B)){
                        pop(&B, &trash1);
                    }
                }
            }
            i++;
        } // end input 
        if (containsSame(A,B)) {
            printf("sama\n");
        } else {
            printf("tidak sama\n");
        }

    }


    return 0;
}
