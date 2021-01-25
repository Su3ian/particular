#include <stdio.h>//  读取并打印字符及其ASCII码，一行仅打印8个字符
int main(void)    //  20.10.30  20：27
{
    int count = 0;
    char ch;

    printf("请输入字符：");

    while((ch = getchar()) != '#')
    {
        count++;

        if(count % 8 == 0)  //8个一循环
        printf("%c %d.  \n", ch, ch);
        else
        printf("%c %d.  ", ch, ch);
    }
    return 0;

}