#ifndef STACK_H
#define STACK_H
#define MAX_SIZE 100


typedef int StackEntry;

typedef struct Stack {
	
	int top;
	StackEntry entry[MAX_SIZE];
	
}Stack;

void CreateStack  (Stack *);
void Push         (StackEntry ,Stack *  );
void Pop          (StackEntry *, Stack* );
int  StackEmpty   (Stack *);
int  StackFull    (Stack *);
int  StackSize    (Stack *);
void StackTop     (StackEntry *, Stack *);
void ClearStack   (Stack *);
void TraverseStack(Stack *, void (*Disply)(StackEntry) );





#endif