#ifndef STACK_H
#define STACK_H

typedef char StackEntry;

typedef struct stacknode{
	
	StackEntry entry;
	struct stacknode *next;
	
}StackNode;

typedef struct stack{
	StackNode *top;
	int size;
}Stack;

void CreateStack  (Stack *);
void Push         (StackEntry ,Stack *  );
void Pop          (StackEntry *, Stack* );
int  StackEmpty   (Stack *);
int  StackFull    (Stack *);
void ClearStack   (Stack *ps);
int  StackSize    (Stack *ps);
void StackTop     (StackEntry *, Stack *);
void TraverseStack(Stack *ps, void (*Disply)(StackEntry));




#endif