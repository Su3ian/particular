#include <stdio.h>// 找出0度以下天数并占总天数的百分比  20.10.27  17：27
int main(void)
{
    const int FREEZING = 0;
    float tem;
    int cold_days = 0, all_days = 0;

    printf("请输入每日最低温度(输入q停止)：\n");

    while(scanf("%f", &tem) == 1)
    {
        all_days++;
        
        if(tem < FREEZING)
        cold_days++;
    }

    if(all_days != 0)
    {
        printf("总共有%d天，其中%.lf%%为零下\n", 
        all_days, 100.0 * (float) cold_days / all_days);
    }

    if(all_days == 0)
    printf("你没有输入数据！");

    return 0;
}