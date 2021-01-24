#include <stdio.h>//报告读取的空格，换行，其他字符 数  20.10.28  18：28
int main(void)
{
    int t, b, n;
    char ch;
    t = 0;
    b = 0;
    n = 0;

    while((ch = getchar()) != '#')
    {
        if(ch == ' ')
        b++;
        else if(ch == '\n')
        n++;
        else
        t++;        
    }
    printf("空格数：%d\n换行符数：%d\n其他字符数：%d", b, n, t);

    return 0;
}