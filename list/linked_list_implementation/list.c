#include <stdlib.h>
#include "list.h"


/* CreatList: initialize the list to be empty.
Pre: None.
Post: The list has been initialized to be empty. */

void CreatList   (List* list) // O(1)
{

	list->Head = NULL;
	list->current = NULL;
	list->size = 0;
	list->currentPos = 0;

}

/* ListEmpty: returns non-zero if the list is empty.
Pre: The list exists and it has been initialized.
Post: Return non-zero if the list is empty; return zero, otherwise. */

int ListEmpty   (List* list) // O(1)
{
	return !(list->size);
}

/* ListFull: returns non-zero if the list is full.
Pre: The list exists and it has been initialized.
Post: Return non-zero if the list is full; return zero, otherwise. */

int ListFull    (List* list) // O(1)
{
	return 0;
}

/*
precondition: The list exists and it has been initialized.
postcondition: The function returns the number of entries in the list.
*/

int ListSize    (List* list) // O(1)
{
	return list->size;
}


/*
precondition: The list exists.
postcondition: set the size to zero.
*/

void DestroyList (List* list) //O(1)
{
	ListNode* temp = NULL;
	
	while(list->Head)
	{
		temp = list->Head->next;
		free(list->Head);
		list->Head = temp;
	}
	list->size = 0;
}

/* InsertList: Insert an item into the list.
Pre:  1- The list exists and it is not full.
	  2- 0 <= p <= size.
Post: 1- The argument item has been inserted at the position p of the list.
	  2- all other elements are incremented by 1.
	  3- size incremented by 1.
 */

int InsertList  (int p, ListEntry e, List* list) // O(n)
{
	ListNode* q = (ListNode*)malloc(sizeof(ListNode));
	if(q)
	{
		q->entry = e;
		q->next = NULL;
		if( p == 0 )
		{
			q->next = list->Head;
			list->Head = q;
			list->current = q;
			list->currentPos = 0;
		}
		else
		{ 
				if( p <= list->currentPos)
			{
				list->currentPos =0;
				list->current = list->Head;
			}
			for( ; list->currentPos < p-1 ; list->currentPos++) list->current = list->current->next;
			
			q->next = list->current->next ;
			
			list->current->next = q;
			
		}
		list->size++;
		return 1;
	}
	else return 0;
}


/* DeleteList: Delete the item at position p from the list.
Pre: The list exists and it is not empty.
Post: The item at the position p of list has been removed and returned in *e. */


void DeleteList  (int p, ListEntry* e, List* list) // // O(n)
{
	ListNode* q ;

	if( p == 0 )
	{
		*e = list->Head->entry;
		list->current = list->Head->next;
		free(list->Head);
		list->Head = list->current;
		list->currentPos=0;
	}
	else
	{ 
		if( p <= list->currentPos)
		{
			list->currentPos =0;
			list->current = list->Head;
		}
		for( ; list->currentPos < p-1 ; list->currentPos++) list->current = list->current->next;
		
		q = list->current->next->next ;
		*e = list->current->next->entry;
		free(list->current->next);
		list->current->next = q;
	}
	list->size--;
}

/*
precondition: 1- The list exists.
	          2- 0 <= p <= size.
postcondition: The item at the p position of the list is replaced with (e)
*/

void ReplaceList (int p, ListEntry e, List* list)
{

	if( p <= list->currentPos)
	{
		list->currentPos =0;
		list->current = list->Head;
	}
	for( ; list->currentPos < p ; list->currentPos++) list->current = list->current->next;
	list->current->entry = e;
}

/*
precondition: 1- The list exists.  2- 0 <= p <= size.
postcondition: The item at the p position of the list is returned (in *e) without
being removed; the list remains unchanged..
*/

void RetrieveList(int p, ListEntry* e, List* list)
{
	if( p <= list->currentPos)
	{
		list->currentPos =0;
		list->current = list->Head;
	}
	for( ; list->currentPos < p ; list->currentPos++) list->current = list->current->next;
	*e = list->current->entry;	
}


/*
precondition: The list exists.
postcondition: Display all elements of the list.
*/


void TraverseList(List* list, void(*pf)(ListEntry))
{
	ListNode* temp = list->Head;
	for(int i = 0 ; i < (list->size) ; ++i)
	{
		(*pf)(temp->entry);
		temp = temp->next;
	}
}