#ifndef List_H
#define List_H

#define MAXSIZE   200

typedef int ListEntry;


typedef struct
{
	ListEntry entry[MAXSIZE];
	int size;
} List;


void CreatList   (List*);
int  ListEmpty   (List*);
int  ListFull    (List*);
int  ListSize    (List*);
void DestroyList (List*);
void InsertList  (int, ListEntry , List*);
void DeleteList  (int, ListEntry*, List*);
void ReplaceList (int, ListEntry , List*);
void RetrieveList(int, ListEntry*, List* );
void TraverseList(List*, void(*pf)(ListEntry));



#endif