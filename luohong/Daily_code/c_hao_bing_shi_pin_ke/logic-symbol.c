# include <stdio.h>

int main(void)
{
    int k = 20;
    int m;

    m = (3>2) && (k = 8);
    printf("m = %d, k = %d\n", m, k);
    return 0;
}