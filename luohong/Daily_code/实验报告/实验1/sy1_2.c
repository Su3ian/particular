#include <stdio.h>
int main(void)
{
    float money, tax_money;

    printf("Enter an amount:\n");
    scanf("%f", &money);

    tax_money = money * 1.05f;

    printf("With tax added:$%.2f\n", tax_money);

    return 0;
}