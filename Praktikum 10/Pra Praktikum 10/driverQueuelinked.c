#include "queuelinked.h"
#include <stdio.h>

int main () {   
    int banyakUser;
    scanf("%d", &banyakUser);
    Queue olympia;
    CreateQueue(&olympia);

    int i = 0, currentUserTime, threshold = 300, trash;
    
    while (i < banyakUser)
    {   
        scanf("%d", &currentUserTime);
        if (i == 0) {
            enqueue(&olympia, currentUserTime);
            printf("%d\n", length(olympia));
        } else {
            if (currentUserTime - olympia.addrHead->info > threshold) {
                if (!isEmpty(olympia)){
                    dequeue(&olympia, &trash);
                }
                if (!isEmpty(olympia)) {
                    while((currentUserTime - olympia.addrHead->info > threshold) && !isEmpty(olympia)) {
                        dequeue(&olympia, &trash);
                    }
                }
                enqueue(&olympia, currentUserTime);
                printf("%d\n", length(olympia));
            } else {
                enqueue(&olympia, currentUserTime);
                printf("%d\n", length(olympia));
            }
        }
        i++;
    }


    return 0;
}

