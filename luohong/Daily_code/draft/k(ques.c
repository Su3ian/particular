# include <stdio.h>

int main(void)
{
    int a , b, c, d;
	int sum = 0;
	printf("请输入您的各科成绩(中间请以空格隔开)：");
    /*
    do
    {
        int i;
        i = scanf("%d %d %d %d", &a, &b, &c, &d);
    }while(i == 1);
    */
  
do
{
    getchar();
    while (scanf("%d %d %d %d", &a, &b, &c, &d) == 1)   
        printf("请重新输入："); 

}while (a > 150 && a <= 0 && 
        b > 150 && b <= 0 && 
        c > 150 && c <= 0 && 
        d > 150 && d <= 0);

    /*do
    {
        if (a>=150 || b>=150 || c>=150 || d>=150)
        {
        ;
        }
        else
        {
            printf("请重新输入：");
            continue;
        }
        
        continue;
    }*/

	if(a>60 && b>60 && c>60 && d>60)
	{
		sum = a+ b+ c+ d;
		if(sum>=340 && sum<370)
			printf("恭喜你被录取，但我们不管你的学费！（啊哈哈哈！）\n");
		else if(sum>=370)
			printf("恭喜你！您的学费由我们一力承担，您只需前往学校即可！\n");
		else
			printf("很遗憾，您没有被录取，请另寻高就吧！\n");

	}
	else
		printf("您不满足我们的录取要求，抱歉！\n");
		

	return 0;
}