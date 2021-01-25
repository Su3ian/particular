//实现输出n行金字塔
#include <stdio.h>
int main(void)
{
	int n;
	printf("输入金字塔层数:");
	scanf("%d", &n);
	printf("输出:\n");
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n - i; j++) {
			printf(" ");
		}
		for (int j = 1; j <= i; j++) {
			printf("%d ", i);
			if (i == j) {
				printf("\n");
			}
		}
	}
	return 0;
}
