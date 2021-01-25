#include <stdio.h>         // 将二位数分解为素数相乘
void decompose(int);

int main(void)
{
    int n;
    printf("请输入一个两位整数：\n");
    scanf("%d", &n);
    if (n > 9 && n < 100)
    decompose(n);
    else 
    printf("输入错误！\n");
    return 0;
}
void decompose(int n)
{
    printf("%d =", n);
    for (int i = 2; i <= n; i++)
    {
        while(n % i == 0)  //判断i是否仍为n的因数
        {
            n /= i;
            printf(" %d", i);
            if (n > 1)
            printf(" *");
        }
        
    }
        printf("\n");
}