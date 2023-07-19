#ifndef List_H
#define List_H

#define MAXSIZE   200

typedef int ListEntry;

typedef struct listnode
{
	ListEntry entry;
	struct listnode *next;
} ListNode;

typedef struct list
{
	ListNode *Head, *current;
	int size;
	int currentPos;
} List;


// error state 


void CreatList   (List*);
int  ListEmpty   (List*);
int  ListFull    (List*);
int  ListSize    (List*);
void DestroyList (List*);
int InsertList  (int, ListEntry , List*);
void DeleteList  (int, ListEntry*, List*);
void ReplaceList (int, ListEntry , List*);
void RetrieveList(int, ListEntry*, List* );
void TraverseList(List*, void(*pf)(ListEntry));



#endif