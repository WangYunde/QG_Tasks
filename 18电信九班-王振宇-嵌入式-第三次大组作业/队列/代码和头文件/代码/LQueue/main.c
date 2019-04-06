#include "../../头文件/LQueue.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	//欢迎页 
	printf("\n              ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	printf("\n              ┃  欢迎使用泛型链队列制造机！┃");
	printf("\n              ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf("\n->此队列可以混合存放整型、浮点型、字符串数据，且无需提前指定数据类型\n");
	printf("\n    ┏━━━━━━━━━━━━━┓    ┏━━━━━━━━━━━┓    ┏━━━━━━━━━━━━━┓");
	printf("\n    ┃  初始化队列 ┃ -->┃  数据输入 ┃ -->┃  查找和判断 ┃");
	printf("\n    ┗━━━━━━━━━━━━━┛    ┗━━━━━━━━━━━┛    ┗━━━━━━━━━━━━━┛\n");
	printf("\n->让我们开始吧！\n->Y.开始    N.算了，告辞    ->");
	char step0;
	scanf_s("%c", &step0);
	while ((getchar()) != '\n') {};
	while (step0 != 'Y' && step0 != 'y') {
		if (step0 == 'N' || step0 == 'n') {
			printf("\n->拜了您嘞~\n");
			getch();
			return 0;
		}
		printf("\n->亲，这边建议您正确输入呢！\n");
		printf("\n->让我们开始吧！\n->Y.开始    N.算了，告辞    ->");
		scanf_s("%c", &step0);
		while ((getchar()) != '\n') {};
	}
	LQueue Q;
	Q.length = -1;
	char* s;

	//根据用户选择进行操作 
	printf("\n\n->现在，您可以对队列进行以下操作\n");
	printf("->    ┏━━┬━━━━━━━━━━━━━━━┓\n");
	printf("      ┃ A┃  初始化队列   ┃\n");
	printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
	printf("      ┃ B┃  加入数据     ┃\n");
	printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
	printf("      ┃ C┃  删除数据     ┃\n");
	printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
	printf("      ┃ D┃  清空队列     ┃\n");
	printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
	printf("      ┃ E┃  销毁队列     ┃\n");
	printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
	printf("      ┃ F┃  查看队首数据 ┃\n");
	printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
	printf("      ┃ G┃  判断长度     ┃\n");
	printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
	printf("      ┃ Z┃  销毁并退出   ┃\n");
	printf("      ┗━━┴━━━━━━━━━━━━━━━┛\n->");
	char step1;
	scanf_s("%c", &step1);
	while ((getchar()) != '\n') {};
	while (step1 != 'Z') {
		switch (step1) {
			//非法字符输入反馈
		default:
			printf("\n->亲，这边建议您正确输入呢！\n");
			break;
			//初始化队列
		case 'A':
			if (Q.length > -1) {
				printf("\n->已经初始化过了，请进行其他操作\n");
				break;
			}
			InitLQueue(&Q);
			printf("\n->创建成功！");
			break;
			//加入数据
		case 'B':
			if (Q.length == -1) {
				printf("\n->您还没有初始化队列！\n");
				break;
			}
			s = malloc(1000 * sizeof(char));
			printf("->请输入数据，回车以结束：    ->");
			if (!judgeAndEn(&Q, s))
				printf("->您未输入数据\n");
			break;
			//删除数据
		case 'C':
			if (Q.length == -1) {
				printf("\n->您还没有初始化队列！\n");
				break;
			}
			if (DeLQueue(&Q))
				printf("\n->已删除原队首数据\n");
			else
				printf("\n->队列内已无数据！\n");
			break;
			//清空队列
		case 'D':
			if (Q.length == -1) {
				printf("\n->您还没有初始化队列！\n");
				break;
			}
			ClearLQueue(&Q);
			printf("\n->队列已被清空\n");
			break;
			//销毁队列
		case 'E':
			if (Q.length == -1) {
				printf("\n->您还没有初始化队列！\n");
				break;
			}
			DestoryLQueue(&Q);
			printf("\n->队列已被销毁\n");
			break;
			//查看队首数据
		case 'F':
			if (Q.length == -1) {
				printf("\n->您还没有初始化队列！\n");
				break;
			}
			if (Q.length == 0)
				printf("\n->队内已无数据\n");
			else {
				char* lastData = malloc(sizeof(char));
				GetHeadLQueue(&Q, lastData);
				//printf(" %s ", lastData);
			}
			break;
			//判断长度
		case 'G':
			if (Q.length == -1) {
				printf("\n->您还没有初始化队列！\n");
				break;
			}
			printf("\n->当前队列内数据有 %d 个\n", LengthLQueue(&Q));
			break;
		}

		if (Q.length > -1) {
			printf("\n->当前队列状态为\n");
			TraverseLQueue(Q, LPrint);
		}
		while ((getchar()) != '\n') {};
		printf("\n\n->还需要做哪类操作？\n");
		printf("->    ┏━━┬━━━━━━━━━━━━━━━┓\n");
		printf("      ┃ A┃  初始化队列   ┃\n");
		printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
		printf("      ┃ B┃  加入数据     ┃\n");
		printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
		printf("      ┃ C┃  删除数据     ┃\n");
		printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
		printf("      ┃ D┃  清空队列     ┃\n");
		printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
		printf("      ┃ E┃  销毁队列     ┃\n");
		printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
		printf("      ┃ F┃  查看队首数据 ┃\n");
		printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
		printf("      ┃ G┃  判断长度     ┃\n");
		printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
		printf("      ┃ Z┃  销毁并退出   ┃\n");
		printf("      ┗━━┴━━━━━━━━━━━━━━━┛\n->");
		scanf_s("%c", &step1);
		while ((getchar()) != '\n') {};
	}
	
	if (Q.length > -1)
		DestoryLQueue(&Q);
	printf("\n->以为您清除数据，期待您的下次使用！\n");

	getch();
	return 0;
}
	/*InitLQueue(&Q);
	char* s;

	s = malloc(1000 * sizeof(char));
	judgeAndEn(&Q, s);
	s = malloc(1000 * sizeof(char));
	judgeAndEn(&Q, s);
	s = malloc(1000 * sizeof(char));
	judgeAndEn(&Q, s);
	
	TraverseLQueue(Q, LPrint);*/

	/*LQueue Q;
	InitLQueue(&Q);
	switch (dataType) {
	case 0:
		for (int* e; e = (int*)malloc(sizeof(int)), scanf_s("%d", e); EnLQueue(&Q, e)) {};
		break;
	case 1:
		for (double* e; e = (double*)malloc(sizeof(double)), scanf_s("%lf", e); EnLQueue(&Q, e)) {};
		break;
	case 2:
		for (char* e; e = (char*)malloc(sizeof(char)), *e = getchar(), *e != '\n'; EnLQueue(&Q, e)) {};
		break;
	}
	TraverseLQueue(Q, LPrint);
	printf("头%p，首%p，尾%p，长度%d\n\n", Q.front, Q.front->next, Q.rear, LengthLQueue(&Q));

	DeLQueue(&Q);
	TraverseLQueue(Q, LPrint);
	printf("头%p，首%p，尾%p，长度%d\n\n", Q.front, Q.front->next, Q.rear, LengthLQueue(&Q));

	//ClearLQueue(&Q);
	//TraverseLQueue(Q, LPrint);
	//printf("头%p，首%p，尾%p，长度%d\n\n", Q.front, Q.front->next, Q.rear, LengthLQueue(&Q));
	
	void* lastData = malloc(sizeof(char));
	if (GetHeadLQueue(&Q, &lastData))
		printf("\n队首数据为%c\n", *(char*)lastData);
	else
		printf("\n队内已无数据\n");

	if (IsEmptyLQueue(&Q))
		printf("队列空\n");
	else
		printf("队列非空\n");

	DestoryLQueue(&Q);*/