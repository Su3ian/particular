#include <stdio.h>  //检查奇偶并分类，各求平均数  20.10.30  20：46
int main(void)
{
    int n, o = 0, j = 0;
    float o_t = 0, j_t = 0;

    printf("请输入一个数（输入0停止）：");
    scanf("%d", &n);

    while(n != 0)
    {
        if(n % 2 == 0)
        {
            o++;
            o_t += n;
        }
        else
        {
            j++;
            j_t += n;
        }
        printf("请输入：");
        scanf("%d", &n);
    }

    printf("偶数个数：%3d  其平均数：%3.f\n", o, o_t / o);
    printf("奇数个数：%3d  其平均数：%3.f\n", j, j_t / j);

    return 0;
}