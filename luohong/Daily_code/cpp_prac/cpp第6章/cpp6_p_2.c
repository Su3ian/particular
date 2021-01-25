#include <stdio.h>          //字母金字塔  20.10.21  16：43
int main(void)
{
    int i, j; 
    char ch;

    printf("请输入一个大写字母：");
    ch = getchar();

    for(i = 0; i <= ch - 'A'; i++)          //每行递增
    {
        
        for (j = 0; j < ch - 'A' - i; j++)
        {
            printf(" ");
        }

        for (j = 0; j <= i; j++)          //顺序递增
        {
            printf("%c", 'A' + j);
        }

        for (j = i; j > 0; j--)          //倒序递减
            printf("%c", 'A' + j - 1);
        
        printf("\n");
    }

    return 0;
}