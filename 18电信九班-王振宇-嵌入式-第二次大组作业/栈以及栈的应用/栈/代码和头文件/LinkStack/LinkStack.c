#include "../head/LinkStack.h"
#include <stdio.h>
#include <stdlib.h>

//链栈(基于链表的)
Status initLStack(LinkStack *s)   //初始化
{
	s->top = NULL;//(StackNode*)malloc(sizeof(StackNode));
	s->count = 0;
	return SUCCESS;
}

Status isEmptyLStack(LinkStack *s)  //判断链栈是否为空
{
	if(s->count > 0)
		return ERROR;
	return SUCCESS;
}

Status getTopLStack(LinkStack *s, ElemType *e)  //得到栈顶元素
{
	if (s->count < 1)
		return ERROR;
	*e = s->top->data;
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

Status destroyLStack(LinkStack *s)   //销毁栈
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

Status LStackLength(LinkStack *s, int *length)    //检测栈长度
{
	if (s->count < 0)
		return ERROR;
	return s->count;
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
	LinkStackPtr oldTop= s->top;
	*data = oldTop->data;
	s->top = oldTop->next;
	s->count--;
	free(oldTop);
	return SUCCESS;
}

Status StarkTraverse(LinkStack *s)   //遍历栈
{
	if (s->count < 0)
		return ERROR;
	printf("\n                ┃        ┃\n");
	LinkStackPtr p = s->top;
	while (p) {
		printf("                ├━━━━━━━━┤\n");
		printf("                ┃%6d  ┃\n", p->data);
		p = p->next;
	}
	printf("                ┗━━━━━━━━┛\n");
}