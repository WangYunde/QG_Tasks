#include "�������㣨���ף�.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	LinkStack Oprt; //�����ջ
	DLinkStack Num; //��������ջ
	initLStack(&Oprt);
	DinitLStack(&Num);
	

	int topOprt, oldOprt; //���ڼ�¼ջ��Ԫ�ء���ջԪ��
	double n; //��ֵ
	char c; //�����

	//��ӭҳ
	printf("\n        ������������������������������������������������������������");
	printf("\n        ��  ��ӭʹ�ñ����߼�������������");
	printf("\n        ������������������������������������������������������������\n");
	printf("\n->�����������ܡ�ǿ�󡱣�������һ������Сѧ����������������\n");
	printf("->���������Խ��и�������������������㣡(����֮��ɶҲ�ɲ��ˡ�����)\n");

in: //�û�����
	clearLStack(&Oprt);
	DclearLStack(&Num); //����ȷ��ջ���޲�������
	pushLStack(&Oprt, '#'); //'#'�������ջ��
	
	printf("\n����ȷ��������ʽ���� = ��β    �� �磺6+(4-2)*3+9/3=  ��\n");
	printf("��׺���ʽ��    ->");
	while (1) {
		if (scanf(" %lf", &n)) { //������ֵ
			printf(" %f", n);
			calculate(&Num, n, 0);
		}
			
		if (scanf(" %c", &c)) { //�����ַ�
			switch (c) {
			case '+':
			case '-':
			case '*':
			case '/': //�������ȼ�����ջ
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
			case ')': //����'('~')'���������
				getTopLStack(&Oprt, &topOprt);
				while (topOprt != '(') {
					popLStack(&Oprt, &oldOprt);
					printf(" %c", oldOprt);
					calculate(&Num, 0, oldOprt);
					getTopLStack(&Oprt, &topOprt);
					if (topOprt == '#') {
						printf("\n->û�� ( �� ) ��Ӧ�����������룡\n");
						while ((getchar()) != '\n') {};
						goto in;
					}
				}
				popLStack(&Oprt, &oldOprt);
				break;
			case '=': //�������
				goto out;
				break;
			default: //�ַ��Ƿ�����
				printf("\n->����������������������룡\n");
				while ((getchar()) != '\n') {};
				goto in;
				break;
			}
		}
	}
out: //ʣ���������ջ
	getTopLStack(&Oprt, &topOprt);
	while (topOprt != '#') {
		popLStack(&Oprt, &oldOprt);
		printf(" %c", oldOprt);
		calculate(&Num, 0, oldOprt);
		getTopLStack(&Oprt, &topOprt);
	}
	printf("    ����ת��Ϊ��׺���ʽ��\n");
	
	printf("\n->������Ϊ��%f", Num.top->data); //���������

	while ((getchar()) != '\n') {};
	goto in; //�ɶ�μ���

	return 0;
}




	//�������ã���������ӡ�����
	//int type = 0; //��2Ϊ�������1Ϊ���֣�0Ϊ�Ƿ����룩
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