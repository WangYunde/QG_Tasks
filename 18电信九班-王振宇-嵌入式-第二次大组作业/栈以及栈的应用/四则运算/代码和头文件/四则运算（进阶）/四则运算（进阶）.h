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


//��ջ��int��char�ͣ�
Status initLStack(LinkStack *s);//��ʼ��ջ
Status getTopLStack(LinkStack *s, ElemType *e);//�õ�ջ��Ԫ��
Status pushLStack(LinkStack *s, ElemType data);//��ջ
Status popLStack(LinkStack *s, ElemType *data);//��ջ
Status clearLStack(LinkStack *s);//���ջ
//��ջ��double�ͣ�
Status DinitLStack(DLinkStack *s);
Status DgetTopLStack(DLinkStack *s, double *e);
Status DpushLStack(DLinkStack *s, double data);
Status DpopLStack(DLinkStack *s, double *data);
Status DclearLStack(DLinkStack *s);

int compare(LinkStack *s, char c); //��������ȼ��Ƚ�
double operate(double x, double y, char c); //��Ԫ����
int calculate(DLinkStack *Num, double n, char c); //��׺ʽ����


#endif // STACK_H_INCLUDED
