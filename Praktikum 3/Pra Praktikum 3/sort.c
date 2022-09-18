#include "boolean.h"
#include <stdio.h>

void main()
{
    int l[10] = {4, 3, 2, 7, 1, 3, 6, 8, 1, 9};
    int *ptr;
    int temp;
    int i;
    int idx;
    for (i = 1; i < 10; i++)
    {
        idx = i-1;
        temp = l[i];
        while (temp > l[idx] && idx >= 0)
        {
            l[idx + 1] = l[idx];
            idx--;
        }
        l[idx + 1] = temp;
    }

    printf("[");
    int j;
    for (j = 0; j < 10; j++)
    {
        if (j < 9)
            printf("%d,", l[j]);
        else
            printf("%d", l[j]);
    }
    printf("]");
}