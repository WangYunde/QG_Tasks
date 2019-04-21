#include "../head/BinaryTree.h"

int main()
{
	//初始化
	BiTree root = NULL;
	int beInit = 0;
	//InitBiTree(&root);
	char *definition = malloc(100 * sizeof(char)); //++2*3-74/84

	//欢迎页
	printf("\n                    ┏━━━━━━━━━━━━━━━━━━━━━━┓");
	printf("\n                    ┃    天天都是植树节    ┃");
	printf("\n                    ┗━━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf("\n-> 这次种下一棵树，下次打看一看就没了；种树不规范，振宇两行泪orz <-\n");
	printf("\n    ┏━━━━━━━━━━━━━━━┓    ┏━━━━━━━━━━━━━┓    ┏━━━━━━━━━━━━━━━┓");
	printf("\n    ┃（挖坑）初始化 ┃ -->┃ 种树（输入）┃ -->┃ 摘果子（输出）┃");
	printf("\n    ┗━━━━━━━━━━━━━━━┛    ┗━━━━━━━━━━━━━┛    ┗━━━━━━━━━━━━━━━┛\n");
	printf("\n->当场挖坑？\n->Y.少废话，拿铲子来    N.算了，告辞    ->");
	char step0;
	scanf_s("%c", &step0);
	while ((getchar()) != '\n') {};
	while (step0 != 'Y' && step0 != 'y') {
		if (step0 == 'N' || step0 == 'n') {
			printf("\n->师兄慢走~\n");
			getch();
			return 0;
		}
		printf("\n->铲子都拿来了，您这样我很为难\n");
		printf("\n->当场挖坑？\n->Y.少废话，拿铲子来    N.算了，告辞    ->");
		scanf_s("%c", &step0);
		while ((getchar()) != '\n') {};
	}
	system("cls");
	printf("\n\n->铲子、树苗都安排上了，不知您想干啥？\n");
	printf("->        ┏━━┬━━━━━━━━━━━━━━━━┓\n");
	printf("          ┃ A┃  挖坑（初始化）┃\n");
	printf("          ├━━┼━━━━━━━━━━━━━━━━┤\n");
	printf("          ┃ B┃  砍树填坑(销毁)┃\n");
	printf("          ├━━┼━━━━━━━━━━━━━━━━┤\n");
	printf("          ┃ C┃  随便种颗树    ┃\n");
	printf("          ├━━┼━━━━━━━━━━━━━━━━┤\n");
	printf("          ┃ D┃  花式爬树(遍历)┃\n");
	printf("          ├━━┼━━━━━━━━━━━━━━━━┤\n");
	printf("          ┃ S┃  前缀表达式计算┃\n");
	printf("      ┏━━┬┴━━┴━━━━━━━━━━━━━━━━┴━━━━━┓\n");
	printf("      ┃ Z┃  砍树换元宝，刀刀九万九  ┃\n");
	printf("      ┗━━┴━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n->");
	char step1;
	scanf_s("%c", &step1);
	while ((getchar()) != '\n') {};
	while (step1 != 'Z') {
		switch (step1) {
		case 'A':
			if (beInit == 1) {
				printf("->已经挖过了，做些别的吧\n");
				break;
			}
			else if (beInit == 2) {
				printf("->已经种下树了，做些别的吧\n");
				break;
			}
			beInit = 1;
			printf("->一个直径十米的大坑已经挖好，就等您栽树了\n");
			break;
		case 'B':
			if (!beInit) {
				printf("->这里没树，甚至没坑，不知要砍啥（未初始化）\n");
				break;
			}
			beInit = 0;
			DestroyBiTree(root);
			root = NULL;
			printf("->砍树成功！木材+1\n");
			break;
		case 'C':
			if (!beInit) {
				printf("->种树之前，考虑以下先挖个坑？（未初始化）\n");
				break;
			}
			else if (beInit == 2) {
				printf("->一棵树的果子还不够吃的吗？（已有树）\n");
				break;
			}
			beInit = 2;
			printf("->种树时请先从根开始埋（先序输入，例如：AB#DF##G##C#E#H## ）：    ->");
			CreateBiTree0(&root);
			printf("->种树成功！\n");
			while ((getchar()) != '\n') {};
			break;
		case 'D':
			if (!beInit) {
				printf("->这里没有树，甚至没有坑（未初始化）\n");
				break;
			}
			else if (beInit == 1) {
				printf("->这里只有一个坑（无数据）\n");
				break;
			}
			printf("\n先序遍历：");
			PreOrderTraverse(root, Print);
			printf("\n中序遍历：");
			InOrderTraverse(root, Print);
			printf("\n后续遍历：");
			PostOrderTraverse(root, Print);
			printf("\n层次遍历：");
			LevelOrderTraverse(root, Print);
			break;
		case 'S':
			while (1) {
				printf("\n->请正确输入一个前缀表达式（如：++2*3-74/84 ）：    ->");
				scanf("%s", definition);
				getchar();
				CreateBiTree(&root, definition);
				printf("先序遍历：");
				PreOrderTraverse(root, Print);
				printf("\n中序遍历：");
				InOrderTraverse(root, Print);
				printf("\n后续遍历：");
				PostOrderTraverse(root, Print);
				printf("\n层次遍历：");
				LevelOrderTraverse(root, Print);
				Value(&root);
				printf("\n运算结果为：%d\n", root->data - '0');
				nextChar(NULL);
			}
			break;
		default:
			printf("\n->树苗啊你能不能快快长大，师兄啊您能不能好好输入~\n");
			break;
		}
		while ((getchar()) != '\n') {};
		system("cls");
		printf("\n-妥了，不知您还想干啥？\n");
		printf("->        ┏━━┬━━━━━━━━━━━━━━━━┓\n");
		printf("          ┃ A┃  挖坑（初始化）┃\n");
		printf("          ├━━┼━━━━━━━━━━━━━━━━┤\n");
		printf("          ┃ B┃  砍树填坑(销毁)┃\n");
		printf("          ├━━┼━━━━━━━━━━━━━━━━┤\n");
		printf("          ┃ C┃  随便种颗树    ┃\n");
		printf("          ├━━┼━━━━━━━━━━━━━━━━┤\n");
		printf("          ┃ D┃  花式爬树(遍历)┃\n");
		printf("          ├━━┼━━━━━━━━━━━━━━━━┤\n");
		printf("          ┃ S┃  前缀表达式计算┃\n");
		printf("      ┏━━┬┴━━┴━━━━━━━━━━━━━━━━┴━━━━━┓\n");
		printf("      ┃ Z┃  砍树换元宝，刀刀九万九  ┃\n");
		printf("      ┗━━┴━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n->");
		scanf_s("%c", &step1);
		while ((getchar()) != '\n') {};
	}
	if (beInit) {
		DestroyBiTree(root);
		root = NULL;
	}
	free(definition);
	printf("->金币+99999\n师兄再见！");

	getchar();
	return 0;
}
	/*printf("种树：");
	CreateBiTree(&root, definition); //AB#DF##G##C#E#H##
	getchar();

	printf("\n先序遍历：");
	PreOrderTraverse(root, Print);

	printf("\n中序遍历：");
	InOrderTraverse(root, Print);

	printf("\n后续遍历：");
	PostOrderTraverse(root, Print);

	printf("\n层次遍历：");
	LevelOrderTraverse(root, Print);

	Value(&root);
	printf("\n运算结果为：%d", root->data - '0');

	DestroyBiTree(root);
	root = NULL;*/