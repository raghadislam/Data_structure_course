#include "queue.h"
#include <string.h>

#ifdef LIMITED_MEMORY

typedef struct queuenode{
    void* entry;
    struct queuenode *next;
}QueueNode;


struct queue{
    QueueNode *front;
    QueueNode *back;
    int size;
};


// create the queue

void CreateQueue(Pqueue *ppq){
    *ppq = (struct queue *)malloc(sizeof(struct queue));
    (*ppq)->front = NULL;
    (*ppq)->back  = NULL;
    (*ppq)->size  = 0;
}


// function to append an element to the rear

int Push_Queue(void* pe, Pqueue pq, int z){
    QueueNode *pn = (QueueNode *)malloc(sizeof(QueueNode));
    if(!pn) return 0;
    pn->next = NULL;
    memcpy(&pn->entry, pe, z);
    if(!pq->front) pq->front = pn;
    else pq->back->next = pn;
    pq->back = pn;
    pq->size++;
    return 1;
}


// function to serve the front element


void Pop_Queue(void* pe, Pqueue pq, int z)
{
    QueueNode *pn = pq->front;
    memcpy(pe, &pq->front->entry, z);
    pq->front = pq->front->next;
    free(pn);
    if(!pq->front) pq->back = NULL;
    pq->size--;
}


// function to return the front element


void Front(void* p_front, Pqueue pq, int z)
{
    memcpy(p_front, pq->front->entry, z);
}


// function to return the rear element


void Back(void* p_back, Pqueue pq, int z)
{
    memcpy(p_back, pq->back->entry, z);
}


// function to tell if the queue is empty


bool QueueEmpty(Pqueue pq)
{

    return !pq->size;
}


// function to tell if the queue is full


bool QueueFull(Pqueue pq)
{
    return 0;
}


// function to tell if the queue size


int QueueSize(Pqueue pq)
{
    return pq->size;
}


// function to clear  the queue


void ClearQueue(Pqueue pq){
    while (pq->front){
        pq->back = pq->front->next;
        free(pq->front);
        pq->front = pq->back;
    }
    pq->size = 0;
}


// function to traverse  the queue


void TraverseQueue(Pqueue pq, void (*pf)(void*)){

    for (QueueNode *pn = pq->front; pn; pn = pn->next)
        (*pf)(&pn->entry);

}

#else

struct queue{
    int front;
    int back;
    int size;
    void* entry[MAX_QUEUE_SIZE];
};

// create the queue


void CreateQueue(Pqueue *ppq){
    *ppq = (struct queue *)malloc(sizeof(struct queue));
    (*ppq)->front = 0;
    (*ppq)->back  = -1;
    (*ppq)->size  = 0;
}


// function to append an element to the rear


int Push_Queue(void* pe, Pqueue pq, int z){
    pq->back = ( pq->back + 1 ) % MAX_QUEUE_SIZE;
    memcpy(&pq->entry[pq->back], pe, z);
    pq->size++;
}


// function to serve the front element


void Pop_Queue(void *pe, Pqueue pq, int z){
    memcpy(pe, &pq->entry[pq->front], z);
    pq->front = ( pq->front + 1 ) % MAX_QUEUE_SIZE;
    pq->size--;
}


// function to return the front element


void Front(void* p_back, Pqueue pq, int z)
{
    memcpy(p_back, &pq->entry[pq->back], z);
}


// function to return the rear element


void Back(void* p_back, Pqueue pq, int z)
{
    memcpy(p_back, &pq->entry[pq->back], z);
}


// function to tell if the queue is empty


bool QueueEmpty(Pqueue pq)
{
    return !pq->size;
}


// function to tell if the queue is full


bool QueueFull(Pqueue pq){
    return pq->size == MAX_QUEUE_SIZE;
}


// function to tell if the queue size


int QueueSize(Pqueue pq)
{
    return pq->size;
}


// function to clear  the queue


void ClearQueue(Pqueue pq)
{
    pq->front =  0;
    pq->back  = -1;
    pq->size  =  0;
}


// function to traverse  the queue


void TraverseQueue(Pqueue pq, void (*pf)(void*)){
    for (int pos = pq->front, i = 0; i < pq->size; ++i){
        (*pf)(&pq->entry[pos]);
        pos = (pos + 1) % MAX_QUEUE_SIZE;
    }

}


#endif
