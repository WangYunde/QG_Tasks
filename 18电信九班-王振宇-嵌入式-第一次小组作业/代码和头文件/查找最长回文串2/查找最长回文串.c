#include <stdio.h>
#include <string.h>

int main()
{
	int cap = 10000;
	char* s = (char*)malloc((cap + 1) * sizeof(char));
	printf("�ڴ˼����ַ�����\n->");
	s[cap + 1] = -1;
	int len; //��¼�ַ�������
	int exp; //��¼������С
	int i;
	//	int j;
	int partLen;
	int partBorn;
	int LongrstPartLen;
	int isFound;
	while (1) {
		scanf("%s", s);
//		if (s[cap + 1] != -1) {
//			cap += 1000;
//			s = (char*)realloc(s, (cap + 1) * sizeof(int));
//		}
		partLen = 0;
		partBorn = -1;
		LongrstPartLen = 0;
		isFound = 0;
		len = strlen(s);
		printf("�ַ�������Ϊ��%d\n", len);
		if (len == 1)
			printf("�����ַ��޷��γɻ��Ĵ�");
		else if (len == 2) {
			if (s[0] == s[1])
				printf("%c%c������Ĵ�\n", s[0], s[1]);
		}
		else {
			for (i = 1; i < len; i++) {
				for (exp = 1; exp <= i && exp <= len - 1 - i && s[i - exp] == s[i + exp]; exp++) {
					//					for (j = i - exp; j <= i + exp; j++) {
					//						printf("%c", s[j]);
					//					}
					//					printf("�ǻ��Ĵ�\n");
					partLen = 1 + 2 * exp;
					if (LongrstPartLen < partLen) {
						LongrstPartLen = partLen;
						partBorn = i - exp;
					}
				}
				for (exp = 1; exp <= i && exp <= len - i && s[i - exp] == s[i + exp - 1]; exp++) {
					//					for (j = i - exp; j <= i + exp - 1; j++) {
					//						printf("%c", s[j]);
					//					}
					//					printf("�ǻ��Ĵ�\n");
					partLen = 0 + 2 * exp;
					if (LongrstPartLen < partLen) {
						LongrstPartLen = partLen;
						partBorn = i - exp;
					}
				}
			}
			printf("->");
			for (int k = partBorn; k < partBorn + LongrstPartLen; k++) {
				printf("%c", s[k]);
				isFound = 1;
			}
			if (isFound)
				printf("������Ĵ�\n");
			else
				printf("δ�ҵ����Ĵ�\n");
		}
		printf("\n�ڴ˼����ַ�����\n->");
	}

	return 0;
}
