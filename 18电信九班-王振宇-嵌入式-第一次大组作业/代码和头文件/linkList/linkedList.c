#include "../head/linkedList.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
	Status beInit = SUCCESS;
	*L = (LinkedList)malloc(sizeof(LNode));
	if ( *L == NULL )
		beInit = 0;
	else
		(*L)->next = NULL;
	return beInit;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
	LinkedList p;
	while ( *L ) {
		p = *L;
		*L = (*L)->next;
		free(p);
	}
	p = NULL;
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status 
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
	Status beInsert = SUCCESS;
	if ( p != NULL && q != NULL ) {
		q->next = p->next;
		p->next = q;
	} else {
		beInsert = ERROR;
	}
	return beInsert;
}

/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
	Status beDelet = SUCCESS;
	if ( p != NULL && p->next != NULL ) {
		LinkedList q = p->next;
		p->next = q->next;
		*e = q->data;
		free(q);
	} else {
		beDelet = ERROR;
	}
	return beDelet;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit 
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
	L = L->next;
	while ( L ) {
		(*visit)(L->data);
		L = L->next;
	}
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e 
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
	Status isFound = ERROR;
	if ( L->next ) {
		L = L->next;
		while ( L != NULL && L->data != e ) {
			L = L->next;
		}
		if ( L )
			isFound = SUCCESS;
	}
	
	return isFound;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list 
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
	Status beReverse = SUCCESS;
	LinkedList p, q;
	p = (*L)->next;
	if ( (*L)->next ) {
		while ( p->next ) {
			q = p->next;
			p->next = q->next;
			q->next = (*L)->next;
			(*L)->next = q;
		}
	} else {
		beReverse = ERROR;
	}
	return beReverse;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
	Status isLoop = ERROR;
	LinkedList p, q;
	p = q = L;
	while ( q->next != NULL && q->next->next != NULL ) {
		p = p->next;
		q = q->next->next;
		if ( p == q ){
			isLoop = SUCCESS;
			break;
		}	
	}
	return isLoop;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish 
 */
LNode* ReverseEvenList(LinkedList *L) {
	LinkedList p, q, r;
	p = *L;
	while ( p->next != 0 && p->next->next != 0 ) {
		q = p->next;
		r = q->next;
		q->next = r->next;
		r->next = q;
		p->next = r;
		p = q;
	}
	return *L;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish 
 */
LNode* FindMidNode(LinkedList *L) {
	LinkedList p, q;
	if ( (*L)->next ) {
		p = q = *L;
		while ( q != NULL && q->next != NULL ) {
			p = p->next;
			q = q->next->next;
		}
	} else {
		p = NULL;
	}
	return p;
}

void PrintData(int data) {
	printf("%d ", data);
}

LinkedList SearchData(LinkedList L, ElemType e) {
	LinkedList inPlace = NULL;
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
