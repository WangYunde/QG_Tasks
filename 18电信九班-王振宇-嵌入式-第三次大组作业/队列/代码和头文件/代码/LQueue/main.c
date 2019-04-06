#include "../../ͷ�ļ�/LQueue.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	//��ӭҳ 
	printf("\n              ������������������������������������������������������������");
	printf("\n              ��  ��ӭʹ�÷������������������");
	printf("\n              ������������������������������������������������������������\n");
	printf("\n->�˶��п��Ի�ϴ�����͡������͡��ַ������ݣ���������ǰָ����������\n");
	printf("\n    ������������������������������    ��������������������������    ������������������������������");
	printf("\n    ��  ��ʼ������ �� -->��  �������� �� -->��  ���Һ��ж� ��");
	printf("\n    ������������������������������    ��������������������������    ������������������������������\n");
	printf("\n->�����ǿ�ʼ�ɣ�\n->Y.��ʼ    N.���ˣ����    ->");
	char step0;
	scanf_s("%c", &step0);
	while ((getchar()) != '\n') {};
	while (step0 != 'Y' && step0 != 'y') {
		if (step0 == 'N' || step0 == 'n') {
			printf("\n->��������~\n");
			getch();
			return 0;
		}
		printf("\n->�ף���߽�������ȷ�����أ�\n");
		printf("\n->�����ǿ�ʼ�ɣ�\n->Y.��ʼ    N.���ˣ����    ->");
		scanf_s("%c", &step0);
		while ((getchar()) != '\n') {};
	}
	LQueue Q;
	Q.length = -1;
	char* s;

	//�����û�ѡ����в��� 
	printf("\n\n->���ڣ������ԶԶ��н������²���\n");
	printf("->    �������Щ�������������������������������\n");
	printf("      �� A��  ��ʼ������   ��\n");
	printf("      �������੥������������������������������\n");
	printf("      �� B��  ��������     ��\n");
	printf("      �������੥������������������������������\n");
	printf("      �� C��  ɾ������     ��\n");
	printf("      �������੥������������������������������\n");
	printf("      �� D��  ��ն���     ��\n");
	printf("      �������੥������������������������������\n");
	printf("      �� E��  ���ٶ���     ��\n");
	printf("      �������੥������������������������������\n");
	printf("      �� F��  �鿴�������� ��\n");
	printf("      �������੥������������������������������\n");
	printf("      �� G��  �жϳ���     ��\n");
	printf("      �������੥������������������������������\n");
	printf("      �� Z��  ���ٲ��˳�   ��\n");
	printf("      �������ة�������������������������������\n->");
	char step1;
	scanf_s("%c", &step1);
	while ((getchar()) != '\n') {};
	while (step1 != 'Z') {
		switch (step1) {
			//�Ƿ��ַ����뷴��
		default:
			printf("\n->�ף���߽�������ȷ�����أ�\n");
			break;
			//��ʼ������
		case 'A':
			if (Q.length > -1) {
				printf("\n->�Ѿ���ʼ�����ˣ��������������\n");
				break;
			}
			InitLQueue(&Q);
			printf("\n->�����ɹ���");
			break;
			//��������
		case 'B':
			if (Q.length == -1) {
				printf("\n->����û�г�ʼ�����У�\n");
				break;
			}
			s = malloc(1000 * sizeof(char));
			printf("->���������ݣ��س��Խ�����    ->");
			if (!judgeAndEn(&Q, s))
				printf("->��δ��������\n");
			break;
			//ɾ������
		case 'C':
			if (Q.length == -1) {
				printf("\n->����û�г�ʼ�����У�\n");
				break;
			}
			if (DeLQueue(&Q))
				printf("\n->��ɾ��ԭ��������\n");
			else
				printf("\n->�������������ݣ�\n");
			break;
			//��ն���
		case 'D':
			if (Q.length == -1) {
				printf("\n->����û�г�ʼ�����У�\n");
				break;
			}
			ClearLQueue(&Q);
			printf("\n->�����ѱ����\n");
			break;
			//���ٶ���
		case 'E':
			if (Q.length == -1) {
				printf("\n->����û�г�ʼ�����У�\n");
				break;
			}
			DestoryLQueue(&Q);
			printf("\n->�����ѱ�����\n");
			break;
			//�鿴��������
		case 'F':
			if (Q.length == -1) {
				printf("\n->����û�г�ʼ�����У�\n");
				break;
			}
			if (Q.length == 0)
				printf("\n->������������\n");
			else {
				char* lastData = malloc(sizeof(char));
				GetHeadLQueue(&Q, lastData);
				//printf(" %s ", lastData);
			}
			break;
			//�жϳ���
		case 'G':
			if (Q.length == -1) {
				printf("\n->����û�г�ʼ�����У�\n");
				break;
			}
			printf("\n->��ǰ������������ %d ��\n", LengthLQueue(&Q));
			break;
		}

		if (Q.length > -1) {
			printf("\n->��ǰ����״̬Ϊ\n");
			TraverseLQueue(Q, LPrint);
		}
		while ((getchar()) != '\n') {};
		printf("\n\n->����Ҫ�����������\n");
		printf("->    �������Щ�������������������������������\n");
		printf("      �� A��  ��ʼ������   ��\n");
		printf("      �������੥������������������������������\n");
		printf("      �� B��  ��������     ��\n");
		printf("      �������੥������������������������������\n");
		printf("      �� C��  ɾ������     ��\n");
		printf("      �������੥������������������������������\n");
		printf("      �� D��  ��ն���     ��\n");
		printf("      �������੥������������������������������\n");
		printf("      �� E��  ���ٶ���     ��\n");
		printf("      �������੥������������������������������\n");
		printf("      �� F��  �鿴�������� ��\n");
		printf("      �������੥������������������������������\n");
		printf("      �� G��  �жϳ���     ��\n");
		printf("      �������੥������������������������������\n");
		printf("      �� Z��  ���ٲ��˳�   ��\n");
		printf("      �������ة�������������������������������\n->");
		scanf_s("%c", &step1);
		while ((getchar()) != '\n') {};
	}
	
	if (Q.length > -1)
		DestoryLQueue(&Q);
	printf("\n->��Ϊ��������ݣ��ڴ������´�ʹ�ã�\n");

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
	printf("ͷ%p����%p��β%p������%d\n\n", Q.front, Q.front->next, Q.rear, LengthLQueue(&Q));

	DeLQueue(&Q);
	TraverseLQueue(Q, LPrint);
	printf("ͷ%p����%p��β%p������%d\n\n", Q.front, Q.front->next, Q.rear, LengthLQueue(&Q));

	//ClearLQueue(&Q);
	//TraverseLQueue(Q, LPrint);
	//printf("ͷ%p����%p��β%p������%d\n\n", Q.front, Q.front->next, Q.rear, LengthLQueue(&Q));
	
	void* lastData = malloc(sizeof(char));
	if (GetHeadLQueue(&Q, &lastData))
		printf("\n��������Ϊ%c\n", *(char*)lastData);
	else
		printf("\n������������\n");

	if (IsEmptyLQueue(&Q))
		printf("���п�\n");
	else
		printf("���зǿ�\n");

	DestoryLQueue(&Q);*/