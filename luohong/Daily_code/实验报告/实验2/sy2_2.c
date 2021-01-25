#include <stdio.h>  //输入x，求y
int main(void)
{
    int x, y;

    printf("Input an integer x:\n");
    scanf("%d", &x);

    if(x < 10)
      y = x;
    else if(x >= 10 && x < 50)
      y = 3 * x - 2;
    else if (x >= 50 && x < 100)
      y = 4 * x + 1;
    else
      y = 5 * x;
    
    printf("y = %d\n", y);

    return 0;
}