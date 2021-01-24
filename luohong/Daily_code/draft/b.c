#include<stdio.h>
#include<math.h> 
int main(void)
{
	double a,b,c,s,area;
	printf("请输入三角形的三边长"); 
	scanf("%lf,%lf,%lf",&a,&b,&c);
	s=(a+b+c)/2.0;
	area=sqrt(s*(s-a)*(s-b)*(s-c));
	printf("该三角形的面积为%lf\n",area);
	return 0;
}
