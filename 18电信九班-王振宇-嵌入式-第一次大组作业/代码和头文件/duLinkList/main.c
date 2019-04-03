#include "../head/duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
//欢迎页 
	printf("\n              ┏━━━━━━━━━━━━━━━━━━━━━━━━┓");
	printf("\n              ┃  欢迎使用双链表制造机！┃");
	printf("\n              ┗━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf("\n->您将通过几个简单的步骤创建出一个双链表以存入数据，并可以进行简单的修改\n");
	printf("\n    ┏━━━━━━━━━━━┓    ┏━━━━━━━━━━━┓    ┏━━━━━━━━━━━┓");
	printf("\n    ┃  输入数值 ┃ -->┃  数值修改 ┃ -->┃  查找判断 ┃");
	printf("\n    ┗━━━━━━━━━━━┛    ┗━━━━━━━━━━━┛    ┗━━━━━━━━━━━┛\n");
	printf("\n->让我们开始吧！\n->Y.开始    N.算了，告辞    ->");
	char step0;
	scanf("%c", &step0);
	if ( step0 != 'Y' && step0 != 'y' ) {
		printf("\n->拜了您嘞~\n");
		return 0;
	}
	
//根据用户输入创建链表 
	printf("\n->接下来，我需要您输入链表需要存放的数值，以空格或回车间隔\n->您可以随时输入字符并回车以停止：\n->");
	Status beCreat = SUCCESS;
	//定义头指针、头节点
	DuLinkedList head;
	beCreat = InitList_DuL(&head);
	if ( beCreat == ERROR ) {
		printf("->Oooops，创建头节点失败，下次见！");
		return 0; 
	} 
	//延长链表，输入字符停止
	DuLinkedList p, q;
	p = head;
	q = (DuLinkedList)malloc(sizeof(DuLNode));
	int i = 0; //用于判断是否为空链表
	while ( scanf("%d", &q->data) && q ) {
		InsertAfterList_DuL(p, q);
		p = q;
		q = (DuLinkedList)malloc(sizeof(DuLNode));
		i = 1; 
	}
	if ( i == 0 ) {
		printf("\n->抱歉，空链表无法进行后续操作，再见！\n");
		return 0;
	}
	if ( q ) {
		free(q);
		fflush(stdin); //清空缓存区字符
	} else {
		printf("Oooops，内存分配出了点问题，下次见！");
		return 0; //出现异常即退出 
	}
	printf("\n->恭喜您，您已成功创建链表，内容为：\n->");
	TraverseList_DuL(head, PrintData); //遍历链表并输出
	
//根据用户选择对链表进行操作 
	printf("\n\n->现在，您可以对链表进行以下操作\n");
	printf("->    ┏━━┬━━━━━━━━━━━━━━━┓\n");
	printf("      ┃ A┃  向后插入节点 ┃\n");
	printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
	printf("      ┃ B┃  向前插入节点 ┃\n");
	printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
	printf("      ┃ C┃  删除节点     ┃\n");
	printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
	printf("      ┃ D┃  不做修改     ┃\n");
	printf("      ┗━━┴━━━━━━━━━━━━━━━┛\n->");
	Status isWork = SUCCESS; //记录执行结果 
	char step1;
	scanf("%c", &step1);
	while ( step1 != 'D' ) {
		switch (step1) {
			//向后插入节点 
			case 'A':
				printf("\n->您希望插入的节点数值为？    ->");
				//新建节点并存入数据 
				DuLinkedList qa;
				InitList_DuL(&qa);
				scanf("%d", &(qa->data));
				//找到插入点
				printf("->插入在哪个节点数值之后？    ->");
				ElemType ea;
				scanf("%d", &ea);
				DuLinkedList pa = SearchData(head, ea);
				//执行插入
				if ( pa )
					isWork = InsertAfterList_DuL(pa, qa);
				else
					printf("\n->抱歉，未找到这个节点数值");
				break;
			//向前插入节点 
			case 'B':
				printf("\n->您希望插入的节点数值为？    ->");
				//新建节点并存入数据 
				DuLinkedList qb;
				InitList_DuL(&qb);
				scanf("%d", &(qb->data));
				//找到插入点
				printf("->插入在哪个节点数值之前？    ->");
				ElemType eb;
				scanf("%d", &eb);
				DuLinkedList pb = SearchData(head, eb);
				//执行插入
				if ( pb )
					isWork = InsertBeforeList_DuL(pb, qb);
				else
					printf("\n->抱歉，未找到这个节点数值");
				break;
			//删除节点 
			case 'C':
				printf("\n->您希望删除哪个节点数值之后的节点？请输入第一~倒数第二的节点数据    ->");
				ElemType ec;
				scanf("%d", &ec);
				DuLinkedList pc = SearchData(head, ec);
				if( !DeleteList_DuL(pc, &ec) )
					printf("\n->抱歉，输入有误");
				break;
			//非法字符输入反馈 
			default:
				printf("\n->请您输入正确的字符！\n");
		}
		if ( isWork ) {
			printf("\n->当前链表为：\n->");
			TraverseList_DuL(head, PrintData); //遍历链表并输出
		} else {
			printf("\n->Oooops，似乎出了点问题，下次见！");
			return 0;
		}
		printf("\n\n->还需要做哪类更改？\n");
		printf("->    ┏━━┬━━━━━━━━━━━━━━━┓\n");
		printf("      ┃ A┃  向后插入节点 ┃\n");
		printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
		printf("      ┃ B┃  向前插入节点 ┃\n");
		printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
		printf("      ┃ C┃  删除节点     ┃\n");
		printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
		printf("      ┃ D┃  不做修改     ┃\n");
		printf("      ┗━━┴━━━━━━━━━━━━━━━┛\n->");
		fflush(stdin);
		scanf("%c", &step1);
	}
	
//销毁链表并退出
	DestroyList_DuL(&head);
	printf("\n->已为您销毁链表，期待与您的下次使用！\n");
	
	return 0;
}


//以下无用 
//根据用户选择对链表进行判断或查找 
//	printf("\n\n->现在，您可以对链表进行查找\n");
//	printf("->    ┏━━┬━━━━━━━━━━━━━━━┓\n");
//	printf("      ┃ A┃  查找节点数值 ┃\n");
//	printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
//	printf("      ┃ B┃  不做查找     ┃\n");
//	printf("      ┗━━┴━━━━━━━━━━━━━━━┛\n->");
//	isWork = SUCCESS; //记录执行结果 
//	char step2;
//	fflush(stdin);
//	scanf("%c", &step2);
//	while ( step2 != 'B' ) {
//		switch (step2) {
//			//查找节点数值
//			case 'A':
//				printf("\n->在此输入需要查找的数据：    ->"); 
//				int data;
//				scanf("%d", &data);
//				Status isFound = SearchList_DuL(head, data);
//				if ( isFound )
//					printf("\n->这个数据在链表中\n");
//				else
//					printf("\n->链表中不存在这个数据\n");
//				break;
//			//非法字符输入反馈 
//			default:
//				printf("\n->请您输入正确的字符！\n");
//		}
//		if ( !isWork ) {
//			printf("->Oooops，似乎出了点问题，下次见！");
//			return 0;
//		}
//		printf("\n\n->还是否还需要查找？\n");
//		printf("->    ┏━━┬━━━━━━━━━━━━━━━┓\n");
//		printf("      ┃ A┃  查找节点数值 ┃\n");
//		printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
//		printf("      ┃ B┃  不做查找     ┃\n");
//		printf("      ┗━━┴━━━━━━━━━━━━━━━┛\n->");
//		fflush(stdin);
//		scanf("%c", &step2);
//	}
