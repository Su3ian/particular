#include <stdio.h>
int main(void)
{
    int i;
    long double num[100];
    num[0] = 1;
    num[1] = 1;

    for ( i = 2; i < 100; i++)
    {
        num[i] = num[i - 1] + num[i - 2];
    }
    
    printf("%.Lf\n", num[99]);

    return 0;
}