# include<stdio.h>
# include<math.h>

int main(void)
{
    int a = 1;
    int b = 2;
    int c = 3;
    double delta;
    double x1, x2;

    delta = b*b -4*a*c;

    if (delta > 0)
    {
        x1 = (-b + sqrt(delta)) / (2*a);
        x2 = (-b - sqrt(delta)) / (2*a);

        printf("x1 = %f\nx2 = %f\n有两个解", x1, x2);
    }

    else if (delta == 0)
    {
        x1 = (-b) / (2*a);
        x2 = x1;

        printf("x1 = x2 = %f\n有唯一解", x1);
    }

    else if (delta < 0)
    {
        printf("无解\n");
    }

    return 0;
}