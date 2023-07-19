#include "list.h"
#include <stdlib.h>
#include <string.h>

#ifdef LIMITED_MEMORY

typedef struct listnode
{
    void* entry;
    struct listnode *next;

}ListNode;

struct list{
    ListNode *Head;
    ListNode *Current;
    int CurrentPos;
    int size;
};

int CreateList(Plist *ppl)
{
    *ppl = (struct list *)malloc(sizeof(struct list));
    if(!(*ppl)) return 0;
    (*ppl)->Head = NULL;
    (*ppl)->Current = NULL;
    (*ppl)->CurrentPos = 0;
    (*ppl)->size = 0;
    return 1;

}
int Insert(int ind, void* pe, Plist pl, int z)
{
    ListNode *p = (ListNode *) malloc(sizeof (ListNode));
    if(!p) return 0;
    memcpy(&p->entry, pe, z);
    if(ind == 0)
    {
        p->next = pl->Head;
        pl->Head = p;
        pl->Current = p;
        pl->CurrentPos = 0;
    }
    else
    {
        if(ind <= pl->CurrentPos)
        {
            pl->CurrentPos = 0;
            pl->Current = pl->Head;
        }

        for( ; pl->CurrentPos < ind - 1 ; ++pl->CurrentPos)
        {
            pl->Current = pl->Current->next;
        }
        p->next = pl->Current->next;
        pl->Current->next = p;
    }
    pl->size++;
    return 1;
}

void Delete(int ind, void* pe, Plist pl, int z)
{
    ListNode *temp ;
    if(ind == 0)
    {
        memcpy(pe, &pl->Head->entry, sizeof(z));
        pl->Current = pl->Head->next;
        free(pl->Head);
        pl->Head = pl->Current;
        pl->CurrentPos = 0;
    }
    else
    {
        if(ind <= pl->CurrentPos)
        {
            pl->CurrentPos = 0;
            pl->Current = pl->Head;
        }

        for( ; pl->CurrentPos < ind - 1 ; ++pl->CurrentPos)
        {
            pl->Current = pl->Current->next;
        }
        temp= pl->Current->next->next;
        memcpy(pe, &pl->Current->next->entry, sizeof(z));
        free(pl->Current->next);
        pl->Current->next = temp;
    }
    pl->size--;

}

void DestroyList(Plist pl)
{
    ListNode* temp = NULL;
    while(pl->Head)
    {
        temp = pl->Head->next;
        free(pl->Head);
        pl->Head = temp;
    }
    pl->size = 0;
}

void Retrieve_List(int ind, void* pe, Plist pl, int z)
{
    if(ind <= pl->CurrentPos)
    {
        pl->CurrentPos = 0;
        pl->Current = pl->Head;
    }

    for( ; pl->CurrentPos < ind ; ++pl->CurrentPos)
    {
        pl->Current = pl->Current->next;
    }
    memcpy(pe, &pl->Current->entry, sizeof(z));
}

void Replace_List(int ind, void* pe, Plist pl, int z)
{
    if(ind <= pl->CurrentPos)
    {
        pl->CurrentPos = 0;
        pl->Current = pl->Head;
    }

    for( ; pl->CurrentPos < ind ; ++pl->CurrentPos)
    {
        pl->Current = pl->Current->next;
    }
    memcpy(&pl->Current->entry, pe, sizeof(z));
}

int ListSize(Plist pl)
{
    return pl->size;
}

int ListEmpty(Plist pl)
{
    return !pl->size;

}

int ListFull(Plist pl)
{
    return 0;
}


void TraverseList(Plist pl, void(*Display)(void*))
{
    ListNode *p = pl->Head;
    while(p)
    {
        (*Display)(&p->entry);
        p = p->next;
    }
}

#else


struct list{
    void* entry[MAX_LIST_SIZE];
    int size;
};

int CreateList(Plist *ppl)
{
    *ppl = (struct list *)malloc(sizeof(struct list));
    if(!(*ppl)) return 0;
    (*ppl)->size = 0;
    return 1;
}


int Insert(int ind, void* pe, Plist pl, int z)
{
    for(int i = pl->size - 1; i >= ind; --i)
    {
        pl->entry[i+1] = pl->entry[i];
    }
    memcpy(&pl->entry[ind], pe, sizeof(z));
    pl->size++;
}


void Delete(int ind, void* pe, Plist pl, int z)
{
    memcpy(pe, &pl->entry[ind], sizeof(z));
    for (int i = ind; i < pl->size - 1; ++i)
    {
        pl->entry[i] = pl->entry[i + 1];
    }
    pl->size--;
}


// 0<= ind <= size-1

void Retrieve_List(int ind, void* pe, Plist pl, int z)
{
    memcpy(pe, &pl->entry[ind], sizeof(z));
}
// 0<= ind <= size-1

void Replace_List(int ind, void* pe, Plist pl, int z)
{
    memcpy(&pl->entry[ind], pe, sizeof(z));
}

int ListSize(Plist pl)
{
    return pl->size;
}

int ListEmpty(Plist pl)
{
    return !pl->size;
}

int ListFull(Plist pl)
{
    return pl->size == MAX_LIST_SIZE;
}

void DestroyList(Plist pl)
{
    pl->size = 0;
}

void TraverseList(Plist pl, void(*Display)(void*))
{
    for(int i = 0; i < pl->size; ++i)
    {
        (*Display)(&pl->entry[i]);
    }
}

#endif