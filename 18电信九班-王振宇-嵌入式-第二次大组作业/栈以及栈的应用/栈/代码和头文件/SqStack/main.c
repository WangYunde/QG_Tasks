#include "../head/SqStack.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	//欢迎页 
	printf("\n              ┏━━━━━━━━━━━━━━━━━━━━━━━━┓");
	printf("\n              ┃  欢迎使用顺序栈制造机！┃");
	printf("\n              ┗━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf("\n->您将通过几个简单的步骤创建出一个顺序栈以存入数据，并可以进行简单的操作\n");
	printf("\n    ┏━━━━━━━━━━━┓    ┏━━━━━━━━━━━┓    ┏━━━━━━━━━━━┓");
	printf("\n    ┃  初始化栈 ┃ -->┃  数值输入 ┃ -->┃  查找判断 ┃");
	printf("\n    ┗━━━━━━━━━━━┛    ┗━━━━━━━━━━━┛    ┗━━━━━━━━━━━┛\n");
	printf("\n->让我们开始吧！\n->Y.开始    N.算了，告辞    ->");
	char step0;
	scanf("%c", &step0);
	while ((getchar()) != '\n') {};
	while (step0 != 'Y' && step0 != 'y') {
		if (step0 == 'N' || step0 == 'n') {
			printf("\n->拜了您嘞~\n");
			getch();
			return 0;
		}
		printf("\n->亲，这边建议您正确输入呢！\n");
		printf("\n->让我们开始吧！\n->Y.开始    N.算了，告辞    ->");
		scanf("%c", &step0);
		while ((getchar()) != '\n') {};
	}

	//根据用户选择进行操作 
	printf("\n\n->现在，您可以对顺序栈进行以下操作\n");
	printf("->    ┏━━┬━━━━━━━━━━━━━━━┓\n");
	printf("      ┃ A┃  初始化顺序栈 ┃\n");
	printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
	printf("      ┃ B┃  加入数据     ┃\n");
	printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
	printf("      ┃ C┃  删除数据     ┃\n");
	printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
	printf("      ┃ D┃  清空栈       ┃\n");
	printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
	printf("      ┃ E┃  销毁栈       ┃\n");
	printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
	printf("      ┃ F┃  查看栈顶数据 ┃\n");
	printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
	printf("      ┃ G┃  判断长度     ┃\n");
	printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
	printf("      ┃ Z┃  销毁并退出   ┃\n");
	printf("      ┗━━┴━━━━━━━━━━━━━━━┛\n->");

	SqStack S;
	S.size = 0;
	char step1;
	scanf("%c", &step1);
	while (step1 != 'Z') {
		switch (step1) {
			//非法字符输入反馈
			default:
				printf("\n->亲，这边建议您正确输入呢！\n");
				break;
			//初始化顺序栈 
			case 'A':
				if (S.size) {
					printf("\n->已经初始化过了，请进行其他操作\n");
					break;
				}
				int sizes = 1;
				printf("\n->您要创建的顺序栈初始大小为：    ->");
				while (!scanf("%d", &sizes) || sizes < 1) {
					while ((getchar()) != '\n') {};
					if (sizes < 1) 
						printf("\n顺序栈的大小应该大于0，请重新输入！\n");
					else
						printf("\n->字符为非法输入，请正确输入！\n");
					sizes = 1;
					printf("->您要创建的顺序栈初始大小为：    ->");
				}
				initStack(&S, sizes);
				printf("\n创建成功！");
				break;
			//加入数据
			case 'B':
				if (!S.size) {
					printf("\n->您还没有初始化顺序栈\n");
					break;
				}
				int bePush = 0;
				printf("->请输入一个或多个数据，以字符结束：    ->");
				for (int data; scanf("%d", &data); pushStack(&S, data)) {
					bePush = 1;
				}
				if (bePush)
					printf("->入栈成功！\n");
				else
					printf("->未输入有效数据\n");
				break;
			//删除数据
			case 'C':
				if (!S.size) {
					printf("\n->您还没有初始化顺序栈\n");
					break;
				}
				int beDelet;
				if (popStack(&S, &beDelet))
					printf("\n->数据 %d 已被删除\n", beDelet);
				else
					printf("\n->栈内已无数据！\n");
				break;
			//清空栈
			case 'D':
				if (!S.size) {
					printf("\n->您还没有初始化顺序栈\n");
					break;
				}
				clearStack(&S);
				printf("\n->顺序栈已被清空\n");
				break;
			//销毁栈
			case 'E':
				if (!S.size) {
					printf("\n->您还没有初始化顺序栈\n");
					break;
				}
				destroyStack(&S);
				printf("\n->顺序栈已被销毁\n");
				break;
			//查看栈顶数据
			case 'F':
				if (!S.size) {
					printf("\n->您还没有初始化顺序栈\n");
					break;
				}
				int lastData;
				if (getTopStack(&S, &lastData))
					printf("\n栈最后数据为%d\n", lastData);
				else
					printf("\n栈内已无数据\n");
				break;
			//判断长度
			case 'G':
				if (!S.size) {
					printf("\n->您还没有初始化顺序栈\n");
					break;
				}
				int length;
				stackLength(&S, &length);
				printf("\n->当前栈内数据有 %d 个\n", length);
				break;
		}
		if (S.size) {
			printf("\n->当前栈中数据状态为\n");
			StarkTraverse(&S);
		}
			
		while ((getchar()) != '\n') {};
		printf("\n\n->还需要做哪类操作？\n");
		printf("->    ┏━━┬━━━━━━━━━━━━━━━┓\n");
		printf("      ┃ A┃  初始化顺序栈 ┃\n");
		printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
		printf("      ┃ B┃  加入数据     ┃\n");
		printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
		printf("      ┃ C┃  删除数据     ┃\n");
		printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
		printf("      ┃ D┃  清空栈       ┃\n");
		printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
		printf("      ┃ E┃  销毁栈       ┃\n");
		printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
		printf("      ┃ F┃  查看栈顶数据 ┃\n");
		printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
		printf("      ┃ G┃  判断长度     ┃\n");
		printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
		printf("      ┃ Z┃  销毁并退出   ┃\n");
		printf("      ┗━━┴━━━━━━━━━━━━━━━┛\n->");
		scanf("%c", &step1);
	}

	//销毁并退出
	if (S.size)
		destroyStack(&S);
	printf("\n->以为您清除数据，期待您的下次使用！\n");

	getch();
	return 0;
}
/*	SqStack S;
	int sizes = 100;
	initStack(&S, sizes);
	for (int data; scanf("%d", &data); pushStack(&S, data)) {}
	StarkTraverse(&S);
	printf("\n%x，元素数%d，大小%d\n", S.elem, S.top + 1, S.size);

	int beDelet;
	popStack(&S, &beDelet);
	printf("\n->%d has been deleted.\n", beDelet);
	StarkTraverse(&S);
	printf("\n%x，元素数%d，大小%d\n", S.elem, S.top + 1, S.size);

	clearStack(&S);
	StarkTraverse(&S);
	printf("\n%x，元素数%d，大小%d\n", S.elem, S.top + 1, S.size);

	int lastData;
	if (getTopStack(&S, &lastData))
		printf("\n栈最后数据为%d\n", lastData);
	else
		printf("\n栈内已无数据\n");
	StarkTraverse(&S);
	printf("\n%x，元素数%d，大小%d\n", S.elem, S.top + 1, S.size);

	if (isEmptyStack(&S))
		printf("栈空\n");
	else
		printf("栈非空\n");

	destroyStack(&S);
	printf("\n栈销毁\n");
	StarkTraverse(&S);
	printf("\n%x，元素数%d，大小%d\n", S.elem, S.top + 1, S.size);
	*/