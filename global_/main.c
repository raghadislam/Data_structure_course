#include <stdio.h>
#include <string.h>
#include "global.h"

void Display(void *e)
{
    int x;
    memcpy(&x, e, sizeof(x));
    printf("%d ", x);
}

int main() {

    // List

    printf("\n<---------------List--------------->\n");
    Plist l;
    CreateList(&l);
    int e;

    // To Use it like Stack

    printf("\nUsing List as Stack : \n");
    for(int i = 1; i <= 10; ++i)
    {
        if(!ListFull(l))
        {
            Insert(0, (void*)&i, l, sizeof(i));
        }
    }

    TraverseList(l, &Display);

    for(int i = 1; i <= 10; ++i)
    {
        if(!ListFull(l))
        {
            Delete(0, (void*)&e, l, sizeof(e));
        }
    }


    // To Use it like Queue

    printf("\n\nUsing List as Queue : \n");

    for(int i = 1; i <= 10; ++i)
    {
        if(!ListFull(l))
        {
            Insert(ListSize(l), (void*)&i, l, sizeof(i));
        }
    }

    TraverseList(l, &Display);

    DestroyList(l);

    // Queue

    printf("\n\n<---------------Queue--------------->\n");
    Pqueue q;
    CreateQueue(&q);
    int e1;
    for(int i = 1; i < 9; ++i)
    {
        if(!QueueFull(q))
        {
            Push_Queue((void*)&i, q, sizeof(i));
        }
    }

    TraverseQueue(q, &Display);

    for(int i = 1; i < 6; ++i)
    {
        if(!QueueEmpty(q))
        {
            Pop_Queue((void*)&e1, q, sizeof(e1));
        }
    }
    printf("\n\n");
    TraverseQueue(q, &Display);

    // Stack

    printf("\n\n<---------------Stack--------------->\n");
    Pstack st;
    CreateStack(&st);


    int e2;
    for(int i = 1; i < 9; ++i)
    {
        if(!StackFull(st))
        {
            Push_Stack((void*)&i, st, sizeof(i));
        }
    }
    TraverseStack(st, &Display);

    for(int i = 1; i < 6; ++i)
    {
        if(!StackEmpty(st))
        {
            Pop_Stack((void*)&e2, st, sizeof(e2));
        }
    }
    printf("\n\n");
    TraverseStack(st, &Display);
    return 0;
}
