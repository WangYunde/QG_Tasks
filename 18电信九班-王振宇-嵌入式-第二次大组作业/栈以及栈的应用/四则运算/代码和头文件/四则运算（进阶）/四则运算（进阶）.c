#include "四则运算（进阶）.h"
#include <stdio.h>
#include <stdlib.h>

//链栈(基于链表的)
Status initLStack(LinkStack *s)   //初始化
{
	s->top = NULL;//(StackNode*)malloc(sizeof(StackNode));
	s->count = 0;
	return SUCCESS;
}

Status getTopLStack(LinkStack *s, ElemType *e)  //得到栈顶元素
{
	if (s->count < 1)
		return ERROR;
	*e = s->top->data;
	return SUCCESS;
}

Status pushLStack(LinkStack *s, ElemType data)   //入栈
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

Status popLStack(LinkStack *s, ElemType *data)   //出栈
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

Status clearLStack(LinkStack *s)   //清空栈
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

Status DinitLStack(DLinkStack *s)   //D初始化
{
	s->top = NULL;//(DStackNode*)malloc(sizeof(DStackNode));
	s->count = 0;
	return SUCCESS;
}

Status DgetTopLStack(DLinkStack *s, double *e)  //D得到栈顶元素
{
	if (s->count < 1)
		return ERROR;
	*e = s->top->data;
	return SUCCESS;
}

Status DpushLStack(DLinkStack *s, double data)   //D入栈
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

Status DpopLStack(DLinkStack *s, double *data)   //D出栈
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

Status DclearLStack(DLinkStack *s)   //D清空栈
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

int compare(LinkStack *s, char c)   //运算符优先级比较
{	//返回1替换(new<=old)
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

double operate(double x, double y, char c)   //二元计算
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

int calculate(DLinkStack *Num, double n, char c)   //后缀式计算
{
	if (c == 0) { //传入数值时
		DpushLStack(Num, n);
	}
	else { //传入运算符时
		double DtopNum1, DtopNum2;
		double result;
		DpopLStack(Num, &DtopNum1);
		DpopLStack(Num, &DtopNum2);
		result = operate(DtopNum2, DtopNum1, c);
		DpushLStack(Num, result);
	}
	return SUCCESS;
}