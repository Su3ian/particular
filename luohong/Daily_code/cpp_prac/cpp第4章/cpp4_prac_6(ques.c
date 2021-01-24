# include<stdio.h>
# include<string.h>
int main(void)
{
    char name[10], fname[10];
    int q, w;

    printf("请输入你的名：");
    scanf("%s", name);

    printf("请输入你的姓：");
    scanf("%s", fname);

    printf("%10s%10s\n", name, fname);

    printf("%10d%10d\n", strlen(name), strlen(fname));
    printf("%-10d%-10d\n", strlen(name), strlen(fname));
    //问题：不知道左边如何对齐

    return 0;
}