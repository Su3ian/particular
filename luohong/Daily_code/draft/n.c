#include <stdio.h>

int main(void)
{
    long long  n = 1, b = 1, a = 2;
    char sd[50];
    char *sr = sd; 
    while (a <= 2)
    {
        n += 1;
        b *= a;
        a += 2;
    }
    scanf("%s", sd);
    printf("%s", sr);
    
    printf("%d", b);
    
}