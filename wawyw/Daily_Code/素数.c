#include<stdio.h>
int main(void)
{
	int flag;
	printf("1000以内的素数有:"); 
	for (int i = 2; i <= 1000; i++) {
		flag = 1;
		for (int j = 2; j < i; j++) {
			if (i % j == 0){
				flag = 0;
			}
		}
		if (flag == 1){
			printf("%d, ", i);
		}
	}
	return 0;
}
