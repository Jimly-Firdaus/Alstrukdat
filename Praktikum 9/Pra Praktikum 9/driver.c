#include "list_circular.h"
#include <stdio.h>

void deleteRR(List *l, ElType tQ)
{
    if (!isEmpty(*l))
    {
        Address p = FIRST(*l);
        while (p->next != FIRST(*l))
        {
            p = p->next;
        }
        // p->next == FIRST(*l) && p == last
        if (p->info > tQ)
        {
            p->info = p->info - tQ;
            FIRST(*l) = p;
            printf("%d\n", tQ);
        }
        else
        {
            int out;
            deleteLast(l, &out);
            printf("%d\n", out);
        }
    }
    else
    {
        printf("List Kosong\n");
    }
}

float avg(List l)
{
    int num;
    int sum = 0;
    int total = 0;
    while (!isEmpty(l))
    {
        deleteLast(&l, &num);
        sum += num;
        total += 1;
    }
    return ((float)sum / (float)total);
}

int main()
{

    int Tq;
    boolean valid = false;
    float res;
    int looper = 0;
    List round_robin;
    CreateList(&round_robin);
    boolean endLoop = false;
    int el;
    char process;
    while (!endLoop)
    {
        do
        {
            // Get Tq
            scanf("%d", &Tq);
        } while (Tq <= 0 && !valid);
        valid = true;
        // Tq valid
        scanf("%c", &process);
        if (process == 'A')
        {
            scanf("%d", &el);
            if (el > 0)
            {
                insertFirst(&round_robin, el);
            }
        }
        else if (process == 'D')
        {
            deleteRR(&round_robin, Tq);
        }
        else if (process == 'F')
        {
            endLoop = true;
            if (!isEmpty(round_robin))
            {
                res = avg(round_robin);
                printf("%.2f\n  ", res);
            }
            else
            {
                printf("Proses selesai\n");
            }
        }
        else
        {
            if (looper >= 1){
               printf("Kode Salah\n");
            }
        }
        looper++;
    }
    return 0;
}