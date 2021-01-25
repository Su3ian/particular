#include <stdio.h>          //倒打印一个单词  20.10.21  17：04
#include <string.h>

int main(void)
{
    char ch[20];
    int i;

    printf("请输入一个英文单词：");
    scanf("%s", ch);

    for (i = strlen(ch); 0 <= i; i--)
        printf("%c", ch[i]);
    
    return 0;
}