#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status {
	ERROR = 0, SUCCESS = 1
} Status;

typedef int ElemType;

typedef  struct StackNode
{
	ElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack {
	LinkStackPtr top;
	int	count;
}LinkStack;

typedef  struct DStackNode
{
	double data;
	struct StackNode *next;
}DStackNode, *DLinkStackPtr;

typedef  struct  DLinkStack {
	DLinkStackPtr top;
	int	count;
}DLinkStack;


//链栈（int、char型）
Status initLStack(LinkStack *s);//初始化栈
Status getTopLStack(LinkStack *s, ElemType *e);//得到栈顶元素
Status pushLStack(LinkStack *s, ElemType data);//入栈
Status popLStack(LinkStack *s, ElemType *data);//出栈
Status clearLStack(LinkStack *s);//清空栈
//链栈（double型）
Status DinitLStack(DLinkStack *s);
Status DgetTopLStack(DLinkStack *s, double *e);
Status DpushLStack(DLinkStack *s, double data);
Status DpopLStack(DLinkStack *s, double *data);
Status DclearLStack(DLinkStack *s);

int compare(LinkStack *s, char c); //运算符优先级比较
double operate(double x, double y, char c); //二元计算
int calculate(DLinkStack *Num, double n, char c); //后缀式计算


#endif // STACK_H_INCLUDED
