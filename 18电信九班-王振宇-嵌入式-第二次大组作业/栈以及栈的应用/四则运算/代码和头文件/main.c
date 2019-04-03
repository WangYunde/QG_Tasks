#include "四则运算.h"
#include <stdio.h>
#include <stdlib.h>

int compare(LinkStack *s, char c)
{	//返回1替换(new<=old)
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
	LinkStack Oprt; //运算符栈
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
		default: //读取数字时
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
	LinkStack Num; //运算符栈
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
		default: //读取数字时
			pushLStack(&Num, num);
			break;
		}
		c = s[j];
		num = (int)(c - 48);
	} //642-3*+93/+
	printf("\n结果为：%d", Num.top->data);

	

	return 0;
}
//
	//LinkStack Num, Oprt;
	//pushLStack(&Oprt, '#');
	//char c = getchar();

	//printf("在此输入整个表达式：\n");
	//int topOptr; //栈顶运算符
	//int topNum;
	//while (c != '#') {
	//	if (c != '+' || c != '-' || c != '*' || c != '/') { //输入数字时
	//		pushLStack(&Num, c);
	//		c = getchar();
	//	}
	//	else { //输入运算符时
	//		getTopLStack(&Oprt, &topOptr);
	//		switch (compare(topOptr, c)) {
	//		case 0: //运算符入栈
	//			pushLStack(&Oprt, c);
	//			break;
	//		case 1: //运算符退栈，运算结果入栈
	//			popLStack(&Num, &topNum);
	//			break;
	//		}
	//		
	//	}