#include <stdio.h> //  报告ei出现次数  20.10.30  21：14
#include <string.h>
int main(void)
{
    char ch[50];
    int index, count = 0;

    printf("请输入（输#停）：");

    while((ch[index] = getchar()) != '#')
    { 
        index++;
        continue;
    }

    for ( index = 0; index < strlen(ch); index++)
    {
        if(ch [index] == 'e' && ch [index+1] == 'i')
        count++;
        else
        continue;
    }

    printf("\n ei共出现%d次", count);

    
    return 0;
}