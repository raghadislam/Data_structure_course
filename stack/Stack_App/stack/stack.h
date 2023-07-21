#ifndef STACK_H
#define STACK_H
#include <stdio.h>

#define LIMITED_MEMORY

#define MAX_STACK_SIZE 100

typedef struct stack *Pstack;


void CreateStack(Pstack*);

int Push_Stack(void* , Pstack , int);

void Pop_Stack(void* , Pstack , int);

int StackEmpty(Pstack );

int StackFull(Pstack );

void ClearStack(Pstack );

void TraverseStack(Pstack , void (*)(void *));

int StackSize(Pstack );

void StackTop(void* , Pstack , int);

#endif