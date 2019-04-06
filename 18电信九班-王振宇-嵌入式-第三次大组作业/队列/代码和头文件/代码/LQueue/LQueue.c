#include "../../头文件/LQueue.h"
#include <stdio.h>
#include <stdlib.h>

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

Status IsEmptyLQueue(const LQueue* Q)
{
	if (Q->rear == Q->front)
		return 1;
	return 0;
}

Status GetHeadLQueue(LQueue* Q, void* e)
{
	if (Q->rear == Q->front)
		return 0;
	//*(char*)e = *(char*)(Q->front->next->data);
	printf("\n队首数据为%s\n", (char*)(Q->front->next->data));
	return 1;
}

int LengthLQueue(LQueue* Q)
{
	Node* p = Q->front->next;
	int i = 0;
	while (p) {
		i++;
		p = p->next;
	}
	return i;
}

Status EnLQueue(LQueue* Q, void* data)
{
	Node* p = (Node*)malloc(sizeof(Node));
	if (!p)
		return 0;
	p->data = data;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	Q->length++;
	return 1;
}

Status DeLQueue(LQueue* Q)
{
	if (Q->front == Q->rear)
		return 0;
	Node* p = Q->front->next;
	Q->front->next = p->next;
	if (Q->rear == p)
		Q->rear = Q->front;
	free(p);
	Q->length--;
	return 1;
}

void ClearLQueue(LQueue* Q)
{
	Q->rear = Q->front->next;
	Node* p = Q->rear;
	while (p) {
		p = p->next;
		free(Q->rear);
		Q->rear = p;
	}
	Q->rear = Q->front;
	Q->rear->next = NULL;
	Q->length = 0;
	return 1;
}

Status TraverseLQueue(LQueue Q, void (*foo)(void* q))
{
	if (Q.length == 0)
		printf("（空）");
	while (Q.front != Q.rear) {
		Q.front = Q.front->next;
		(*foo)(Q.front);
	}
	printf("    （回车以继续）\n");
}

void LPrint(void* q)
{
	char* s = ((Node*)q)->data;
	printf(" %s ", s);
	/*Node N = *(Node*)q;
	for (int i = 0; i < 1000; i++) {
		if (*((char*)N.data + i) == '\0')
			break;
		printf("%c", *((char*)N.data + i));
	}*/
}

int judgeAndEn(LQueue* Q, char* s)
{
	char c = getchar();
	int isString = 0;
	int isDouble = 0;
	int i;
	for (i = 0; i < 1000 && c != '\n'; i++) {
		if (i > 0 && c == '.')
			isDouble++;
		else if (c < 48 || c>57)
			isString = 1;
		s[i] = c;
		c = getchar();
	}
	if (!i)
		return 0;
	s[i] = '\0';
	//printf("\n%s", s);
	int beEn = EnLQueue(Q, s);
	if (isString || isDouble > 1) {
		printf("->您输入了一个字符串\n");
		Q->rear->dataType = 2;
	}
	else if (isDouble == 1) {
		printf("->您输入了一个浮点型\n");
		Q->rear->dataType = 1;
	}
	else if (i > 0) {
		printf("->您输入了一个整型\n");
		Q->rear->dataType = 0;
	}
	return beEn;
}