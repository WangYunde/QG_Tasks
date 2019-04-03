#include "../head/SqStack.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	//��ӭҳ 
	printf("\n              ����������������������������������������������������");
	printf("\n              ��  ��ӭʹ��˳��ջ���������");
	printf("\n              ����������������������������������������������������\n");
	printf("\n->����ͨ�������򵥵Ĳ��贴����һ��˳��ջ�Դ������ݣ������Խ��м򵥵Ĳ���\n");
	printf("\n    ��������������������������    ��������������������������    ��������������������������");
	printf("\n    ��  ��ʼ��ջ �� -->��  ��ֵ���� �� -->��  �����ж� ��");
	printf("\n    ��������������������������    ��������������������������    ��������������������������\n");
	printf("\n->�����ǿ�ʼ�ɣ�\n->Y.��ʼ    N.���ˣ����    ->");
	char step0;
	scanf("%c", &step0);
	while ((getchar()) != '\n') {};
	while (step0 != 'Y' && step0 != 'y') {
		if (step0 == 'N' || step0 == 'n') {
			printf("\n->��������~\n");
			getch();
			return 0;
		}
		printf("\n->�ף���߽�������ȷ�����أ�\n");
		printf("\n->�����ǿ�ʼ�ɣ�\n->Y.��ʼ    N.���ˣ����    ->");
		scanf("%c", &step0);
		while ((getchar()) != '\n') {};
	}

	//�����û�ѡ����в��� 
	printf("\n\n->���ڣ������Զ�˳��ջ�������²���\n");
	printf("->    �������Щ�������������������������������\n");
	printf("      �� A��  ��ʼ��˳��ջ ��\n");
	printf("      �������੥������������������������������\n");
	printf("      �� B��  ��������     ��\n");
	printf("      �������੥������������������������������\n");
	printf("      �� C��  ɾ������     ��\n");
	printf("      �������੥������������������������������\n");
	printf("      �� D��  ���ջ       ��\n");
	printf("      �������੥������������������������������\n");
	printf("      �� E��  ����ջ       ��\n");
	printf("      �������੥������������������������������\n");
	printf("      �� F��  �鿴ջ������ ��\n");
	printf("      �������੥������������������������������\n");
	printf("      �� G��  �жϳ���     ��\n");
	printf("      �������੥������������������������������\n");
	printf("      �� Z��  ���ٲ��˳�   ��\n");
	printf("      �������ة�������������������������������\n->");

	SqStack S;
	S.size = 0;
	char step1;
	scanf("%c", &step1);
	while (step1 != 'Z') {
		switch (step1) {
			//�Ƿ��ַ����뷴��
			default:
				printf("\n->�ף���߽�������ȷ�����أ�\n");
				break;
			//��ʼ��˳��ջ 
			case 'A':
				if (S.size) {
					printf("\n->�Ѿ���ʼ�����ˣ��������������\n");
					break;
				}
				int sizes = 1;
				printf("\n->��Ҫ������˳��ջ��ʼ��СΪ��    ->");
				while (!scanf("%d", &sizes) || sizes < 1) {
					while ((getchar()) != '\n') {};
					if (sizes < 1) 
						printf("\n˳��ջ�Ĵ�СӦ�ô���0�����������룡\n");
					else
						printf("\n->�ַ�Ϊ�Ƿ����룬����ȷ���룡\n");
					sizes = 1;
					printf("->��Ҫ������˳��ջ��ʼ��СΪ��    ->");
				}
				initStack(&S, sizes);
				printf("\n�����ɹ���");
				break;
			//��������
			case 'B':
				if (!S.size) {
					printf("\n->����û�г�ʼ��˳��ջ\n");
					break;
				}
				int bePush = 0;
				printf("->������һ���������ݣ����ַ�������    ->");
				for (int data; scanf("%d", &data); pushStack(&S, data)) {
					bePush = 1;
				}
				if (bePush)
					printf("->��ջ�ɹ���\n");
				else
					printf("->δ������Ч����\n");
				break;
			//ɾ������
			case 'C':
				if (!S.size) {
					printf("\n->����û�г�ʼ��˳��ջ\n");
					break;
				}
				int beDelet;
				if (popStack(&S, &beDelet))
					printf("\n->���� %d �ѱ�ɾ��\n", beDelet);
				else
					printf("\n->ջ���������ݣ�\n");
				break;
			//���ջ
			case 'D':
				if (!S.size) {
					printf("\n->����û�г�ʼ��˳��ջ\n");
					break;
				}
				clearStack(&S);
				printf("\n->˳��ջ�ѱ����\n");
				break;
			//����ջ
			case 'E':
				if (!S.size) {
					printf("\n->����û�г�ʼ��˳��ջ\n");
					break;
				}
				destroyStack(&S);
				printf("\n->˳��ջ�ѱ�����\n");
				break;
			//�鿴ջ������
			case 'F':
				if (!S.size) {
					printf("\n->����û�г�ʼ��˳��ջ\n");
					break;
				}
				int lastData;
				if (getTopStack(&S, &lastData))
					printf("\nջ�������Ϊ%d\n", lastData);
				else
					printf("\nջ����������\n");
				break;
			//�жϳ���
			case 'G':
				if (!S.size) {
					printf("\n->����û�г�ʼ��˳��ջ\n");
					break;
				}
				int length;
				stackLength(&S, &length);
				printf("\n->��ǰջ�������� %d ��\n", length);
				break;
		}
		if (S.size) {
			printf("\n->��ǰջ������״̬Ϊ\n");
			StarkTraverse(&S);
		}
			
		while ((getchar()) != '\n') {};
		printf("\n\n->����Ҫ�����������\n");
		printf("->    �������Щ�������������������������������\n");
		printf("      �� A��  ��ʼ��˳��ջ ��\n");
		printf("      �������੥������������������������������\n");
		printf("      �� B��  ��������     ��\n");
		printf("      �������੥������������������������������\n");
		printf("      �� C��  ɾ������     ��\n");
		printf("      �������੥������������������������������\n");
		printf("      �� D��  ���ջ       ��\n");
		printf("      �������੥������������������������������\n");
		printf("      �� E��  ����ջ       ��\n");
		printf("      �������੥������������������������������\n");
		printf("      �� F��  �鿴ջ������ ��\n");
		printf("      �������੥������������������������������\n");
		printf("      �� G��  �жϳ���     ��\n");
		printf("      �������੥������������������������������\n");
		printf("      �� Z��  ���ٲ��˳�   ��\n");
		printf("      �������ة�������������������������������\n->");
		scanf("%c", &step1);
	}

	//���ٲ��˳�
	if (S.size)
		destroyStack(&S);
	printf("\n->��Ϊ��������ݣ��ڴ������´�ʹ�ã�\n");

	getch();
	return 0;
}
/*	SqStack S;
	int sizes = 100;
	initStack(&S, sizes);
	for (int data; scanf("%d", &data); pushStack(&S, data)) {}
	StarkTraverse(&S);
	printf("\n%x��Ԫ����%d����С%d\n", S.elem, S.top + 1, S.size);

	int beDelet;
	popStack(&S, &beDelet);
	printf("\n->%d has been deleted.\n", beDelet);
	StarkTraverse(&S);
	printf("\n%x��Ԫ����%d����С%d\n", S.elem, S.top + 1, S.size);

	clearStack(&S);
	StarkTraverse(&S);
	printf("\n%x��Ԫ����%d����С%d\n", S.elem, S.top + 1, S.size);

	int lastData;
	if (getTopStack(&S, &lastData))
		printf("\nջ�������Ϊ%d\n", lastData);
	else
		printf("\nջ����������\n");
	StarkTraverse(&S);
	printf("\n%x��Ԫ����%d����С%d\n", S.elem, S.top + 1, S.size);

	if (isEmptyStack(&S))
		printf("ջ��\n");
	else
		printf("ջ�ǿ�\n");

	destroyStack(&S);
	printf("\nջ����\n");
	StarkTraverse(&S);
	printf("\n%x��Ԫ����%d����С%d\n", S.elem, S.top + 1, S.size);
	*/