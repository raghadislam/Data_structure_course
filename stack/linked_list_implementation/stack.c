#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void CreateStack(Stack *ps) // O(1)
{
	ps->top = NULL;
	ps->size=0;
}

/* Push: push an item onto the stack.
Pre: The stack exists and intialized.
Post: The argument item has been stored at the top of the stack. */

void Push (StackEntry item ,Stack *ps ) // O(1)
{
	StackNode *pn = (StackNode*)malloc(sizeof(StackNode));
	pn->entry = item ;
	pn->next  = ps->top;
	ps->top   = pn;
	ps->size++;
}

/* Pop: pop an item from the stack.
Pre: The stack exists and it is not empty.
Post: The item at the top of stack has been removed and returned in *item. */

void Pop(StackEntry *pi , Stack* ps) // O(1)
{
	StackNode *pn = (StackNode*)malloc(sizeof(StackNode));
   *pi = ps-> top-> entry;
	pn = ps-> top;
	ps->top = ps->top->next;
	free(pn);
	ps->size--;
}

/* StackEmpty: returns non-zero if the stack is empty.
Pre: The stack exists and it has been initialized.
Post: Return non-zero if the stack is empty; return zero, otherwise. */

int StackEmpty(Stack *ps) // O(1)
{
	return (ps->top==NULL);
}

/* StackFull: always returns zero because linked list is never full.
Pre: The stack exists and it has been initialized.
Post: Return zero.                                                   */

int StackFull(Stack* ps) // O(1)
{
	return 0;
}

void StackTop(StackEntry *item, Stack *ps)
{
	*item = ps->top->entry;
} 

void ClearStack(Stack *ps) // O(N)
{
	StackNode *pn = ps->top;
	while(pn)
	{
		pn=pn->next;
		free(ps->top);
		ps->top=pn;
	}
	ps->size=0;
}
void TraverseStack(Stack *ps, void (*Disply)(StackEntry)) // O(N)
{
	for(StackNode *pn = ps->top ; pn ; pn=pn->next)
	{
		(*Disply)(pn->entry);
	}
	
}
int  StackSize(Stack *ps)  // O(1)
{
	return ps->size;
}