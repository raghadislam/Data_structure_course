#ifndef QUEUE_H
#define QUEUE_H

typedef int QueueEntry;

typedef struct queuenode{
	
	QueueEntry entry;
	struct queuenode *next;
	
}QueueNode;

typedef struct queue{
	
	QueueNode *front;
	QueueNode *rear;
	int size;
	
	
}Queue;

void CreateQueue  (Queue*);
void Push         (QueueEntry, Queue*);
void Pop          (QueueEntry *, Queue*);
int QueueEmpty    (Queue*);
int QueueFull     (Queue*);
int QueueSize     (Queue*);
QueueEntry Front (Queue*);
QueueEntry Back  (Queue*);
void ClearQueue   (Queue*);
void TraverseQueue(Queue*, void (*)(QueueEntry ));

#endif