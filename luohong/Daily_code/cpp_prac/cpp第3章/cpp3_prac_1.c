# include<stdio.h>
int main(void)

{   //浮点值上溢
   // float i = 3.4E38 * 100.0f;
   // printf("%e\n", i);
   //输出结果 ： inf（表示无穷）

   float y =1.234567E-10;
   printf("%e, %e", y, y / 1.0e180);
   //这个下溢是真不知道咋搞，唉


    return 0;
}