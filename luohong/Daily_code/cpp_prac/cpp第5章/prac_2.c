//输入某值，输出其及其后十个值    20.10.16  21:04
# include<stdio.h>
int main(void)
{
    int n, i;

    printf("请输入一个整数：");
    scanf("%d", &n);

    for (i = n + 11 ; n < i; n++)
    {
        printf("%d\t", n);
    }
    
    printf("\n");
    
    return 0;
}