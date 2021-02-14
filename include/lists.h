/*
 * lists.h
 * 
 * Created: 02.01.2021 11:58:18
 * Author: ThePetrovich
 */


#ifndef SCHED_COMMON_H_
#define SCHED_COMMON_H_

#include <stddef.h>
#include <stdint.h>

#define common_LISTITEM_STRUCT_SIZE (sizeof(struct sListItemStruct_t)

typedef struct sLinkedListStruct_t
{
	sLinkedListItem_t* head;
	sLinkedListItem_t* tail;
} sLinkedList_t;

typedef struct sListItemStruct_t
{
	sLinkedList_t* list;
	sLinkedListItem_t* next;
	sLinkedListItem_t* prev;
	void* data;
} sLinkedListItem_t;

void common_listAddBack(sLinkedList_t* list, sLinkedListItem_t* item);
void common_listAddFront(sLinkedList_t* list, sLinkedListItem_t* item);
void common_listDropBack(sLinkedList_t* list);
void common_listDropFront(sLinkedList_t* list);
void common_listDeleteAny(sLinkedList_t* list, sLinkedListItem_t* item);

#endif