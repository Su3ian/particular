# include<stdio.h>
int main(void)
{
  /*(第4题)  
    float f;
    printf("Enter a floating-point value:");

    scanf("%f", &f);

    printf("fixed-point notation: %f\n", f);
    printf("exponential notation: %e\n", f);
    printf("p notation: %a\n", f);*/
    
    /*(5)
    int age;
    float second;
    printf("请输入你的年龄 ：");

    scanf("%d", &age);
    second = age * 3.156e7;
    printf("The second of your age is %e\n", second); */

    //6, 7省略

    int bottle;

    printf("请输入液体杯数：");

    scanf("%d", &bottle);

    float p, a, t, c;
    p =2 * bottle;
    a = bottle / 8;
    t = a / 2;
    c = t / 3;

    printf("品脱 = %f\n盎司 = %.4f\n汤勺 = %f\n茶勺 = %f", p, a, t, c);
    //ques :输出结果会丢失精度，需重新检查

    return 0;
}