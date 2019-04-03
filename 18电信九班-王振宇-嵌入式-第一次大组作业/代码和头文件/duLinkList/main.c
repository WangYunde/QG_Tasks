#include "../head/duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
//��ӭҳ 
	printf("\n              ����������������������������������������������������");
	printf("\n              ��  ��ӭʹ��˫�������������");
	printf("\n              ����������������������������������������������������\n");
	printf("\n->����ͨ�������򵥵Ĳ��贴����һ��˫�����Դ������ݣ������Խ��м򵥵��޸�\n");
	printf("\n    ��������������������������    ��������������������������    ��������������������������");
	printf("\n    ��  ������ֵ �� -->��  ��ֵ�޸� �� -->��  �����ж� ��");
	printf("\n    ��������������������������    ��������������������������    ��������������������������\n");
	printf("\n->�����ǿ�ʼ�ɣ�\n->Y.��ʼ    N.���ˣ����    ->");
	char step0;
	scanf("%c", &step0);
	if ( step0 != 'Y' && step0 != 'y' ) {
		printf("\n->��������~\n");
		return 0;
	}
	
//�����û����봴������ 
	printf("\n->������������Ҫ������������Ҫ��ŵ���ֵ���Կո��س����\n->��������ʱ�����ַ����س���ֹͣ��\n->");
	Status beCreat = SUCCESS;
	//����ͷָ�롢ͷ�ڵ�
	DuLinkedList head;
	beCreat = InitList_DuL(&head);
	if ( beCreat == ERROR ) {
		printf("->Oooops������ͷ�ڵ�ʧ�ܣ��´μ���");
		return 0; 
	} 
	//�ӳ����������ַ�ֹͣ
	DuLinkedList p, q;
	p = head;
	q = (DuLinkedList)malloc(sizeof(DuLNode));
	int i = 0; //�����ж��Ƿ�Ϊ������
	while ( scanf("%d", &q->data) && q ) {
		InsertAfterList_DuL(p, q);
		p = q;
		q = (DuLinkedList)malloc(sizeof(DuLNode));
		i = 1; 
	}
	if ( i == 0 ) {
		printf("\n->��Ǹ���������޷����к����������ټ���\n");
		return 0;
	}
	if ( q ) {
		free(q);
		fflush(stdin); //��ջ������ַ�
	} else {
		printf("Oooops���ڴ������˵����⣬�´μ���");
		return 0; //�����쳣���˳� 
	}
	printf("\n->��ϲ�������ѳɹ�������������Ϊ��\n->");
	TraverseList_DuL(head, PrintData); //�����������
	
//�����û�ѡ���������в��� 
	printf("\n\n->���ڣ������Զ�����������²���\n");
	printf("->    �������Щ�������������������������������\n");
	printf("      �� A��  ������ڵ� ��\n");
	printf("      �������੥������������������������������\n");
	printf("      �� B��  ��ǰ����ڵ� ��\n");
	printf("      �������੥������������������������������\n");
	printf("      �� C��  ɾ���ڵ�     ��\n");
	printf("      �������੥������������������������������\n");
	printf("      �� D��  �����޸�     ��\n");
	printf("      �������ة�������������������������������\n->");
	Status isWork = SUCCESS; //��¼ִ�н�� 
	char step1;
	scanf("%c", &step1);
	while ( step1 != 'D' ) {
		switch (step1) {
			//������ڵ� 
			case 'A':
				printf("\n->��ϣ������Ľڵ���ֵΪ��    ->");
				//�½��ڵ㲢�������� 
				DuLinkedList qa;
				InitList_DuL(&qa);
				scanf("%d", &(qa->data));
				//�ҵ������
				printf("->�������ĸ��ڵ���ֵ֮��    ->");
				ElemType ea;
				scanf("%d", &ea);
				DuLinkedList pa = SearchData(head, ea);
				//ִ�в���
				if ( pa )
					isWork = InsertAfterList_DuL(pa, qa);
				else
					printf("\n->��Ǹ��δ�ҵ�����ڵ���ֵ");
				break;
			//��ǰ����ڵ� 
			case 'B':
				printf("\n->��ϣ������Ľڵ���ֵΪ��    ->");
				//�½��ڵ㲢�������� 
				DuLinkedList qb;
				InitList_DuL(&qb);
				scanf("%d", &(qb->data));
				//�ҵ������
				printf("->�������ĸ��ڵ���ֵ֮ǰ��    ->");
				ElemType eb;
				scanf("%d", &eb);
				DuLinkedList pb = SearchData(head, eb);
				//ִ�в���
				if ( pb )
					isWork = InsertBeforeList_DuL(pb, qb);
				else
					printf("\n->��Ǹ��δ�ҵ�����ڵ���ֵ");
				break;
			//ɾ���ڵ� 
			case 'C':
				printf("\n->��ϣ��ɾ���ĸ��ڵ���ֵ֮��Ľڵ㣿�������һ~�����ڶ��Ľڵ�����    ->");
				ElemType ec;
				scanf("%d", &ec);
				DuLinkedList pc = SearchData(head, ec);
				if( !DeleteList_DuL(pc, &ec) )
					printf("\n->��Ǹ����������");
				break;
			//�Ƿ��ַ����뷴�� 
			default:
				printf("\n->����������ȷ���ַ���\n");
		}
		if ( isWork ) {
			printf("\n->��ǰ����Ϊ��\n->");
			TraverseList_DuL(head, PrintData); //�����������
		} else {
			printf("\n->Oooops���ƺ����˵����⣬�´μ���");
			return 0;
		}
		printf("\n\n->����Ҫ��������ģ�\n");
		printf("->    �������Щ�������������������������������\n");
		printf("      �� A��  ������ڵ� ��\n");
		printf("      �������੥������������������������������\n");
		printf("      �� B��  ��ǰ����ڵ� ��\n");
		printf("      �������੥������������������������������\n");
		printf("      �� C��  ɾ���ڵ�     ��\n");
		printf("      �������੥������������������������������\n");
		printf("      �� D��  �����޸�     ��\n");
		printf("      �������ة�������������������������������\n->");
		fflush(stdin);
		scanf("%c", &step1);
	}
	
//���������˳�
	DestroyList_DuL(&head);
	printf("\n->��Ϊ�����������ڴ��������´�ʹ�ã�\n");
	
	return 0;
}


//�������� 
//�����û�ѡ�����������жϻ���� 
//	printf("\n\n->���ڣ������Զ�������в���\n");
//	printf("->    �������Щ�������������������������������\n");
//	printf("      �� A��  ���ҽڵ���ֵ ��\n");
//	printf("      �������੥������������������������������\n");
//	printf("      �� B��  ��������     ��\n");
//	printf("      �������ة�������������������������������\n->");
//	isWork = SUCCESS; //��¼ִ�н�� 
//	char step2;
//	fflush(stdin);
//	scanf("%c", &step2);
//	while ( step2 != 'B' ) {
//		switch (step2) {
//			//���ҽڵ���ֵ
//			case 'A':
//				printf("\n->�ڴ�������Ҫ���ҵ����ݣ�    ->"); 
//				int data;
//				scanf("%d", &data);
//				Status isFound = SearchList_DuL(head, data);
//				if ( isFound )
//					printf("\n->���������������\n");
//				else
//					printf("\n->�����в������������\n");
//				break;
//			//�Ƿ��ַ����뷴�� 
//			default:
//				printf("\n->����������ȷ���ַ���\n");
//		}
//		if ( !isWork ) {
//			printf("->Oooops���ƺ����˵����⣬�´μ���");
//			return 0;
//		}
//		printf("\n\n->���Ƿ���Ҫ���ң�\n");
//		printf("->    �������Щ�������������������������������\n");
//		printf("      �� A��  ���ҽڵ���ֵ ��\n");
//		printf("      �������੥������������������������������\n");
//		printf("      �� B��  ��������     ��\n");
//		printf("      �������ة�������������������������������\n->");
//		fflush(stdin);
//		scanf("%c", &step2);
//	}
