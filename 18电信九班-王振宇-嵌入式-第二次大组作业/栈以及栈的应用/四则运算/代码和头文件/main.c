#include "��������.h"
#include <stdio.h>
#include <stdlib.h>

int compare(LinkStack *s, char c)
{	//����1�滻(new<=old)
	int topOprt;
	getTopLStack(s, &topOprt);
	(char)topOprt;
	if (topOprt == '#' || topOprt =='(')
		return 0;
	if (topOprt == '+' || topOprt == '-')
		if (c == '*' || c == '/')
			return 0;
	return 1;
}

int calculate(int x, int y, char c)
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

int main()
{
	LinkStack Oprt; //�����ջ
	initLStack(&Oprt);
	pushLStack(&Oprt, '#');
	int topOprt, oldOprt;

	int i = 0;
	char s[100];

	char c = getchar(); //6+(4-2)*3+9/3#
	int num = (int)(c - 48);
	while (c != '#') {
		switch (c) {
		case '(':
			pushLStack(&Oprt, c);
			break;
		case ')':
			getTopLStack(&Oprt, &topOprt);
			(char)topOprt;
			while (topOprt != '(') {
				popLStack(&Oprt, &oldOprt);
				printf("%c", oldOprt);
				s[i] = oldOprt;//
				i++;//
				getTopLStack(&Oprt, &topOprt);
				(char)topOprt;
			}
			popLStack(&Oprt, &oldOprt);
			break;
		case '+':
		case '-':
		case '*':
		case '/':
			if (compare(&Oprt, c)) {
				while (compare(&Oprt, c)) {
					popLStack(&Oprt, &oldOprt);
					printf("%c", oldOprt);
					s[i] = oldOprt;//
					i++;//
				}
				pushLStack(&Oprt, c);
			}
			else {
				pushLStack(&Oprt, c);
			}
			break;
		default: //��ȡ����ʱ
			printf("%d", num);
			s[i] = c;//
			i++;//
			break;
		}
		c = getchar();
		num = (int)(c - 48);
	}
	while (topOprt != '#') {
		popLStack(&Oprt, &oldOprt);
		printf("%c", oldOprt);
		s[i] = oldOprt;//
		i++;//
		getTopLStack(&Oprt, &topOprt);
		(char)topOprt;
	}
	
	s[i] = '#';
	LinkStack Num; //�����ջ
	initLStack(&Num);
	//pushLStack(&Num, '#');
	int topNum1, topNum2;
	int result;
	c = s[0];
	num = (int)(c - 48);
	for (int j = 1; c != '#'; j++) {
		switch (c) {
		case '+':
		case '-':
		case '*':
		case '/':
			popLStack(&Num, &topNum1);
			popLStack(&Num, &topNum2);
			result = calculate(topNum2, topNum1, c);
			pushLStack(&Num, result);
			break;
		default: //��ȡ����ʱ
			pushLStack(&Num, num);
			break;
		}
		c = s[j];
		num = (int)(c - 48);
	} //642-3*+93/+
	printf("\n���Ϊ��%d", Num.top->data);

	

	return 0;
}
//
	//LinkStack Num, Oprt;
	//pushLStack(&Oprt, '#');
	//char c = getchar();

	//printf("�ڴ������������ʽ��\n");
	//int topOptr; //ջ�������
	//int topNum;
	//while (c != '#') {
	//	if (c != '+' || c != '-' || c != '*' || c != '/') { //��������ʱ
	//		pushLStack(&Num, c);
	//		c = getchar();
	//	}
	//	else { //���������ʱ
	//		getTopLStack(&Oprt, &topOptr);
	//		switch (compare(topOptr, c)) {
	//		case 0: //�������ջ
	//			pushLStack(&Oprt, c);
	//			break;
	//		case 1: //�������ջ����������ջ
	//			popLStack(&Num, &topNum);
	//			break;
	//		}
	//		
	//	}