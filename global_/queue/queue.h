#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "../global.h"


typedef struct queue *Pqueue;


void CreateQueue(Pqueue *);

int Push_Queue(void* , Pqueue , int);

void Pop_Queue(void* , Pqueue , int );

void Front(void* , Pqueue , int );

void Back(void* , Pqueue , int );

bool QueueEmpty(Pqueue );

bool QueueFull(Pqueue );

int QueueSize(Pqueue );

void ClearQueue(Pqueue );

void TraverseQueue(Pqueue , void (*)(void*));


#endif