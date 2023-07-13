#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// create the queue 

void CreateQueue(Queue* pq)
{
	pq->front =  NULL;
	pq->rear  =  NULL;
	pq->size  =   0;

}
 
// function to append an element to the rear 
int Push(QueueEntry e, Queue* pq)
{
	QueueNode* pn = (QueueNode*)malloc(sizeof(QueueNode));
	if(!pn) return 0; // check if malloc worked right (there is enough memory space)
	pn->entry = e;
	pn->next  = NULL;
	if(!pq->rear)
		pq->front  = pn;
	else
	pq->rear->next = pn;
	pq->rear = pn;
	pq->size++;
	return 1
}

// function to serve the front element 
void Pop(QueueEntry *pe, Queue* pq)
{
	QueueNode* pn = pq->front;
	pq->front = pq->front->next;
	if(!pq->front) pq->rear = NULL;
	free(pn);
	pq->size --;
}


// function to tell if the queue is empty


int QueueEmpty(Queue* pq)
{
	return !pq->rear;
}



// function to tell if the queue is full



int QueueFull(Queue* pq)
{
	return 0;
}


// function to return the size


int QueueSize(Queue* pq)
{
	return pq->size;
}


// function to return the front element


QueueEntry Front(Queue* pq)
{
	return pq->front->entry;
}

// function to return the rear element


QueueEntry Back(Queue* pq)
{
	return pq->rear->entry;
}


// function to clear  the queue

void ClearQueue(Queue* pq)
{
	while(pq->front)
	{
		pq->rear = pq->front->next;
		free( pq->front );
		pq->front = pq->rear;
	}
	pq->size = 0;
}

// function to traverse  the queue

void TraverseQueue(Queue* pq, void (*pf)(QueueEntry e))
{
	QueueNode* pn = pq->front;
	for(int size =0; size < pq->size ; size++ )
	{
		(*pf)(pn->entry);
		pn = pn->next;
	}
}