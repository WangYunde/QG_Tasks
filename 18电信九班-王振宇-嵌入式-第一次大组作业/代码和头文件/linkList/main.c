#include "../head/linkedList.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
//��ӭҳ 
	printf("\n              ����������������������������������������������������");
	printf("\n              ��  ��ӭʹ�õ��������������");
	printf("\n              ����������������������������������������������������\n");
	printf("\n->����ͨ�������򵥵Ĳ��贴����һ���������Դ������ݣ������Խ��м򵥵��޸�\n");
	printf("\n    ��������������������������    ��������������������������    ��������������������������");
	printf("\n    ��  ������ֵ �� -->��  ��ֵ�޸� �� -->��  �����ж� ��");
	printf("\n    ��������������������������    ��������������������������    ��������������������������\n");
	printf("\n->�����ǿ�ʼ�ɣ�\n->Y.��ʼ    N.���ˣ����    ->");
	char step0;
	scanf("%c", &step0);
	fflush(stdin);
	while ( step0 != 'Y' && step0 != 'y' ) {
		printf("\n->�ף���߽�������ȷ�����أ�\n");
		if ( step0 == 'N' && step0 == 'n' ) {
		printf("\n->��������~\n");
		getch(); 
		return 0;
		}
		printf("\n->�����ǿ�ʼ�ɣ�\n->Y.��ʼ    N.���ˣ����    ->");
		scanf("%c", &step0);
		fflush(stdin);
	} 
	
	
//�����û����봴������ 
	printf("\n->������������Ҫ������������Ҫ��ŵ���ֵ���Կո��س����\n->��������ʱ�����ַ����س���ֹͣ��\n->");
	Status beCreat = SUCCESS;
	//����ͷָ�롢ͷ�ڵ�
	LinkedList head;
	beCreat = InitList(&head);
	if ( beCreat == ERROR ) {
		printf("->Oooops������ͷ�ڵ�ʧ�ܣ��´μ���");
		getch();
		return 0;
	} 
	//�ӳ����������ַ�ֹͣ
	LinkedList p, q;
	p = head;
	q = (LinkedList)malloc(sizeof(LNode));
	int i = 0; //�����ж��Ƿ�Ϊ������
	while ( scanf("%d", &q->data) && q ) {
		InsertList(p, q);
		p = q;
		q = (LinkedList)malloc(sizeof(LNode));
		i = 1; 
	}
	if ( i == 0 ) {
		printf("\n->��Ǹ���������޷����к����������ټ���\n");
		getch();
		return 0;
	}
	if ( q ) {
		free(q);
		fflush(stdin); //��ջ������ַ�
	} else {
		printf("Oooops���ڴ������˵����⣬�´μ���");
		getch();
		return 0; //�����쳣���˳� 
	}
	printf("\n->��ϲ�������ѳɹ�������������Ϊ��\n->");
	TraverseList(head, PrintData); //�����������
	
//�����û�ѡ���������в��� 
	printf("\n\n->���ڣ������Զ�����������²���\n");
	printf("->    �������Щ�������������������������������\n");
	printf("      �� A��  ����ڵ�     ��\n");
	printf("      �������੥������������������������������\n");
	printf("      �� B��  ɾ���ڵ�     ��\n");
	printf("      �������੥������������������������������\n");
	printf("      �� C��  ��ת����     ��\n");
	printf("      �������੥������������������������������\n");
	printf("      �� D��  ��תż���ڵ� ��\n");
	printf("      �������੥������������������������������\n");
	printf("      �� E��  ����ɻ�     ��\n");
	printf("      �������੥������������������������������\n");
	printf("      �� F��  �����޸�     ��\n");
	printf("      �������ة�������������������������������\n->");
	Status isWork = SUCCESS; //��¼ִ�н�� 
	Status isRight;
	char step1;
	scanf("%c", &step1);
	while ( step1 != 'F' ) {
		switch (step1) {
			//����ڵ� 
			case 'A':
				isRight = SUCCESS;
				printf("\n->��ϣ������Ľڵ���ֵΪ��    ->");
				//�½��ڵ㲢�������� 
				LinkedList qa;
				InitList(&qa);
				isRight = scanf("%d", &(qa->data));
				if ( isRight == ERROR ) {
					printf("\n->�ף���߽�������ȷ�����أ�\n");
					fflush(stdin);
					break;
				}
				//�ҵ������
				printf("->�������ĸ��ڵ���ֵ֮��    ->");
				ElemType ea;
				isRight = scanf("%d", &ea);
				if ( isRight == ERROR ) {
					printf("\n->�ף���߽�������ȷ�����أ�\n");
					fflush(stdin);
					break;
				}
				LinkedList pa = SearchData(head, ea);
				//ִ�в���
				if ( pa )
					isWork = InsertList(pa, qa);
				else
					printf("\n->��Ǹ��δ�ҵ�����ڵ���ֵ");
				break;
			//ɾ���ڵ� 
			case 'B':
				isRight = SUCCESS;
				printf("\n->��ϣ��ɾ���ĸ��ڵ���ֵ֮��Ľڵ㣿�������һ~�����ڶ��Ľڵ�����    ->");
				ElemType eb;
				isRight = scanf("%d", &eb);
				if ( isRight == ERROR ) {
					printf("\n->�ף���߽�������ȷ�����أ�\n");
					fflush(stdin);
					break;
				}
				LinkedList pb = SearchData(head, eb);
				if( !DeleteList(pb, &eb) )
					printf("\n->��Ǹ����������");
				break;
			//��ת���� 
			case 'C':
				isWork = ReverseList(&head);
				break;
			//��תż���ڵ�
			case 'D':
				ReverseEvenList(&head); 
				break;
			//����ɻ�
			case 'E':
				printf("->���ĸ��ڵ���ֵ�ɻ���    ");
				ElemType ee;
				isRight = scanf("%d", &ee);
				if ( isRight == ERROR ) {
					printf("\n->�ף���߽�������ȷ�����أ�\n");
					fflush(stdin);
					break;
				}
				p->next = SearchData(head, ee);
				printf("\n->ִ����ϣ����������򽫼����ĺ�������Ƿ�ɻ�\n\n��\n��\n��\n��\n��\n"); 
				goto loop;
			//�Ƿ��ַ����뷴�� 
			default:
				printf("\n->�ף���߽�������ȷ�����أ�\n");
		}
		if ( isWork ) {
			printf("\n->��ǰ����Ϊ��\n->");
			TraverseList(head, PrintData); //�����������
		} else {
			printf("\n->Oooops���ƺ����˵����⣬�´μ���");
			getch();
			return 0;
		}
		printf("\n\n->����Ҫ��������ģ�\n");
		printf("->    �������Щ�������������������������������\n");
		printf("      �� A��  ����ڵ�     ��\n");
		printf("      �������੥������������������������������\n");
		printf("      �� B��  ɾ���ڵ�     ��\n");
		printf("      �������੥������������������������������\n");
		printf("      �� C��  ��ת����     ��\n");
		printf("      �������੥������������������������������\n");
		printf("      �� D��  ��תż���ڵ� ��\n");
		printf("      �������੥������������������������������\n");
		printf("      �� E��  ����ɻ�     ��\n");
		printf("      �������੥������������������������������\n");
		printf("      �� F��  �����޸�     ��\n");
		printf("      �������ة�������������������������������\n->");
		fflush(stdin);
		scanf("%c", &step1);
	}
	
//�����û�ѡ�����������жϻ���� 
	printf("\n\n->���ڣ������Զ�������������жϻ����\n");
	printf("->    �������Щ�������������������������������\n");
	printf("      �� A��  ����м�ڵ� ��\n");
	printf("      �������੥������������������������������\n");
	printf("      �� B��  ���ҽڵ���ֵ ��\n");
	printf("      �������੥������������������������������\n");
	printf("      �� C��  �ж��Ƿ�ɻ� ��\n");
	printf("      �������੥������������������������������\n");
	printf("      �� D�� �����жϻ���ҩ�\n");
	printf("      �������ة�������������������������������\n->");
	isWork = SUCCESS; //��¼ִ�н�� 
	char step2;
	fflush(stdin);
	scanf("%c", &step2);
	while ( step2 != 'D' ) {
		switch (step2) {
			//����м�ڵ�
			case 'A':;
				LinkedList mid = FindMidNode(&head);
				printf("\n->��������м�ڵ����ֵΪ��%d", mid->data);
				break;
			//���ҽڵ���ֵ
			case 'B':
				printf("\n->�ڴ�������Ҫ���ҵ����ݣ�    ->"); 
				int data;
				isRight = scanf("%d", &data);
				if ( isRight == ERROR ) {
					printf("\n->�ף���߽�������ȷ�����أ�\n");
					fflush(stdin);
					break;
				}
				Status isFound = SearchList(head, data);
				if ( isFound )
					printf("\n->���������������\n");
				else
					printf("\n->�����в������������\n");
				break;
			//�ж��Ƿ�ɻ�
			case 'C':
				loop:;
				Status isLoop = IsLoopList(head);
				if ( isLoop ) {
					printf("\n->���жϣ��������ɻ����ڴ��������´μ��棡\n");
					getch(); 
					return 0; 
				} else { 
					printf("\n->���жϣ���������ɻ�\n");
				} 
				break;
			//�Ƿ��ַ����뷴�� 
			default:
				printf("\n->����������ȷ���ַ���\n");
		}
		if ( !isWork ) {
			printf("->Oooops���ƺ����˵����⣬�´μ���");
			getch();
			return 0;
		}
		printf("\n\n->����Ҫ�������жϻ���ң�\n");
		printf("->    �������Щ�������������������������������\n");
		printf("      �� A��  ����м�ڵ� ��\n");
		printf("      �������੥������������������������������\n");
		printf("      �� B��  ���ҽڵ���ֵ ��\n");
		printf("      �������੥������������������������������\n");
		printf("      �� C��  �ж��Ƿ�ɻ� ��\n");
		printf("      �������੥������������������������������\n");
		printf("      �� D�� �����жϻ���ҩ�\n");
		printf("      �������ة�������������������������������\n->");
		fflush(stdin);
		scanf("%c", &step2);
	}
	
//���������˳�
	DestroyList(&head);
	printf("\n->��Ϊ�����������ڴ��������´�ʹ�ã�\n");
	
	getch();
	return 0;
}


//��������
//��
//��
//��
//��
//��
//��	
//ɾ���׽ڵ�
//	ElemType del;
//	Status beDelet;
//	beDelet = DeleteList(head, &del);
//	if ( beDelet )
//		printf("��ɾ��");
//	else
//		printf("ɾ��ʧ��"); 
	
//	printf("%d\n", del);
	
	//����������� 
//	TraverseList(head, PrintData);
	
	//��������
//	int e;
//	printf("�ڴ�������Ҫ���ҵ����ݣ�"); 
//	scanf("%d", &e);
//	Status isFound = SearchList(head, e);
//	if ( isFound )
//		printf("�ҵ���");
	
	//��ת����
//	Status beReverse = ReverseList(&head);
//	printf("%d", beReverse);
	
	//�ж��Ƿ�ɻ�
//	loop:;
//	Status isLoop = IsLoopList(head);
//	if ( isLoop ) {
//		printf("\n���жϣ��������ɻ����ڴ��������´μ��棡\n");
//		return 0; 
//	} else { 
//		printf("\n���жϣ���������ɻ�\n");
//	} 
	//�ҵ��м�ڵ�
//	LinkedList mid = FindMidNode(&head);
//	printf("%x", mid);

	//��תż���ڵ� 
//	ReverseEvenList(&head);
//	TraverseList(head, PrintData);

//���������˳�
//	DestroyList(&head);
//	printf("\n��Ϊ�����������ڴ��������´μ��棡\n"); 
