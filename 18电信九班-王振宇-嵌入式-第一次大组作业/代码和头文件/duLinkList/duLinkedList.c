#include "../head/duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
	Status beInit = SUCCESS;
	*L = (DuLinkedList)malloc(sizeof(DuLNode));
	if ( *L == NULL )
		beInit = 0;
	else
		(*L)->next = NULL;
		(*L)->prior = NULL;
	return beInit;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
	DuLinkedList p;
	while ( *L ) {
		p = *L;
		*L = (*L)->next;
		free(p);
	}
	p = NULL;
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
	Status beInsert = SUCCESS;
	if ( p != NULL && q != NULL ) {
		q->prior = p->prior;
		p->prior = q;
		q->next = p;
		if ( q->prior )
			q->prior->next = q;
	} else {
		beInsert = ERROR;
	}
	return beInsert;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
	Status beInsert = SUCCESS;
	if ( p != NULL && q != NULL ) {
		q->next = p->next;
		p->next = q;
		q->prior = p;
		if ( q->next )
			q->next->prior = q;
	} else {
		beInsert = ERROR;
	}
	return beInsert;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
	Status beDelet = SUCCESS;
	if ( p != NULL && p->next != NULL ) {
		DuLinkedList q = p->next;
		p->next = q->next;
		if ( p->next )
			p->next->prior = p;
		*e = q->data;
		free(q);
	} else {
		beDelet = ERROR;
	}
	return beDelet;
}
 
/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit 
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
	L = L->next;
	while ( L ) {
		(*visit)(L->data);
		L = L->next;
	}
}

void PrintData(int data) {
	printf("%d ", data);
}

DuLinkedList SearchData(DuLinkedList L, ElemType e) {
	DuLinkedList inPlace = NULL;
	if ( L->next ) {
		L = L->next;
		while ( L != NULL && L->data != e ) {
			L = L->next;
		}
		if ( L )
			inPlace = L;
	}
	return inPlace;
}
