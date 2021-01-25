#include <stdio.h>//求某人多少年能取完100万  20.10.27  17：09
int main(void)
{
    int year;
    float money = 1e+06;

    for (year = 0; money > 0; year++)
    {
        money *= 1.08;
        money -= 1e+05;
    }

    printf("%d年后钱取完\n", year);
    
    return 0;
}