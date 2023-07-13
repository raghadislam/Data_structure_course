#include <stdio.h>
#include "stack.h"

void Display(StackEntry item)
{
	printf("%d\n",item);
}

int main()
{
Stack S;
	StackEntry item;
	
	CreateStack(&S);
	
	if(!StackFull(&S))Push(5, &S);
	if(!StackFull(&S))Push(10, &S);	
	if(!StackFull(&S))Push(15, &S);	
	
	if(!StackEmpty(&S)) Pop(&item, &S);
	if(!StackEmpty(&S)) Pop(&item, &S);
	
	//printf("\n\nSize of Stack : %d\n\n", StackSize(&S));
	
	//StackTop(&item, &S);
	if(!StackEmpty(&S)) printf("\n\nTop of Stack : %d\n\n", item);
	
	
	if(!StackFull(&S))Push(5, &S);
	if(!StackFull(&S))Push(10, &S);	
	if(!StackFull(&S))Push(15, &S);
	//TraverseStack(&S, &Display);
	
	//ClearStack(&S);
	//printf("\n\nSize of Stack : %d\n\n", StackSize(&S));
	
	
	
	
	return 0;
}