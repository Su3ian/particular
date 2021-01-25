#include <stdio.h>
int main(void)
{
    int a = 2020;
    unsigned long c;
    printf("%p\n", &a);
    printf("想要修改的地址：\n");
    scanf("%lx", &c);
    printf("请随便输入一个数：\n");
    scanf("%d", (int *)c);
    printf("a = %d\n", a);
    
    
    return 0;

}