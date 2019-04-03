#include "四则运算（进阶）.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	LinkStack Oprt; //运算符栈
	DLinkStack Num; //数字运算栈
	initLStack(&Oprt);
	DinitLStack(&Num);
	

	int topOprt, oldOprt; //用于记录栈顶元素、出栈元素
	double n; //数值
	char c; //运算符

	//欢迎页
	printf("\n        ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	printf("\n        ┃  欢迎使用本“高级”计算器！┃");
	printf("\n        ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf("\n->本计算器功能“强大”，能满足一至三级小学生的所有运算需求！\n");
	printf("->您甚至可以进行浮点数、负数的四则计算！(除此之外啥也干不了。。。)\n");

in: //用户输入
	clearLStack(&Oprt);
	DclearLStack(&Num); //用于确认栈内无残留数据
	pushLStack(&Oprt, '#'); //'#'作运算符栈底
	
	printf("\n请正确输入算术式，以 = 结尾    （ 如：6+(4-2)*3+9/3=  ）\n");
	printf("中缀表达式：    ->");
	while (1) {
		if (scanf(" %lf", &n)) { //读入数值
			printf(" %f", n);
			calculate(&Num, n, 0);
		}
			
		if (scanf(" %c", &c)) { //读入字符
			switch (c) {
			case '+':
			case '-':
			case '*':
			case '/': //根据优先级出入栈
				if (compare(&Oprt, c)) {
					while (compare(&Oprt, c)) {
						popLStack(&Oprt, &oldOprt);
						printf(" %c", oldOprt);
						calculate(&Num, 0, oldOprt);
					}
					pushLStack(&Oprt, c);
				}
				else {
					pushLStack(&Oprt, c);
				}
				break;
			case '(':
				pushLStack(&Oprt, c);
				break;
			case ')': //弹出'('~')'所有运算符
				getTopLStack(&Oprt, &topOprt);
				while (topOprt != '(') {
					popLStack(&Oprt, &oldOprt);
					printf(" %c", oldOprt);
					calculate(&Num, 0, oldOprt);
					getTopLStack(&Oprt, &topOprt);
					if (topOprt == '#') {
						printf("\n->没有 ( 与 ) 对应，请重新输入！\n");
						while ((getchar()) != '\n') {};
						goto in;
					}
				}
				popLStack(&Oprt, &oldOprt);
				break;
			case '=': //输入结束
				goto out;
				break;
			default: //字符非法输入
				printf("\n->符号输入错误，请您重新输入！\n");
				while ((getchar()) != '\n') {};
				goto in;
				break;
			}
		}
	}
out: //剩余运算符出栈
	getTopLStack(&Oprt, &topOprt);
	while (topOprt != '#') {
		popLStack(&Oprt, &oldOprt);
		printf(" %c", oldOprt);
		calculate(&Num, 0, oldOprt);
		getTopLStack(&Oprt, &topOprt);
	}
	printf("    （已转换为后缀表达式）\n");
	
	printf("\n->运算结果为：%f", Num.top->data); //输出运算结果

	while ((getchar()) != '\n') {};
	goto in; //可多次计算

	return 0;
}




	//以下无用，但不舍得扔。。。
	//int type = 0; //（2为运算符，1为数字，0为非法输入）
	//if (scanf(" %lf", &n))
	//	type = 1;
	//else if (scanf(" %c", &c))
	//	type = 2;
	//
	//while (type) {
	//	switch (c) {
	//	case -1:
	//		printf("%lf ", n);
	//		break;
	//	case '+':
	//	case '-':
	//	case '*':
	//	case '/':
	//		if (compare(&Oprt, c)) {
	//			while (compare(&Oprt, c)) {
	//				popLStack(&Oprt, &oldOprt);
	//				printf("%c", oldOprt);
	//			}
	//			pushLStack(&Oprt, c);
	//		}
	//		else {
	//			pushLStack(&Oprt, c);
	//		}
	//		break;
	//	case '(':
	//		pushLStack(&Oprt, c);
	//		break;
	//	case ')':
	//		getTopLStack(&Oprt, &topOprt);
	//		while (topOprt != '(') {
	//			popLStack(&Oprt, &oldOprt);
	//			printf("%c", oldOprt);
	//			getTopLStack(&Oprt, &topOprt);
	//		}
	//		popLStack(&Oprt, &oldOprt);
	//		break;
	//	default:

	//		break;
	//	}
	//	c = -1;
	//	type = 0;
	//	if (scanf(" %lf", &n))
	//		type = 1;
	//	else if (scanf(" %c", &c))
	//		type = 2;
	//}
	//while (topOprt != '#') {
	//	popLStack(&Oprt, &oldOprt);
	//	printf("%c", oldOprt);
	//	getTopLStack(&Oprt, &topOprt);
	//	(char)topOprt;
	//}