#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

#ifdef LIMITED_MEMORY

typedef struct stacknode{
    void *entry;
    struct stacknode *next;
}StackNode;


struct stack{
    StackNode *top;
    int size;
};


void CreateStack(Pstack *pps) // O(1)
{
    *pps = (struct stack *) malloc(sizeof (struct stack));
    (*pps)->top = NULL;
    (*pps)->size = 0;
}



int Push_Stack(void* pe, Pstack ps, int z){   // O(1)

	StackNode *pn = (StackNode *)malloc(sizeof(StackNode));
	if(pn != NULL)
	{
        memcpy(&pn->entry, pe, z);
        pn->next  = ps->top;
        ps->top   = pn;
        ps->size++;
        return 1;
	}
	else return 0;
}


void Pop_Stack(void* pe, Pstack ps, int z) {   // O(1)
    StackNode *pn;
    memcpy(pe, &ps->top->entry, z);
    pn = ps->top;
    ps->top = ps->top->next;
    free(pn);
    ps->size--;
}


int StackEmpty(Pstack ps){   // O(1)

	return !ps->top;
}


int StackFull(Pstack ps){    // O(1)

	return 0;
}


void ClearStack(Pstack ps){  // o(n)

	StackNode *pn = ps->top;
	while(pn){
		pn = pn->next;
		free(ps->top);
		ps->top = pn;
	}
	ps->size = 0;
}


void TraverseStack(Pstack ps, void (*pf)(void*)){

    StackNode *pn;
	for(pn = ps->top ; pn; pn = pn->next)
		(*pf)(&pn->entry);
}


int StackSize(Pstack ps)
{  // O(1)

	return ps->size;
}


void StackTop(void* p_top, Pstack ps, int z)
{
	memcpy(p_top, &ps->top->entry, z);
}

#else

struct stack{

    int top;
    void* items[MAX_STACK_SIZE];
};


void CreateStack(Pstack *pps)
{
    *pps = (struct stack *)malloc(sizeof(struct stack));
    (*pps)->top = 0;
}


int Push_Stack(void *pe, Pstack ps, int z){
    void* ptr = (void *)malloc(z);
    memcpy(ptr, pe, z);
    ps->items[ps->top++] = ptr;
    return 1;
}


int StackFull(Pstack ps){

    return ps->top == MAX_STACK_SIZE;
}


void Pop_Stack(void* pe, Pstack ps, int z)
{
    memcpy(pe, ps->items[--ps->top], z);
}


int StackEmpty(Pstack ps){

    return !ps->top;
}


int StackSize(Pstack ps){

    return ps->top;
}


void ClearStack(Pstack ps){

    ps->top = 0;
}


void StackTop(void* p_top, Pstack ps, int z){

    memcpy(p_top, &ps->items[ps->top - 1], z);
}


void TraverseStack(Pstack ps, void (*pf)(void*)){

    for(int i = ps->top - 1; i >= 0; --i)
        (*pf)(ps->items[i]);
}


#endif