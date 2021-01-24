#include <stdio.h>  //s1将s2覆盖
int main(void)
{
    char s1[20], s2[20];
    char *a = s1, *b = s2;

    printf("请输入两个字符串：\n");
    scanf("%s %s", s1, s2);
    
    for (int i = 0; *(a + i) != '\0'; i++)
    {
        *b = *(a + i);
        b++;
    }
    *b = '\0';
    printf("%s\n", s2);

    return 0;
}
