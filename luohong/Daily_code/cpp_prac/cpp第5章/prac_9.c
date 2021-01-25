//温度转换    20.10.16  22:06
# include<stdio.h>
double tem_c (double f);
double tem_k (double f);
int main(void)
{
    double f, c, k;
    printf("请输入一个华氏温度(q to quit):");

    while (scanf("%lf", &f) == 1)
    {
        c = tem_c (f);
        k = tem_k (f);

        printf("与该华氏温度对应\n摄氏温度为%.3lf\n开氏温度为%.3lf\n", 
        c, k);
        printf("请输入一个华氏温度(q to quit):");
    }
    
    return 0;
}

double tem_c (double f)
{
    f = 5.0 / 9.0 * (f - 32.0);
    return f;
}

double tem_k (double f)
{
    f = f + 273.16;
    return f;
}