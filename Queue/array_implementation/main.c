#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void Display(int x){
    printf(" %d ", x);
}

int main() {
    Queue q;
    QueueEntry e;

    CreateQueue(&q);

    for(int i = 0; i < 10; ++i) if(!QueueFull(&q))Push(i, &q);


    if(!QueueEmpty(&q))
    printf("\nFront of Queue : %d\nBack of Queue : %d", Front(&q), Back(&q));

    for(int i = 0; i < 10; ++i) {
        if(!QueueEmpty(&q)) Pop(&e, &q);
    }
    printf("\nLast element in Queue : %d",e);

    if(!QueueEmpty(&q))
    printf("\nFront of Queue : %d\nBack of Queue : %d", Front(&q), Back(&q));


    for(int i = 0; i < 20; ++i) if(!QueueFull(&q))Push(i, &q);

    printf("\nSize of Queue is : %d\n", QueueSize(&q));

    TraverseQueue(&q, &Display);

    return 0;
}