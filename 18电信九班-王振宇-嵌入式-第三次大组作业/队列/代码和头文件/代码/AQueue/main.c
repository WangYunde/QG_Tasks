#include "../../头文件/AQueue.h"
#include <stdio.h>
#include <stdlib.h>
int dataType = 0;
int dataSize = 4;

int main()
{
	//欢迎页 
	printf("\n              ┏━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	printf("\n              ┃  欢迎使用循环队列制造机！┃");
	printf("\n              ┗━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf("\n->在您选择队列的数据类型后，您将创建一个最多能容纳10个数据的队列\n");
	printf("\n    ┏━━━━━━━━━━━━━┓    ┏━━━━━━━━━━━┓    ┏━━━━━━━━━━━━━┓");
	printf("\n    ┃  初始化队列 ┃ -->┃  数值输入 ┃ -->┃  查找和判断 ┃");
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
	printf("\n->谢谢使用！您要存放的数据类型为？\n");
	printf("->    ┏━━┬━━━━━━━━━━━┓\n");
	printf("      ┃ 0┃  整型     ┃\n");
	printf("      ├━━┼━━━━━━━━━━━┤\n");
	printf("      ┃ 1┃  浮点型   ┃\n");
	printf("      ├━━┼━━━━━━━━━━━┤\n");
	printf("      ┃ 2┃  字符串   ┃\n");
	printf("      ┗━━┴━━━━━━━━━━━┛\n->");
	scanf_s("%d", &dataType);
	while ((getchar()) != '\n') {};
	while (dataType != 0 && dataType != 1 && dataType != 2) {
		printf("\n->亲，这边建议您正确输入呢！\n->");
		scanf_s("%d", &dataType);
		while ((getchar()) != '\n') {};
	}

	AQueue Q;
	Q.length = -1;

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
			InitAQueue(&Q);
			printf("\n->创建成功！");
			break;
		//加入数据
		case 'B':
			if (Q.length == -1) {
				printf("\n->您还没有初始化队列！\n");
				break;
			}
			if (dataType != 2)
				printf("->请输入一个或多个数据，以字符结束：    ->");
			else
				printf("->请输入一个或多个字符，以回车结束：    ->");
			switch (dataType) {
			case 0:
				for (int* e; e = malloc(dataSize), scanf_s("%d", e); EnAQueue(&Q, e)) {};
				break;
			case 1:
				for (double* e; e = malloc(dataSize), scanf_s("%lf", e); EnAQueue(&Q, e)) {};
				break;
			case 2:
				for (char* e; e = malloc(dataSize), *e = getchar(), *e != '\n'; EnAQueue(&Q, e)) {};
				break;
			}
			break;
		//删除数据
		case 'C':
			if (Q.length == -1) {
				printf("\n->您还没有初始化队列！\n");
				break;
			}
			if (DeAQueue(&Q))
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
			ClearAQueue(&Q);
			printf("\n->队列已被清空\n");
			break;
		//销毁队列
		case 'E':
			if (Q.length == -1) {
				printf("\n->您还没有初始化队列！\n");
				break;
			}
			DestoryAQueue(&Q);
			printf("\n->队列已被销毁\n");
			break;
		//查看队首数据
		case 'F':
			if (Q.length == -1) {
				printf("\n->您还没有初始化队列！\n");
				break;
			}
			void* lastData = malloc(dataSize);
			if (GetHeadAQueue(Q, &lastData)) {
				switch (dataType) {
				case 0:
					printf("\n->队首数据为：%d\n", *(int*)lastData);
					break;
				case 1:
					printf("\n->队首数据为：%f\n", *(double*)lastData);
					break;
				case 2:
					printf("\n->队首数据为：%c\n", *(char*)lastData);
					break;
				}
			}
			else
				printf("\n->队内已无数据\n");
			break;
		//判断长度
		case 'G':
			if (Q.length == -1) {
				printf("\n->您还没有初始化队列！\n");
				break;
			}
			printf("\n->当前队列内数据有 %d 个\n", LengthAQueue(&Q));
			break;
		}

		if (Q.length > -1) {
			printf("\n->当前队列状态为\n");
			TraverseAQueue(Q, APrint);
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
		DestoryAQueue(&Q);
	printf("\n->以为您清除数据，期待您的下次使用！\n");

	getch();
	return 0;
}
	/*switch (dataType) {
	case 0:
		for (int* e; e = malloc(dataSize), scanf_s("%d", e); EnAQueue(&Q, e)) {};
		break;
	case 1:
		for (double* e; e = malloc(dataSize), scanf_s("%lf", e); EnAQueue(&Q, e)) {};
		break;
	case 2:
		for (char* e; e = malloc(dataSize), *e = getchar(), *e != '\n'; EnAQueue(&Q, e)) {};
		break;
	}
	TraverseAQueue(Q, APrint);
	printf("%p~%p，长度%d\n\n", Q.data[Q.front], Q.data[Q.rear-1], Q.length);

	DeAQueue(&Q);
	TraverseAQueue(Q, APrint);
	printf("%p~%p，长度%d\n\n", Q.data[Q.front], Q.data[Q.rear - 1], Q.length);

	//ClearAQueue(&Q);
	//TraverseAQueue(Q, APrint);
	//printf("%p~%p，长度%d\n\n", Q.data[Q.front], Q.data[Q.rear - 1], Q.length);

	void* lastData = malloc(dataSize);
	if (GetHeadAQueue(Q, &lastData))
		printf("\n队首数据为%d\n", *(int*)lastData);
	else
		printf("\n队内已无数据\n");

	if (IsEmptyAQueue(&Q))
		printf("队列空\n");
	else
		printf("队列非空\n");

	if (IsFullAQueue(&Q))
		printf("队列满\n");
	else
		printf("队列未满\n");*/