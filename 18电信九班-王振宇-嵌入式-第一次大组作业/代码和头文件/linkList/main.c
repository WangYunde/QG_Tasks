#include "../head/linkedList.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
//欢迎页 
	printf("\n              ┏━━━━━━━━━━━━━━━━━━━━━━━━┓");
	printf("\n              ┃  欢迎使用单链表制造机！┃");
	printf("\n              ┗━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf("\n->您将通过几个简单的步骤创建出一个单链表以存入数据，并可以进行简单的修改\n");
	printf("\n    ┏━━━━━━━━━━━┓    ┏━━━━━━━━━━━┓    ┏━━━━━━━━━━━┓");
	printf("\n    ┃  输入数值 ┃ -->┃  数值修改 ┃ -->┃  查找判断 ┃");
	printf("\n    ┗━━━━━━━━━━━┛    ┗━━━━━━━━━━━┛    ┗━━━━━━━━━━━┛\n");
	printf("\n->让我们开始吧！\n->Y.开始    N.算了，告辞    ->");
	char step0;
	scanf("%c", &step0);
	fflush(stdin);
	while ( step0 != 'Y' && step0 != 'y' ) {
		printf("\n->亲，这边建议您正确输入呢！\n");
		if ( step0 == 'N' && step0 == 'n' ) {
		printf("\n->拜了您嘞~\n");
		getch(); 
		return 0;
		}
		printf("\n->让我们开始吧！\n->Y.开始    N.算了，告辞    ->");
		scanf("%c", &step0);
		fflush(stdin);
	} 
	
	
//根据用户输入创建链表 
	printf("\n->接下来，我需要您输入链表需要存放的数值，以空格或回车间隔\n->您可以随时输入字符并回车以停止：\n->");
	Status beCreat = SUCCESS;
	//定义头指针、头节点
	LinkedList head;
	beCreat = InitList(&head);
	if ( beCreat == ERROR ) {
		printf("->Oooops，创建头节点失败，下次见！");
		getch();
		return 0;
	} 
	//延长链表，输入字符停止
	LinkedList p, q;
	p = head;
	q = (LinkedList)malloc(sizeof(LNode));
	int i = 0; //用于判断是否为空链表
	while ( scanf("%d", &q->data) && q ) {
		InsertList(p, q);
		p = q;
		q = (LinkedList)malloc(sizeof(LNode));
		i = 1; 
	}
	if ( i == 0 ) {
		printf("\n->抱歉，空链表无法进行后续操作，再见！\n");
		getch();
		return 0;
	}
	if ( q ) {
		free(q);
		fflush(stdin); //清空缓存区字符
	} else {
		printf("Oooops，内存分配出了点问题，下次见！");
		getch();
		return 0; //出现异常即退出 
	}
	printf("\n->恭喜您，您已成功创建链表，内容为：\n->");
	TraverseList(head, PrintData); //遍历链表并输出
	
//根据用户选择对链表进行操作 
	printf("\n\n->现在，您可以对链表进行以下操作\n");
	printf("->    ┏━━┬━━━━━━━━━━━━━━━┓\n");
	printf("      ┃ A┃  插入节点     ┃\n");
	printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
	printf("      ┃ B┃  删除节点     ┃\n");
	printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
	printf("      ┃ C┃  反转链表     ┃\n");
	printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
	printf("      ┃ D┃  反转偶数节点 ┃\n");
	printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
	printf("      ┃ E┃  链表成环     ┃\n");
	printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
	printf("      ┃ F┃  不做修改     ┃\n");
	printf("      ┗━━┴━━━━━━━━━━━━━━━┛\n->");
	Status isWork = SUCCESS; //记录执行结果 
	Status isRight;
	char step1;
	scanf("%c", &step1);
	while ( step1 != 'F' ) {
		switch (step1) {
			//插入节点 
			case 'A':
				isRight = SUCCESS;
				printf("\n->您希望插入的节点数值为？    ->");
				//新建节点并存入数据 
				LinkedList qa;
				InitList(&qa);
				isRight = scanf("%d", &(qa->data));
				if ( isRight == ERROR ) {
					printf("\n->亲，这边建议您正确输入呢！\n");
					fflush(stdin);
					break;
				}
				//找到插入点
				printf("->插入在哪个节点数值之后？    ->");
				ElemType ea;
				isRight = scanf("%d", &ea);
				if ( isRight == ERROR ) {
					printf("\n->亲，这边建议您正确输入呢！\n");
					fflush(stdin);
					break;
				}
				LinkedList pa = SearchData(head, ea);
				//执行插入
				if ( pa )
					isWork = InsertList(pa, qa);
				else
					printf("\n->抱歉，未找到这个节点数值");
				break;
			//删除节点 
			case 'B':
				isRight = SUCCESS;
				printf("\n->您希望删除哪个节点数值之后的节点？请输入第一~倒数第二的节点数据    ->");
				ElemType eb;
				isRight = scanf("%d", &eb);
				if ( isRight == ERROR ) {
					printf("\n->亲，这边建议您正确输入呢！\n");
					fflush(stdin);
					break;
				}
				LinkedList pb = SearchData(head, eb);
				if( !DeleteList(pb, &eb) )
					printf("\n->抱歉，输入有误");
				break;
			//反转链表 
			case 'C':
				isWork = ReverseList(&head);
				break;
			//反转偶数节点
			case 'D':
				ReverseEvenList(&head); 
				break;
			//链表成环
			case 'E':
				printf("->在哪个节点数值成环？    ");
				ElemType ee;
				isRight = scanf("%d", &ee);
				if ( isRight == ERROR ) {
					printf("\n->亲，这边建议您正确输入呢！\n");
					fflush(stdin);
					break;
				}
				p->next = SearchData(head, ee);
				printf("\n->执行完毕，接下来程序将检测更改后的链表是否成环\n\n﹀\n﹀\n﹀\n﹀\n﹀\n"); 
				goto loop;
			//非法字符输入反馈 
			default:
				printf("\n->亲，这边建议您正确输入呢！\n");
		}
		if ( isWork ) {
			printf("\n->当前链表为：\n->");
			TraverseList(head, PrintData); //遍历链表并输出
		} else {
			printf("\n->Oooops，似乎出了点问题，下次见！");
			getch();
			return 0;
		}
		printf("\n\n->还需要做哪类更改？\n");
		printf("->    ┏━━┬━━━━━━━━━━━━━━━┓\n");
		printf("      ┃ A┃  插入节点     ┃\n");
		printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
		printf("      ┃ B┃  删除节点     ┃\n");
		printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
		printf("      ┃ C┃  反转链表     ┃\n");
		printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
		printf("      ┃ D┃  反转偶数节点 ┃\n");
		printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
		printf("      ┃ E┃  链表成环     ┃\n");
		printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
		printf("      ┃ F┃  不做修改     ┃\n");
		printf("      ┗━━┴━━━━━━━━━━━━━━━┛\n->");
		fflush(stdin);
		scanf("%c", &step1);
	}
	
//根据用户选择对链表进行判断或查找 
	printf("\n\n->现在，您可以对链表进行以下判断或查找\n");
	printf("->    ┏━━┬━━━━━━━━━━━━━━━┓\n");
	printf("      ┃ A┃  输出中间节点 ┃\n");
	printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
	printf("      ┃ B┃  查找节点数值 ┃\n");
	printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
	printf("      ┃ C┃  判断是否成环 ┃\n");
	printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
	printf("      ┃ D┃ 不做判断或查找┃\n");
	printf("      ┗━━┴━━━━━━━━━━━━━━━┛\n->");
	isWork = SUCCESS; //记录执行结果 
	char step2;
	fflush(stdin);
	scanf("%c", &step2);
	while ( step2 != 'D' ) {
		switch (step2) {
			//输出中间节点
			case 'A':;
				LinkedList mid = FindMidNode(&head);
				printf("\n->这个链表中间节点的数值为：%d", mid->data);
				break;
			//查找节点数值
			case 'B':
				printf("\n->在此输入需要查找的数据：    ->"); 
				int data;
				isRight = scanf("%d", &data);
				if ( isRight == ERROR ) {
					printf("\n->亲，这边建议您正确输入呢！\n");
					fflush(stdin);
					break;
				}
				Status isFound = SearchList(head, data);
				if ( isFound )
					printf("\n->这个数据在链表中\n");
				else
					printf("\n->链表中不存在这个数据\n");
				break;
			//判断是否成环
			case 'C':
				loop:;
				Status isLoop = IsLoopList(head);
				if ( isLoop ) {
					printf("\n->经判断，这个链表成环，期待与您的下次见面！\n");
					getch(); 
					return 0; 
				} else { 
					printf("\n->经判断，这个链表不成环\n");
				} 
				break;
			//非法字符输入反馈 
			default:
				printf("\n->请您输入正确的字符！\n");
		}
		if ( !isWork ) {
			printf("->Oooops，似乎出了点问题，下次见！");
			getch();
			return 0;
		}
		printf("\n\n->还需要做哪类判断或查找？\n");
		printf("->    ┏━━┬━━━━━━━━━━━━━━━┓\n");
		printf("      ┃ A┃  输出中间节点 ┃\n");
		printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
		printf("      ┃ B┃  查找节点数值 ┃\n");
		printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
		printf("      ┃ C┃  判断是否成环 ┃\n");
		printf("      ├━━┼━━━━━━━━━━━━━━━┤\n");
		printf("      ┃ D┃ 不做判断或查找┃\n");
		printf("      ┗━━┴━━━━━━━━━━━━━━━┛\n->");
		fflush(stdin);
		scanf("%c", &step2);
	}
	
//销毁链表并退出
	DestroyList(&head);
	printf("\n->已为您销毁链表，期待与您的下次使用！\n");
	
	getch();
	return 0;
}


//以下无用
//━
//┃
//┓
//┗
//┏
//┛	
//删除首节点
//	ElemType del;
//	Status beDelet;
//	beDelet = DeleteList(head, &del);
//	if ( beDelet )
//		printf("已删除");
//	else
//		printf("删除失败"); 
	
//	printf("%d\n", del);
	
	//遍历链表并输出 
//	TraverseList(head, PrintData);
	
	//搜索数据
//	int e;
//	printf("在此输入需要查找的数据："); 
//	scanf("%d", &e);
//	Status isFound = SearchList(head, e);
//	if ( isFound )
//		printf("找到了");
	
	//反转链表
//	Status beReverse = ReverseList(&head);
//	printf("%d", beReverse);
	
	//判断是否成环
//	loop:;
//	Status isLoop = IsLoopList(head);
//	if ( isLoop ) {
//		printf("\n经判断，这个链表成环，期待与您的下次见面！\n");
//		return 0; 
//	} else { 
//		printf("\n经判断，这个链表不成环\n");
//	} 
	//找到中间节点
//	LinkedList mid = FindMidNode(&head);
//	printf("%x", mid);

	//反转偶数节点 
//	ReverseEvenList(&head);
//	TraverseList(head, PrintData);

//销毁链表并退出
//	DestroyList(&head);
//	printf("\n已为您销毁链表，期待与您的下次见面！\n"); 
