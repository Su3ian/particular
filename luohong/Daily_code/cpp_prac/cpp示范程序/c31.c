# include<stdio.h>

int main(void)
{
    float weight, value;

    scanf("%f", &weight);
    
    
    value = 1700.0 * weight * 14.5833;

    printf("Your weight in platinum is worth %.2f.\n", value);
    
    return 0;
}