#include <stdio.h>
void menu(void);

int main(void)
{
    menu();
    return 0;
}
void menu(void)
{
    int i;
    for ( i = 0; i < 40; i++)
    {
        printf("*");
    }
    
    printf("\n");
    printf("请选择等级：\n");
    printf("1) $8.75/hr               2) $9.33/hr\n");
    printf("3) $10.00/hr              4) $11.20/hr\n");
    printf("5)\n");
    
    for ( i = 0; i < 40; i++)
    {
        printf("*");
    }
    printf("\n");

}