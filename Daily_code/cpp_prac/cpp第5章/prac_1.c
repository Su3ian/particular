//时间转换（分钟--小时+分钟， 可循环）    20.10.16  20:53
# include<stdio.h>
const int min_to_h = 60;
int main(void)
{
    int min, hour;

    printf("若输入0或负数程序将会停止\n");
    printf("请输入所需转换的时间（分钟）：");
    scanf("%d", &min);
    while (min > 0)
    {
        hour = min / min_to_h;
        min = min % min_to_h;

        printf("时间为%d小时%d分钟\n", hour, min);

        printf("请输入所需转换的时间（分钟）：");
        scanf("%d", &min);

    }
    
    printf("欢迎您的使用，再见!\n");

    return 0;
}