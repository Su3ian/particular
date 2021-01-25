#include <stdio.h>     //定义判断素数的函数
void is_prime(int);
int main(void)
{
    int n, num;
    printf("请输入一个两位整数：\n");
    scanf("%d", &n);
    if (n > 9 && n < 100)
    is_prime(n);
    else 
    printf("输入错误！\n");

    return 0;
}
void is_prime(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (i == n)
        {
            printf("该数为素数\n");
            break;
        }
        if (n % i == 0)
        {
            printf("该数不为素数\n");
            break;
        }
        
    }
    
}
