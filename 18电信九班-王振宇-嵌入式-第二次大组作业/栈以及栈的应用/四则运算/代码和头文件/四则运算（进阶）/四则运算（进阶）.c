#include "�������㣨���ף�.h"
#include <stdio.h>
#include <stdlib.h>

//��ջ(���������)
Status initLStack(LinkStack *s)   //��ʼ��
{
	s->top = NULL;//(StackNode*)malloc(sizeof(StackNode));
	s->count = 0;
	return SUCCESS;
}

Status getTopLStack(LinkStack *s, ElemType *e)  //�õ�ջ��Ԫ��
{
	if (s->count < 1)
		return ERROR;
	*e = s->top->data;
	return SUCCESS;
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
	LinkStackPtr oldTop = s->top;
	*data = oldTop->data;
	s->top = oldTop->next;
	s->count--;
	free(oldTop);
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

Status DinitLStack(DLinkStack *s)   //D��ʼ��
{
	s->top = NULL;//(DStackNode*)malloc(sizeof(DStackNode));
	s->count = 0;
	return SUCCESS;
}

Status DgetTopLStack(DLinkStack *s, double *e)  //D�õ�ջ��Ԫ��
{
	if (s->count < 1)
		return ERROR;
	*e = s->top->data;
	return SUCCESS;
}

Status DpushLStack(DLinkStack *s, double data)   //D��ջ
{
	DLinkStackPtr newTop = (DStackNode*)malloc(sizeof(DStackNode));
	if (!newTop)
		return ERROR;
	newTop->next = s->top;
	newTop->data = data;
	s->top = newTop;
	s->count++;
	return SUCCESS;
}

Status DpopLStack(DLinkStack *s, double *data)   //D��ջ
{
	if (s->count < 1)
		return ERROR;
	DLinkStackPtr oldTop = s->top;
	*data = oldTop->data;
	s->top = oldTop->next;
	s->count--;
	free(oldTop);
	return SUCCESS;
}

Status DclearLStack(DLinkStack *s)   //D���ջ
{
	DLinkStackPtr p;
	while (s->top) {
		p = s->top;
		s->top = s->top->next;
		s->count--;
		free(p);
	}
	return SUCCESS;
}

int compare(LinkStack *s, char c)   //��������ȼ��Ƚ�
{	//����1�滻(new<=old)
	int topOprt;
	getTopLStack(s, &topOprt);
	(char)topOprt;
	if (topOprt == '#' || topOprt == '(')
		return 0;
	if (topOprt == '+' || topOprt == '-')
		if (c == '*' || c == '/')
			return 0;
	return 1;
}

double operate(double x, double y, char c)   //��Ԫ����
{
	if (c == '+')
		return x + y;
	else if (c == '-')
		return x - y;
	else if (c == '*')
		return x * y;
	else if (c == '/')
		return x / y;
	else
		printf("ERROR!");
}

int calculate(DLinkStack *Num, double n, char c)   //��׺ʽ����
{
	if (c == 0) { //������ֵʱ
		DpushLStack(Num, n);
	}
	else { //���������ʱ
		double DtopNum1, DtopNum2;
		double result;
		DpopLStack(Num, &DtopNum1);
		DpopLStack(Num, &DtopNum2);
		result = operate(DtopNum2, DtopNum1, c);
		DpushLStack(Num, result);
	}
	return SUCCESS;
}