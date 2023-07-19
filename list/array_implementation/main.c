#include <stdio.h>
#include "list.h"

void Display(ListEntry x)
{
	printf("%d ",x);
}

int main()
{
	ListEntry e = 7;
	List l;
	CreatList(&l);
	if(!ListFull(&l))
	{
		InsertList(0,1,&l);
		InsertList(1,6,&l);
		InsertList(2,5,&l);
		InsertList(0,4,&l);
	}
	printf("\nlist befor delete first element:\n\n ");
	TraverseList(&l,&Display);


	if(!ListEmpty(&l))
	{
		DeleteList(1,&e,&l);
	}
	printf("\nlist after delete first element:\n\n ");
	TraverseList(&l,&Display);
	printf("\ndeleted element: %d ",e);
	printf("\nsize of list = %d\n\n ",ListSize(&l));
	printf("\nlist befor replace last element:\n");
	TraverseList(&l,&Display);
	ReplaceList(2,9,&l);
	printf("\nlist after replace last element:\n\n ");
	TraverseList(&l,&Display);
	RetrieveList(2,&e,&l);
	printf("\nlast element: %d ",e);
	DestroyList (&l);
	printf("\nlist destroyed \n");
	printf("\nsize of list = %d\n\n ",ListSize(&l));

	TraverseList(&l,&Display);







	return 0;
}