#include <stdio.h>  //比较三个数大小
int main(void)
{
    int x, y, z, max;

    printf("Input x, y, z:\n");
    scanf("%d %d %d", &x, &y, &z);
    max = x;

    if(max > y)
    {
        if(max > z)
        ;
        else
        max = z;
    }    
    else
    {
        max = y;  //这里y > x，将y的值赋给max

       if(max > z)
        ;
        else
        max = z;
    }

    printf("max = %d\n", max);

    return 0;
}
