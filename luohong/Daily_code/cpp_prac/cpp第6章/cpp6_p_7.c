#include <stdio.h>//输入八个数，第一行打印各个元素，第二行打印该元素前所有数之和
int main(void)    //  20.10.26  18：19
{
    double one[8], two[8];
    int i, j;

    printf("请输入八个数：");

    for ( i = 0; i < 8; i++)
    scanf("%lf", &one[i]);

    two[0] = one[0];

    for ( j = 1; j < 8; j++)
    two[j] += two[j - 1] + one[j];

    for ( i = 0; i < 8; i++)
    printf("%3.lf ", one[i]);

    printf("\n");

    for ( j = 0; j < 8; j++)
    printf("%3.lf ", two[j]);

    return 0;
}