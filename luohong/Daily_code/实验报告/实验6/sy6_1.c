#include <stdio.h>
#include <string.h>
#define NUM 20;
int main(void)
{
/*    char str1[20], str2[20], str3[20];
    char *one, *two, *three;
    printf("输入三个字符串：\n");
    scanf("%s %s %s", str1, str2, str3);
    
    if (strcmp(str1,str2) < 0 && strcmp(str1,str3) < 0)
    {
        one = str1;
        if (strcmp(str2,str3) < 0)
        {
            two = str2;
            three = str3;
        }
        else
        {
            two = str3;
            three = str2;
        }
    }
    if (strcmp(str2,str1) < 0 && strcmp(str2,str3) < 0)
    {
        one = str2;
        if (strcmp(str1,str3) < 0)
        {
            two = str1;
            three = str3;
        }
        else
        {
            two = str3;
            three = str1;
        }
    }
    if (strcmp(str3,str1) < 0 && strcmp(str3,str2) < 0)
    {
        one = str3;
        if (strcmp(str1,str2) < 0)
        {
            two = str1;
            three = str2;
        }
        else
        {
            two = str2;
            three = str1;
        }
    }
    
    printf("%s\n%s\n%s\n", one, two, three);
*/
    char str[3][10], temp[10];
    // 输入字符串
    printf("请输入三个字符串:\n");
    for (int i = 0; i < 3; i++)
    scanf("%s", str[i]);
    // 字典排序
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (strcmp(str[i],str[j]) < 0)
            {
                strcpy(temp,str[i]);
                strcpy(str[i],str[j]);
                strcpy(str[j],temp);
            }
        }
    }
    // 输出排序后字符串
    for (int i = 0; i < 3; i++)
    printf("%s\n", str[i]);

    return 0;
}