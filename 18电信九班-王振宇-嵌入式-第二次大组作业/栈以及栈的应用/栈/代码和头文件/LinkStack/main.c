#include "../head/LinkStack.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	//欢迎页 
	printf("\n              ┏━━━━━━━━━━━━━━━━━━━━━━━━┓");
	printf("\n              ┃   欢迎使用链栈制造机！ ┃");
	printf("\n              ┗━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf("\n->您将通过几个简单的步骤创建出一个链栈以存入数据，并可以进行简单的操作\n");
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
	printf("\n\n->现在，您可以对链栈进行以下操作\n");
	printf("->    ┏━━┬━━━━━━━━━━━━━━━┓\n");
	printf("      ┃ A┃  初始化链栈   ┃\n");
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

	LinkStack S;
	S.top = NULL;
	S.count = -1;
	char step1;
	scanf("%c", &step1);
	while (step1 != 'Z') {
		switch (step1) {
			//非法字符输入反馈
		default:
			printf("\n->亲，这边建议您正确输入呢！\n");
			break;
			//初始化链栈 
		case 'A':
			if (S.count > -1) {
				printf("\n->已经初始化过了，请进行其他操作\n");
				break;
			}
			initLStack(&S);
			printf("\n创建成功！");
			break;
			//加入数据
		case 'B':
			if (S.count < 0) {
				printf("\n->您还没有初始化链栈\n");
				break;
			}
			int bePush = 0;
			printf("->请输入一个或多个数据，以字符结束：    ->");
			for (int data; scanf("%d", &data); pushLStack(&S, data)) {
				bePush = 1;
			}
			if (bePush)
				printf("->入栈成功！\n");
			else
				printf("->未输入有效数据\n");
			break;
			break;
			//删除数据
		case 'C':
			if (S.count < 0) {
				printf("\n->您还没有初始化链栈\n");
				break;
			}
			int beDelet;
			if (popLStack(&S, &beDelet))
				printf("\n->数据 %d 已被删除\n", beDelet);
			else
				printf("\n->栈内已无数据！\n");
			break;
			//清空栈
		case 'D':
			if (S.count < 0) {
				printf("\n->您还没有初始化链栈\n");
				break;
			}
			clearLStack(&S);
			printf("\n->链栈已被清空\n");
			break;
			//销毁栈
		case 'E':
			if (S.count < 0) {
				printf("\n->您还没有初始化链栈\n");
				break;
			}
			destroyLStack(&S);
			printf("\n->链栈已被销毁\n");
			break;
			//查看栈顶数据
		case 'F':
			if (S.count < 0) {
				printf("\n->您还没有初始化链栈\n");
				break;
			}
			int lastData;
			if (getTopLStack(&S, &lastData))
				printf("\n栈最后数据为%d\n", lastData);
			else
				printf("\n栈内已无数据\n");
			break;
			//判断长度
		case 'G':
			if (S.count < 0) {
				printf("\n->您还没有初始化链栈\n");
				break;
			}
			int length;
			LStackLength(&S, &length);
			printf("\n->当前栈内数据有 %d 个\n", length);
			break;
		}
		if (S.count > -1) {
			printf("\n->当前栈中数据状态为\n");
			StarkTraverse(&S);
		}

		while ((getchar()) != '\n') {};
		printf("\n\n->还需要做哪类操作？\n");
		printf("->    ┏━━┬━━━━━━━━━━━━━━━┓\n");
		printf("      ┃ A┃  初始化链栈   ┃\n");
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
	if (S.count < 0)
		destroyLStack(&S);
	printf("\n->以为您清除数据，期待您的下次使用！\n");

	getch();
	return 0;
}