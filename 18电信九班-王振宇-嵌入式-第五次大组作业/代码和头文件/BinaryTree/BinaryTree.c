#include "../head/BinaryTree.h"

Status InitBiTree(BiTree* T)
{
	*T = malloc(sizeof(BiTNode));
	if (!T)
		return ERROR;
	(*T)->data = '#';
	(*T)->lchild = (*T)->rchild = NULL;
}

Status DestroyBiTree(BiTree T)
{
	if (!T) {
		return ERROR;
	}
	BiTree p = T;
	DestroyBiTree(T->lchild);
	DestroyBiTree(T->rchild);
	free(p);
	return SUCCESS;
}

Status CreateBiTree(BiTree* T, char* definition)
{
	TElemType ch;
	ch = nextChar(definition);
	(*T) = malloc(sizeof(BiTNode));
	(*T)->data = ch;
	(*T)->lchild = (*T)->rchild = NULL;
	if (ch > 57 || ch < 48) {
		CreateBiTree(&(*T)->lchild, definition);
		CreateBiTree(&(*T)->rchild, definition);
	}
}

Status CreateBiTree0(BiTree* T)
{
	TElemType ch;
	ch = getchar();
	if (ch == '\n' || ch == '#') {
		(*T) = NULL;
	}
	else {
		(*T) = malloc(sizeof(BiTNode));
		(*T)->data = ch;
		CreateBiTree0(&(*T)->lchild);
		CreateBiTree0(&(*T)->rchild);
	}
	return SUCCESS;
}

Status PreOrderTraverse(BiTree T, Status(*visit)(TElemType e))
{
	if (!T) {
		return ERROR;
	}
	(*visit)(T->data);
	PreOrderTraverse(T->lchild, *visit);
	PreOrderTraverse(T->rchild, *visit);
	return SUCCESS;
}

Status InOrderTraverse(BiTree T, Status(*visit)(TElemType e))
{
	if (!T) {
		return ERROR;
	}
	InOrderTraverse(T->lchild, *visit);
	(*visit)(T->data);
	InOrderTraverse(T->rchild, *visit);
	return SUCCESS;
}

Status PostOrderTraverse(BiTree T, Status(*visit)(TElemType e))
{
	if (!T) {
		return ERROR;
	}
	PostOrderTraverse(T->lchild, *visit);
	PostOrderTraverse(T->rchild, *visit);
	(*visit)(T->data);
	return SUCCESS;
}

Status LevelOrderTraverse(BiTree T, Status(*visit)(TElemType e))
{
	LQueue Q;
	Q.length = -1;
	InitLQueue(&Q);
	EnLQueue(&Q, T);
	BiTree e = malloc(sizeof(BiTNode));
	while (Q.length) {
		DeLQueue(&Q, &e);
		(*visit)(e->data);
		if (e->lchild)
			EnLQueue(&Q, e->lchild);
		if (e->rchild)
			EnLQueue(&Q, e->rchild);
	}
	if (Q.length > -1)
		DestoryLQueue(&Q);
}

Status Print(TElemType e)
{
	printf("%c ", e);
	return SUCCESS;
}

int Value(BiTree* T)
{
	if ((*T)->lchild) {
		(*T)->data = calculate(Value(&((*T)->lchild)), Value(&((*T)->rchild)), (*T)->data);
		(*T)->lchild = (*T)->rchild = NULL;
	}
	return (*T)->data;
}

char nextChar(char* definition)
{
	static int i = 0;
	if (definition == NULL) {
		i = 0;
		return 1;
	}
	while (definition[i] == ' ' || definition[i] == '\0') {
		i++;
	}
	return definition[i++];
}

int calculate(char x, char y, char c)
{
	if (c == '+')
		return x + y - '0';
	else if (c == '-')
		return x - y + '0';
	else if (c == '*')
		return (x - '0') * (y - '0') + '0';
	else if (c == '/')
		return (x - '0') / (y - '0') + '0';
	else
		printf("ERROR!");
}

void InitLQueue(LQueue* Q)
{
	Q->front = Q->rear = (Node*)malloc(sizeof(Node));
	Q->rear->next = NULL;
	Q->length = 0;
}

void DestoryLQueue(LQueue* Q)
{
	while (Q->front) {
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
	Q->length = -1;
	return 1;
}

Status EnLQueue(LQueue* Q, BiTree T)
{
	Node* p = (Node*)malloc(sizeof(Node));
	if (!p)
		return 0;
	p->data = T;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	Q->length++;
	return 1;
}

Status DeLQueue(LQueue* Q, BiTree* e)
{
	if (Q->front == Q->rear)
		return 0;
	*e = Q->front->next->data;
	Node* p = Q->front->next;
	Q->front->next = p->next;
	if (Q->rear == p)
		Q->rear = Q->front;
	free(p);
	Q->length--;
	return 1;
}