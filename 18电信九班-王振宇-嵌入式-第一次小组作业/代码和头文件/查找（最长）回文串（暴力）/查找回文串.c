#include <stdio.h>
#include <string.h>
#include <conio.h>

int judgePldr(char* s)
{	//判断已知字符串是否为回文串
	int isPldr = 1; //用于判断 
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
	printf("在此键入字符串：    ->");
	gets(s);
	int len = strlen(s);
	printf("字符串长度为：%d\n", len);
	
	//拆分字符串
	char part[1001];
	int num = 0;
	int isPldr = 0; //用于判断
	
	if ( len == 0 )
		printf("请不要输入空字符串\n");
	else if ( len == 1 )
		printf("%长度为 1 的字符串不属于回文串\n");
	else 
		for(int partLen=len; partLen>1; partLen-- ) { //确定片段长度 
			num = len-partLen+1; //确定同长度片段个数
			printf("\n长度为%d的片段有%d个\n", partLen, num);
			for (int i=0; i<num; i++) { //确定为第几个片段
				for (int j=0, k=i; j<partLen; j++, k++) { //构造字符串片段
					part[j] = s[k];
				}
				part[partLen] = '\0';
				isPldr = judgePldr(part); //调用判断函数
				printf("其中，第%3d个为：%s", i+1, part);
				if ( isPldr )
					printf("，它是回文串\n");
				else
					printf("\n");
			}
		} 
	
	getch();
	return 0;
}
