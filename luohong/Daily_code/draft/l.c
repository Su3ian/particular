# include<stdio.h>


int main(void)
{
	int i;

nihao:
	printf("快输入你成绩：");
	scanf("%d", &i);

	if(150<i || 0>i)
	{
		printf("你不乖！\n");

		goto nihao;
	}	
	else
		printf("继续判断巴拉巴拉！\n");

	
	return 0;
}