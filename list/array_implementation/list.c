#include <stdlib.h>
#include "list.h"


/* CreatList: initialize the list to be empty.
Pre: None.
Post: The list has been initialized to be empty. */

ES_t CreatList   (List* list) // O(1)
{
	if(list != NULL){
		list->size = 0;
		return ES_OK;
	}
	else return ES_NULL_POINTER;
}

/* ListEmpty: returns non-zero if the list is empty.
Pre: The list exists and it has been initialized.
Post: Return non-zero if the list is empty; return zero, otherwise. */

int ListEmpty   (List* list) // O(1)
{
	if(list != NULL) return !(list->size);
    else return ES_NULL_POINTER;

}

/* ListFull: returns non-zero if the list is full.
Pre: The list exists and it has been initialized.
Post: Return non-zero if the list is full; return zero, otherwise. */

int ListFull    (List* list) // O(1)
{
	if(list != NULL) return (list->size == MAXSIZE);
    else return ES_NULL_POINTER;
}

/*
precondition: The list exists and it has been initialized.
postcondition: The function returns the number of entries in the list.
*/

int ListSize    (List* list) // O(1)
{
	if(list != NULL) return list->size;
	else return ES_NULL_POINTER;

}


/*
precondition: The list exists.
postcondition: set the size to zero.
*/

ES_t DestroyList (List* list) // O(1) 
{
	if(list != NULL){
		list->size = 0;
		return ES_OK;
	}
	else return ES_NULL_POINTER;
}

/* InsertList: Insert an item into the list.
Pre:  1- The list exists and it is not full.
	  2- 0 <= p <= size.
Post: 1- The argument item has been inserted at the position p of the list.
	  2- all other elements are incremented by 1.
	  3- size incremented by 1.
 */

ES_t InsertList  (int p, ListEntry e, List* list) // O(n)
{
		if(list != NULL)
		{
			for(int i = (list->size)-1 ; i >= p ; --i)
				list->entry[i+1] = list->entry[i];
			list->entry[p] = e;
			list->size++;
		    return ES_OK;
		}
		else return ES_NULL_POINTER;
}


/* DeleteList: Delete the item at position p from the list.
Pre: The list exists and it is not empty.
Post: The item at the position p of list has been removed and returned in *e. */


ES_t DeleteList  (int p, ListEntry* e, List* list) // // O(n)
{
	if( (list != NULL) && (e != NULL) ){
		*e = list->entry[p];
		
		for(int i = p+1 ; i < (list->size) ; ++i)
			list->entry[i-1] = list->entry[i];
		list->size--;
		return ES_OK;
	}
	else return ES_NULL_POINTER;
}

/*
precondition: 1- The list exists.
	          2- 0 <= p <= size.
postcondition: The item at the p position of the list is replaced with (e)
*/

ES_t ReplaceList (int p, ListEntry e, List* list)
{
	if(list != NULL) 
	{
		list->entry[p] = e;
		return ES_OK;
	}
	else return ES_NULL_POINTER;
}

/*
precondition: 1- The list exists.
	          2- 0 <= p <= size.
postcondition: The item at the p position of the list is returned (in *e) without

being removed; the list remains unchanged..
*/

ES_t RetrieveList(int p, ListEntry* e, List* list)
{
	if( (list != NULL) && (e != NULL) )
	{
		*e = list->entry[p];
			return ES_OK;
	}
	else return ES_NULL_POINTER;
}


/*
precondition: The list exists.
postcondition: Display all elements of the list.
*/


ES_t TraverseList(List* list, void(*pf)(ListEntry))
{
	if(list != NULL) 
	{
		for(int i = 0 ; i < (list->size) ; ++i)
			(*pf)(list->entry[i]);
	}
	else return ES_NULL_POINTER;

}