#include <stdio.h>// 替换输入字母，非字母字符不换 20.10.27  17：42
#include <ctype.h>
int main(void)
{
    char ch;

    printf("请输入一句英语语句：");

    while((ch = getchar()) != '\n')
    {
        if(isalpha(ch))
        putchar(ch + 1);
        else
        putchar(ch);        
    }

    putchar(ch);

    return 0;
}