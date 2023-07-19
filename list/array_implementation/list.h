#ifndef List_H
#define List_H

#define MAXSIZE   200

typedef int ListEntry;


typedef struct
{
	ListEntry entry[MAXSIZE];
	int size;
} List;


// error state 

typedef enum
{
	ES_NULL_POINTER = -1,
	ES_OK
}ES_t;

ES_t CreatList   (List*);
int  ListEmpty   (List*);
int  ListFull    (List*);
int  ListSize    (List*);
ES_t DestroyList (List*);
ES_t InsertList  (int, ListEntry , List*);
ES_t DeleteList  (int, ListEntry*, List*);
ES_t ReplaceList (int, ListEntry , List*);
ES_t RetrieveList(int, ListEntry*, List* );
ES_t TraverseList(List*, void(*pf)(ListEntry));



#endif