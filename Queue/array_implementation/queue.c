#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// create the queue 

void CreateQueue(Queue* pq)
{
	pq->front =  0;
	pq->rear  = -1;
	pq->size  =  0;
}
 
// function to append an element to the rear 
void Push(QueueEntry e, Queue* pq)
{
	pq->rear = (pq->rear + 1) % MAXSIZE;
	pq->entry[pq->rear] = e;
	pq->size++;
}

// function to serve the front element 
void Pop(QueueEntry *pe, Queue* pq)
{
	*pe = pq->entry[pq->front];
	pq->front = (pq->front + 1) % MAXSIZE;
	pq->size--;
}


// function to tell if the queue is empty


int QueueEmpty(Queue* pq)
{
	return !pq->size;
}



// function to tell if the queue is full



int QueueFull(Queue* pq)
{
	return pq->size == MAXSIZE;
}


// function to return the size


int QueueSize(Queue* pq)
{
	return pq->size;
}


// function to return the front element


QueueEntry Front(Queue* pq)
{
	return pq->entry[pq->front];
}

// function to return the rear element


QueueEntry Back(Queue* pq)
{
	return pq->entry[pq->rear];
}


// function to clear  the queue

void ClearQueue(Queue* pq)
{
	pq->front =  0;
	pq->rear  = -1;
	pq->size  =  0;
}

// function to traverse  the queue

void TraverseQueue(Queue* pq, void (*pf)(QueueEntry e))
{
	int pos = pq->front ,size;
	for(int size =0; size < pq->size; size++ )
	{
		(*pf)(pq->entry[pos]);
		pos = ( pos + 1 ) % MAXSIZE;
	}
}