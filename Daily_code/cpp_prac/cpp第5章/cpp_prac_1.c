//计算不同鞋码对应脚长（有改动）      20.10.16  19:18
# include<stdio.h>
# define ADJUST 7.31
int main(void)
{
    const double SCALE = 0.333;
    double shoe, foot;

    printf("Shoe size (men's)     foot length\n");

    for (shoe = 3.0; shoe < 18.5; shoe++)
    {
        foot = SCALE * shoe + ADJUST;
        printf("%10.1f %15.2f inches\n", shoe, foot);
    }
    
    printf("If the shoe fits, wear it.\n");

    return 0;
}