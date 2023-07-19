#include <stdio.h>
#include "stack.h"

/* CreateStack: initialize the stack to be empty.
Pre: None.
Post: The stack has been initialized to be empty. */

void CreateStack(Stack *ps)
{
	ps->top=0;
}

/* Push: push an item onto the stack.
Pre: The stack exists and it is not full.
Post: The argument item has been stored at the top of the stack. */

void Push (StackEntry item ,Stack *ps )
{
	ps->entry[ps->top++]=item;
}

/* StackFull: returns non-zero if the stack is full.
Pre: The stack exists and it has been initialized.
Post: Return non-zero if the stack is full; return zero, otherwise. */

int StackFull(Stack* ps)
{
	return ps->top==MAX_SIZE;
}

/* Pop: pop an item from the stack.
Pre: The stack exists and it is not empty.
Post: The item at the top of stack has been removed and returned in *item. */

void Pop(StackEntry *pi , Stack* ps)
{
	*pi= ps->entry[--ps->top];
}

/* StackEmpty: returns non-zero if the stack is empty.
Pre: The stack exists and it has been initialized.
Post: Return non-zero if the stack is empty; return zero, otherwise. */

int StackEmpty(Stack *ps)
{
	return !(ps->top);
}


/*
precondition: The stack exists and it has been initialized.
postcondition: The function returns the number of entries in the stack.
*/

int  StackSize(Stack *ps)
{
	return ps->top;
}

/*
precondition: The stack exists and it is not empty.
postcondition: The item at the top of the stack is returned (in *item) without

being removed; the stack remains unchanged.
*/

void StackTop(StackEntry *item, Stack *ps)
{
	*item = ps->entry[ps->top-1];
}

/*
precondition: The stack exists.
postcondition: set the top to zero.
*/


void ClearStack(Stack *ps)
{
	ps->top =0;
}

/*
precondition: The stack exists.
postcondition: Display all elements of the stack.
*/

void TraverseStack(Stack *ps, void (*Disply)(StackEntry))
{
	for(int i=(ps->top-1); i>=0; --i)
	{
		(*Disply)(ps->entry[i]);
	}
	
}


