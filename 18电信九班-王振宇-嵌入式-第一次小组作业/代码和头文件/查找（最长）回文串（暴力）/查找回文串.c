#include <stdio.h>
#include <string.h>
#include <conio.h>

int judgePldr(char* s)
{	//�ж���֪�ַ����Ƿ�Ϊ���Ĵ�
	int isPldr = 1; //�����ж� 
	int len = strlen(s);
	for(int i=0; i<(len)/2; i++) {
		if ( s[i] != s[len-1-i] ) {
			isPldr = 0;
			break;
		}
	}
	return isPldr;
}

int main()
{
	char s[1001];
	printf("�ڴ˼����ַ�����    ->");
	gets(s);
	int len = strlen(s);
	printf("�ַ�������Ϊ��%d\n", len);
	
	//����ַ���
	char part[1001];
	int num = 0;
	int isPldr = 0; //�����ж�
	
	if ( len == 0 )
		printf("�벻Ҫ������ַ���\n");
	else if ( len == 1 )
		printf("%����Ϊ 1 ���ַ��������ڻ��Ĵ�\n");
	else 
		for(int partLen=len; partLen>1; partLen-- ) { //ȷ��Ƭ�γ��� 
			num = len-partLen+1; //ȷ��ͬ����Ƭ�θ���
			printf("\n����Ϊ%d��Ƭ����%d��\n", partLen, num);
			for (int i=0; i<num; i++) { //ȷ��Ϊ�ڼ���Ƭ��
				for (int j=0, k=i; j<partLen; j++, k++) { //�����ַ���Ƭ��
					part[j] = s[k];
				}
				part[partLen] = '\0';
				isPldr = judgePldr(part); //�����жϺ���
				printf("���У���%3d��Ϊ��%s", i+1, part);
				if ( isPldr )
					printf("�����ǻ��Ĵ�\n");
				else
					printf("\n");
			}
		} 
	
	getch();
	return 0;
}
