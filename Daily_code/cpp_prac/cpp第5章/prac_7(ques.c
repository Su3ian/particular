//自行设置函数    20.10.16  21:xx
# include<stdio.h>
double threetimes(double n);
int main(void)
{
    double n, i;
    scanf("%lf", &n);

    i = threetimes(n);

    printf("%.lf\n", i);

    return 0;
}
double threetimes(double n)
{
    n = n * n * n;

    return n;              //这里用的对不对？
}