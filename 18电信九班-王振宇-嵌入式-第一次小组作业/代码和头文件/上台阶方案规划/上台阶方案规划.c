#include <stdio.h>

int plan(int n)
{
	long long solution = 0;
	if (n == 0 || n == 1)
		solution = 1;
	else if (n > 1)
		solution = plan(n - 1) + plan(n - 2);
	return solution;
}

int main()
{
	int n = 0;
	printf("请输入台阶数：    ->");
	while (scanf("%d", &n)) {
		long long solution = plan(n);
		printf("方案有 %d 种\n", solution);
		printf("\n请输入台阶数：    ->");
	}

	getch();
	return 0;
}