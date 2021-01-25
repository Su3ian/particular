//计算三或四阶行列式结果
#include<stdio.h>
int main(void)
{
int number,a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, r1, r2, r3, r4, answer;
printf("请输入您要计算的阶数(3或4)\n");
scanf("%d", &number);
if (number == 3) {
	printf("请按行输入三阶行列式的9个数字(数字间用空格间隔)\n");
	scanf("%d %d %d", &a, &b, &c);
	scanf("%d %d %d", &d, &e, &f);
	scanf("%d %d %d", &g, &h, &i);
	answer = a * e * i + b * f * g + c * d * h - a * f * h - b * d * i - c * e * g;
	printf("此三阶行列式的结果为%d\n", answer);
}
else if(number == 4){
	printf("请按行输入四阶行列式的16个数字(数字间用空格间隔)\n");
	scanf("%d %d %d %d", &a, &b, &c, &d);
	scanf("%d %d %d %d", &e, &f, &g, &h);
	scanf("%d %d %d %d", &i, &j, &k, &l);
	scanf("%d %d %d %d", &m, &n, &o, &p);
	r1 = f * k * p + j * o * h + g * l * n - h * k * n - g * j * p - l * o * f;
	r2 = b * k * p + j * o * d + c * l * n - n * k * d - j * c * p - l * o * b;
	r3 = b * g * p + f * o * d + c * h * n - n * g * d - f * c * p - h * o * b;
	r4 = b * g * l + f * k * d + c * h * j - j * g * d - f * c * l - h * k * b;
	answer = a * r1 - e * r2 + i * r3 - m * r4;
	printf("此四阶行列式的结果为%d\n", answer);
}
else {
	printf("输入错误\n");
}
return 0;
}