#ifndef LIST_H
#define LIST_H

#include "../global.h"



typedef  struct list *Plist;


int CreateList(Plist *pl);

int Insert  (int ind, void* , Plist , int);

void Delete (int ind, void* , Plist , int);

void Retrieve_List(int ind, void* , Plist , int);

void Replace_List (int ind, void* , Plist , int);

int ListSize(Plist);

int ListEmpty(Plist);

int ListFull(Plist);

void DestroyList (Plist);

void TraverseList(Plist, void(*Display)(void*));

#endif
