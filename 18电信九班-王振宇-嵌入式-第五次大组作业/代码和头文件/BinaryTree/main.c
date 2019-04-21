#include "../head/BinaryTree.h"

int main()
{
	//��ʼ��
	BiTree root = NULL;
	int beInit = 0;
	//InitBiTree(&root);
	char *definition = malloc(100 * sizeof(char)); //++2*3-74/84

	//��ӭҳ
	printf("\n                    ������������������������������������������������");
	printf("\n                    ��    ���춼��ֲ����    ��");
	printf("\n                    ������������������������������������������������\n");
	printf("\n-> �������һ�������´δ�һ����û�ˣ��������淶������������orz <-\n");
	printf("\n    ����������������������������������    ������������������������������    ����������������������������������");
	printf("\n    �����ڿӣ���ʼ�� �� -->�� ���������룩�� -->�� ժ���ӣ��������");
	printf("\n    ����������������������������������    ������������������������������    ����������������������������������\n");
	printf("\n->�����ڿӣ�\n->Y.�ٷϻ����ò�����    N.���ˣ����    ->");
	char step0;
	scanf_s("%c", &step0);
	while ((getchar()) != '\n') {};
	while (step0 != 'Y' && step0 != 'y') {
		if (step0 == 'N' || step0 == 'n') {
			printf("\n->ʦ������~\n");
			getch();
			return 0;
		}
		printf("\n->���Ӷ������ˣ��������Һ�Ϊ��\n");
		printf("\n->�����ڿӣ�\n->Y.�ٷϻ����ò�����    N.���ˣ����    ->");
		scanf_s("%c", &step0);
		while ((getchar()) != '\n') {};
	}
	system("cls");
	printf("\n\n->���ӡ����綼�������ˣ���֪�����ɶ��\n");
	printf("->        �������Щ���������������������������������\n");
	printf("          �� A��  �ڿӣ���ʼ������\n");
	printf("          �������੥��������������������������������\n");
	printf("          �� B��  �������(����)��\n");
	printf("          �������੥��������������������������������\n");
	printf("          �� C��  ����ֿ���    ��\n");
	printf("          �������੥��������������������������������\n");
	printf("          �� D��  ��ʽ����(����)��\n");
	printf("          �������੥��������������������������������\n");
	printf("          �� S��  ǰ׺���ʽ���㩧\n");
	printf("      �������Щة����ة��������������������������������ة�����������\n");
	printf("      �� Z��  ������Ԫ�������������  ��\n");
	printf("      �������ة�����������������������������������������������������\n->");
	char step1;
	scanf_s("%c", &step1);
	while ((getchar()) != '\n') {};
	while (step1 != 'Z') {
		switch (step1) {
		case 'A':
			if (beInit == 1) {
				printf("->�Ѿ��ڹ��ˣ���Щ��İ�\n");
				break;
			}
			else if (beInit == 2) {
				printf("->�Ѿ��������ˣ���Щ��İ�\n");
				break;
			}
			beInit = 1;
			printf("->һ��ֱ��ʮ�׵Ĵ���Ѿ��ںã��͵���������\n");
			break;
		case 'B':
			if (!beInit) {
				printf("->����û��������û�ӣ���֪Ҫ��ɶ��δ��ʼ����\n");
				break;
			}
			beInit = 0;
			DestroyBiTree(root);
			root = NULL;
			printf("->�����ɹ���ľ��+1\n");
			break;
		case 'C':
			if (!beInit) {
				printf("->����֮ǰ�������������ڸ��ӣ���δ��ʼ����\n");
				break;
			}
			else if (beInit == 2) {
				printf("->һ�����Ĺ��ӻ������Ե��𣿣���������\n");
				break;
			}
			beInit = 2;
			printf("->����ʱ���ȴӸ���ʼ���������룬���磺AB#DF##G##C#E#H## ����    ->");
			CreateBiTree0(&root);
			printf("->�����ɹ���\n");
			while ((getchar()) != '\n') {};
			break;
		case 'D':
			if (!beInit) {
				printf("->����û����������û�пӣ�δ��ʼ����\n");
				break;
			}
			else if (beInit == 1) {
				printf("->����ֻ��һ���ӣ������ݣ�\n");
				break;
			}
			printf("\n���������");
			PreOrderTraverse(root, Print);
			printf("\n���������");
			InOrderTraverse(root, Print);
			printf("\n����������");
			PostOrderTraverse(root, Print);
			printf("\n��α�����");
			LevelOrderTraverse(root, Print);
			break;
		case 'S':
			while (1) {
				printf("\n->����ȷ����һ��ǰ׺���ʽ���磺++2*3-74/84 ����    ->");
				scanf("%s", definition);
				getchar();
				CreateBiTree(&root, definition);
				printf("���������");
				PreOrderTraverse(root, Print);
				printf("\n���������");
				InOrderTraverse(root, Print);
				printf("\n����������");
				PostOrderTraverse(root, Print);
				printf("\n��α�����");
				LevelOrderTraverse(root, Print);
				Value(&root);
				printf("\n������Ϊ��%d\n", root->data - '0');
				nextChar(NULL);
			}
			break;
		default:
			printf("\n->���簡���ܲ��ܿ�쳤��ʦ�ְ����ܲ��ܺú�����~\n");
			break;
		}
		while ((getchar()) != '\n') {};
		system("cls");
		printf("\n-���ˣ���֪�������ɶ��\n");
		printf("->        �������Щ���������������������������������\n");
		printf("          �� A��  �ڿӣ���ʼ������\n");
		printf("          �������੥��������������������������������\n");
		printf("          �� B��  �������(����)��\n");
		printf("          �������੥��������������������������������\n");
		printf("          �� C��  ����ֿ���    ��\n");
		printf("          �������੥��������������������������������\n");
		printf("          �� D��  ��ʽ����(����)��\n");
		printf("          �������੥��������������������������������\n");
		printf("          �� S��  ǰ׺���ʽ���㩧\n");
		printf("      �������Щة����ة��������������������������������ة�����������\n");
		printf("      �� Z��  ������Ԫ�������������  ��\n");
		printf("      �������ة�����������������������������������������������������\n->");
		scanf_s("%c", &step1);
		while ((getchar()) != '\n') {};
	}
	if (beInit) {
		DestroyBiTree(root);
		root = NULL;
	}
	free(definition);
	printf("->���+99999\nʦ���ټ���");

	getchar();
	return 0;
}
	/*printf("������");
	CreateBiTree(&root, definition); //AB#DF##G##C#E#H##
	getchar();

	printf("\n���������");
	PreOrderTraverse(root, Print);

	printf("\n���������");
	InOrderTraverse(root, Print);

	printf("\n����������");
	PostOrderTraverse(root, Print);

	printf("\n��α�����");
	LevelOrderTraverse(root, Print);

	Value(&root);
	printf("\n������Ϊ��%d", root->data - '0');

	DestroyBiTree(root);
	root = NULL;*/