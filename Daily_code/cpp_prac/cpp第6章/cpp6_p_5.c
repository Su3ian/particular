#include <stdio.h>//计算两个无限序列之和  20.10.26  15:57
#include <math.h>
int main(void)
{
    double sum, sum_1;       //ques:这两个变量类型换成long double输出结果出现-nan
    int j, i, h;
    
    printf("输入所要求项数总量（当输入数不为正数停止）：");
    scanf("%d", &j);

    
    while(j > 0)
    {
    
    for ( i = 1; i < j; i++)
        sum += (pow(-1, i - 1) * (1.0 / i));
    for ( i = 1; i < j; i++)
        sum_1 += (1.0 / i);
    
    printf("第%d项差和为%lf\n", j, sum);
    printf("第%d项和为%lf\n", j, sum_1);

    printf("输入所要求项数总量（当输入数不为正数停止）：");
    scanf("%d", &j);
    
    }
    return 0;
}