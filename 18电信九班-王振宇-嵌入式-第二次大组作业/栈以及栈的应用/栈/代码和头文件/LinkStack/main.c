#include "../head/LinkStack.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	//��ӭҳ 
	printf("\n              ����������������������������������������������������");
	printf("\n              ��   ��ӭʹ����ջ������� ��");
	printf("\n              ����������������������������������������������������\n");
	printf("\n->����ͨ�������򵥵Ĳ��贴����һ����ջ�Դ������ݣ������Խ��м򵥵Ĳ���\n");
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
	printf("\n\n->���ڣ������Զ���ջ�������²���\n");
	printf("->    �������Щ�������������������������������\n");
	printf("      �� A��  ��ʼ����ջ   ��\n");
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

	LinkStack S;
	S.top = NULL;
	S.count = -1;
	char step1;
	scanf("%c", &step1);
	while (step1 != 'Z') {
		switch (step1) {
			//�Ƿ��ַ����뷴��
		default:
			printf("\n->�ף���߽�������ȷ�����أ�\n");
			break;
			//��ʼ����ջ 
		case 'A':
			if (S.count > -1) {
				printf("\n->�Ѿ���ʼ�����ˣ��������������\n");
				break;
			}
			initLStack(&S);
			printf("\n�����ɹ���");
			break;
			//��������
		case 'B':
			if (S.count < 0) {
				printf("\n->����û�г�ʼ����ջ\n");
				break;
			}
			int bePush = 0;
			printf("->������һ���������ݣ����ַ�������    ->");
			for (int data; scanf("%d", &data); pushLStack(&S, data)) {
				bePush = 1;
			}
			if (bePush)
				printf("->��ջ�ɹ���\n");
			else
				printf("->δ������Ч����\n");
			break;
			break;
			//ɾ������
		case 'C':
			if (S.count < 0) {
				printf("\n->����û�г�ʼ����ջ\n");
				break;
			}
			int beDelet;
			if (popLStack(&S, &beDelet))
				printf("\n->���� %d �ѱ�ɾ��\n", beDelet);
			else
				printf("\n->ջ���������ݣ�\n");
			break;
			//���ջ
		case 'D':
			if (S.count < 0) {
				printf("\n->����û�г�ʼ����ջ\n");
				break;
			}
			clearLStack(&S);
			printf("\n->��ջ�ѱ����\n");
			break;
			//����ջ
		case 'E':
			if (S.count < 0) {
				printf("\n->����û�г�ʼ����ջ\n");
				break;
			}
			destroyLStack(&S);
			printf("\n->��ջ�ѱ�����\n");
			break;
			//�鿴ջ������
		case 'F':
			if (S.count < 0) {
				printf("\n->����û�г�ʼ����ջ\n");
				break;
			}
			int lastData;
			if (getTopLStack(&S, &lastData))
				printf("\nջ�������Ϊ%d\n", lastData);
			else
				printf("\nջ����������\n");
			break;
			//�жϳ���
		case 'G':
			if (S.count < 0) {
				printf("\n->����û�г�ʼ����ջ\n");
				break;
			}
			int length;
			LStackLength(&S, &length);
			printf("\n->��ǰջ�������� %d ��\n", length);
			break;
		}
		if (S.count > -1) {
			printf("\n->��ǰջ������״̬Ϊ\n");
			StarkTraverse(&S);
		}

		while ((getchar()) != '\n') {};
		printf("\n\n->����Ҫ�����������\n");
		printf("->    �������Щ�������������������������������\n");
		printf("      �� A��  ��ʼ����ջ   ��\n");
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
	if (S.count < 0)
		destroyLStack(&S);
	printf("\n->��Ϊ��������ݣ��ڴ������´�ʹ�ã�\n");

	getch();
	return 0;
}