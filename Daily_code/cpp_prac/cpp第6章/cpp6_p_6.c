#include <stdio.h>//用for和do while循环输出2的前八次幂
#include <math.h>//  20.10.26  18：04
int main(void)
{
    int n[8];
    int i;

    for ( i = 0; i < 8; i++)
    n[i] = pow(2, i + 1);

    i = 0;
    do
    {
        printf("%d\n", n[i]);
        i++;
    }while(i < 8);
    
    return 0;
}