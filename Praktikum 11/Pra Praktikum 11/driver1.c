#include <stdio.h>
#include "listrec.h"
#include <stdlib.h>

ElType maxList(List l) {
    if (isOneElmt(l)) {
        return head(l);
    } else {
        ElType max = maxList(l->next);
        if (max < l->info) {
            max = l->info;
        } else {
            return max;
        }
    }

}

ElType minList(List l) {
    if (isOneElmt(l)){
        return head(l);
    } else {
        ElType min = minList(l->next);
        if (min > l->info) {
            min = l->info;
        } else {
            return min;
        }
    }
}

ElType sumList(List l) {
    if (isEmpty(l)) {
        return 0;
    } else {
        return sumList(l->next) + head(l);
    }
}

float AvgList(List l) {
    int total = sumList(l);
    int len = length(l);
    return (float) total / (float) len;
}

List inverseList(List l) {
    if (isEmpty(l)) {
        return NIL;
    } else {
        return konsb(inverseList(l->next), head(l));
    }
}

void splitPosNeg(List l, List *l1, List *l2) {
    if (isEmpty(l)) return;
    else {
        if (l->info >= 0) {
            *l1 = konsb(*l1, l->info);
        } else {
            *l2 = konsb(*l2, l->info);
        }
        return splitPosNeg(l->next, l1, l2);
    }
}

void splitOnX(List l, ElType x, List *l1, List *l2) {
    if (isEmpty(l)) return;
    else {
        if (l->info < x) {
            *l1 = konsb(*l1, l->info);
        } else {
            *l2 = konsb(*l2, l->info);
        }
        return splitOnX(l->next, x, l1, l2);
    }
}

int compareList(List l1, List l2) {
    if (length(l1) < length(l2)) return -1;
    if (length(l1) > length(l2)) return 1;
    else {
        if (isEmpty(l1)) {
            return 0;
        } else {
            if (l1->info != l2->info) {
                if (l1->info > l2->info) return 1;
                else return -1;
            } else {
                compareList(l1->next, l2->next);
            }
        }
    }
}

boolean isAllExist (List l1, List l2) {
    if (isEmpty(l1) && isEmpty(l2)) {
        return true;
    }
    if (isEmpty(l1)) return false;
    else {
        if (!isOneElmt(l1)) {
            if (isMember(l2, l1->info)) {
                return isAllExist(l1->next, l2);
            } else return false;
        } else {
            if (isMember(l2, l1->info)) return true;
            else return false;
        } 
    }

}

int main() {
    List l, invl, posL, negL;
    int input;
    int N = 0;
    l = NULL;
    invl = NULL;
    posL = NULL;
    negL = NULL;
    while (N < 5) {
        scanf("%d", &input);
        l = konsb(l, input);
        N++;
    }
    // dummy = konsb(l, 7);
    displayList(l);
    printf("-------\n");
    ElType max = maxList(l);
    printf("max : %d\n", max);
    ElType min = minList(l);
    printf("min : %d\n", min);
    ElType sum = sumList(l);
    printf("sum : %d\n", sum);
    float avg =  AvgList(l);
    printf("Avg : %.2f\n", avg);
    invl = inverseList(l);
    printf("-------\n");
    displayList(invl);
    printf("-------\n");
    splitPosNeg(l, &posL, &negL);
    displayList(posL);
    printf("-------\n");
    displayList(negL);
    printf("-------\n");
    printf("masukkan x : ");
    scanf("%d", &N);
    posL = NULL;
    negL = NULL;
    splitOnX(l, N, &posL, &negL);
    displayList(posL);
    printf("-------\n");
    displayList(negL);
    printf("-------\n");
    printf("input cmp1\n");
    List cmp1, cmp2;
    cmp1 = NULL;
    cmp2 = NULL;
    N = 0;
    while (N < 4) {
        scanf("%d", &input);
        cmp1 = konsb(cmp1, input);
        N++;
    }
    printf("input cmp2\n");
    N = 0;
    while (N < 6) {
        scanf("%d", &input);
        cmp2 = konsb(cmp2, input);
        N++;
    }
    printf("Result cmp: %d\n", compareList(cmp1, cmp2));

    printf("Is all exist: %d\n", isAllExist(cmp1, cmp2));

    return 0;
}
