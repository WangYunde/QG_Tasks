#include "../head/SqStack.h"
#include <stdio.h>
#include <stdlib.h>

//顺序栈(基于数组的)
Status initStack(SqStack *s, int sizes)  //初始化栈
{
	s->elem = (ElemType*)malloc(sizes*sizeof(SqStack));
	if (s->elem == NULL)
		return ERROR;
	s->top = -1;
	s->size = sizes;
	return SUCCESS;
}

Status isEmptyStack(SqStack *s)   //判断栈是否为空
{
	if (s->top > -1)
		return ERROR;
	return SUCCESS;
}

Status getTopStack(SqStack *s, ElemType *e)   //得到栈顶元素
{
	if (s->top < 0)
		return ERROR;
	*e = *(s->elem + s->top);
	return SUCCESS;
		
}

Status clearStack(SqStack *s)   //清空栈
{
	s->top = -1;
	return SUCCESS;
}

Status destroyStack(SqStack *s)  //销毁栈
{
	free(s->elem);
	s->elem = NULL;
	s->top = -1;
	s->size = 0;
	return SUCCESS;
}

Status stackLength(SqStack *s, int *length)   //检测栈长度
{
	if (s->top < -1)
		return ERROR;
	*length = s->top + 1;
	return SUCCESS;
}

Status pushStack(SqStack *s, ElemType data)  //入栈
{
	if (s->top < -1)
		return ERROR;
	if (s->top >= s->size) {
		s->elem = (ElemType*)realloc(s->elem, 10 * sizeof(SqStack));
		s->size += 10;
	}
	s->top++;
	*(s->elem + s->top) = data;
	return SUCCESS;
}

Status popStack(SqStack *s, ElemType *data)   //出栈
{
	if (s->top < 0)
		return ERROR;
	*data = *(s->elem + s->top);
	s->top--;
	return SUCCESS;
}

Status StarkTraverse(SqStack *s)   //遍历栈
{
	if (s->top < -1)
		return ERROR;
	printf("\n                ┃        ┃\n");
	for (int i = s->top; i>= 0; i--) {
		printf("                ├━━━━━━━━┤\n");
		printf("                ┃%6d  ┃\n", *(s->elem + i));
	}
	printf("                ┗━━━━━━━━┛\n");
}
