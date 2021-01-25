#include <stdio.h>  //替换符号并报告次数  20.10.30  21：01
int main(void)
{
    int count = 0;
    char ch;

    printf("请输入（输入#停止）：");

    while((ch = getchar()) != '#')
    {
        if(ch == '.')
        putchar('!');
        else if(ch == '!')
        {
            putchar('!');
            putchar('!');
        }
        else
        {
            putchar(ch);
            continue;
        }

        count++;
    }

    printf("\n进行了%d次更换", count);
    
    return 0;
}