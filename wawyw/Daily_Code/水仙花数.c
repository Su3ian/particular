//打印出所有的“水仙花数”
#include<stdio.h>
int main(void)
{
	int  a, b, c;
	printf("所有的水仙花数:");
	for (int i = 100; i < 1000; i++) {
		a = i / 100;
		b = i / 10 % 10;
		c = i % 100 % 10;
		if (a * a * a + b * b * b + c * c * c == i) {
			printf("%d ", i);
		}
	}

	return 0;
}