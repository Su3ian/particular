#include <stdio.h>          //计算整数平方和  20.10.21  18：18
int doub(int n);
int main(void)
{
    int min, max;
    int sum = 0;
    printf("请输入下限整数和上限整数：");
    scanf("%d %d", &min, &max);

    while(min < max)
    {
        int sum = 0;

    for (int i = min; i <= max; i++)    //初始化条件为什么不能初始化sum = 0？
        sum += doub(i);
    printf("%d到%d之间所有整数平方和为：%d\n", doub(min), doub(max), sum);
    printf("请输入下一组数据：");
    scanf("%d%d", &min, &max);

    }
    printf("Done!\n");

    return 0;
}
    int doub(int n)
    {
        int m;
        m = n * n;
        return m;
    }
