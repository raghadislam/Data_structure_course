#ifndef QUEUE_H
#define QUEUE_H

#define MAXSIZE 100

typedef int QueueEntry;

typedef struct queue{
	
	int front;
	int rear;
	int size;
	QueueEntry entry[MAXSIZE];
	
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