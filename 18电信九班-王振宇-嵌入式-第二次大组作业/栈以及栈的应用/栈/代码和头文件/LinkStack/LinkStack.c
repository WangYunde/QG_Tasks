#include "../head/LinkStack.h"
#include <stdio.h>
#include <stdlib.h>

//��ջ(���������)
Status initLStack(LinkStack *s)   //��ʼ��
{
	s->top = NULL;//(StackNode*)malloc(sizeof(StackNode));
	s->count = 0;
	return SUCCESS;
}

Status isEmptyLStack(LinkStack *s)  //�ж���ջ�Ƿ�Ϊ��
{
	if(s->count > 0)
		return ERROR;
	return SUCCESS;
}

Status getTopLStack(LinkStack *s, ElemType *e)  //�õ�ջ��Ԫ��
{
	if (s->count < 1)
		return ERROR;
	*e = s->top->data;
	return SUCCESS;
}

Status clearLStack(LinkStack *s)   //���ջ
{
	LinkStackPtr p;
	while (s->top) {
		p = s->top;
		s->top = s->top->next;
		s->count--;
		free(p);
	}
	return SUCCESS;
}

Status destroyLStack(LinkStack *s)   //����ջ
{
	LinkStackPtr p;
	while (s->top) {
		p = s->top;
		s->top = s->top->next;
		s->count--;
		free(p);
	}
	s->count = -1;
	return SUCCESS;
}

Status LStackLength(LinkStack *s, int *length)    //���ջ����
{
	if (s->count < 0)
		return ERROR;
	return s->count;
}

Status pushLStack(LinkStack *s, ElemType data)   //��ջ
{
	LinkStackPtr newTop = (StackNode*)malloc(sizeof(StackNode));
	if (!newTop)
		return ERROR;
	newTop->next = s->top;
	newTop->data = data;
	s->top = newTop;
	s->count++;
	return SUCCESS;
}

Status popLStack(LinkStack *s, ElemType *data)   //��ջ
{
	if (s->count < 1)
		return ERROR;
	LinkStackPtr oldTop= s->top;
	*data = oldTop->data;
	s->top = oldTop->next;
	s->count--;
	free(oldTop);
	return SUCCESS;
}

Status StarkTraverse(LinkStack *s)   //����ջ
{
	if (s->count < 0)
		return ERROR;
	printf("\n                ��        ��\n");
	LinkStackPtr p = s->top;
	while (p) {
		printf("                ��������������������\n");
		printf("                ��%6d  ��\n", p->data);
		p = p->next;
	}
	printf("                ��������������������\n");
}