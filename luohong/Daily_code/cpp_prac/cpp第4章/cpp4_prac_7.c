//第七题看不懂题意
# include<stdio.h>
#define oil 3.785
#define kilometer 1.609

int main(void)
{
    int j, o;

    printf("请输入旅行里程(英里)：");
    scanf("%d", &j);
    printf("请输入消耗的汽油量：");
    scanf("%d", &o);

    printf("单位耗油的英里数：%.f", j / o);

    printf("转换单位后结果：%.f升/每100公里", (j * kilometer) / (100 * o *oil));
    return 0;
}