#include "../../头文件/AQueue.h"
#include <stdio.h>
#include <stdlib.h>
/*
typedef struct Aqueue
{
	void* data[MAXQUEUE];      //数据域
	int front;
	int rear;
	size_t length;        //队列长度
} AQueue;*/

void InitAQueue(AQueue* Q)
{
	switch (dataType) {
	case 0:
		dataSize = sizeof(int);
		break;
	case 1:
		dataSize = sizeof(double);
		break;
	case 2:
		dataSize = sizeof(char);
		break;
	default:
		printf("ERROR!");
		break;
	}
	Q->rear = Q->front = 0;
	Q->length = 0;
}

void DestoryAQueue(AQueue* Q)
{
	Q->front = Q->rear = 0;
	Q->length = -1;
}

Status IsFullAQueue(const AQueue* Q)
{
	if (Q->length < MAXQUEUE)
		return 0;
	return 1;
}

Status IsEmptyAQueue(const AQueue* Q)
{
	if (Q->length)
		return 0;
	return 1;
}

Status GetHeadAQueue(AQueue Q, void** e)
{
	if (Q.rear == Q.front)
		return 0;
	*e = Q.data[Q.front];
	return 1;
}

int LengthAQueue(AQueue* Q)
{
	return Q->length;
}

Status EnAQueue(AQueue* Q, void* data)
{
	if (Q->length == MAXQUEUE)
		return 0;
	Q->data[Q->rear] = data;
	Q->rear = (Q->rear + 1) % 100;
	Q->length++;
	return 1;
}

Status DeAQueue(AQueue* Q)
{
	if (Q->rear == Q->front)
		return 0;
	Q->front = (Q->front + 1) % 100;
	Q->length--;
	return 1;
}

void ClearAQueue(AQueue* Q)
{
	Q->front = Q->rear = 0;
	Q->length = 0;
}

Status TraverseAQueue(AQueue Q, void (*foo)(void* q))
{
	if (Q.length == 0)
		printf("（空）");
	while (Q.front != Q.rear) {
		(*foo)(Q.data[Q.front]);
		Q.front = (Q.front + 1) % 100;
	}
	printf("    （回车以继续）\n");
}

void APrint(void* q)
{
	switch (dataType) {
	case 0:
		printf(" %d", *(int*)q);
		break;
	case 1:
		printf(" %f", *(double*)q);
		break;
	case 2:
		printf(" %c", *(char*)q);
		break;
	}
}