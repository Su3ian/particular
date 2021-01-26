//扔 n 个骰子，向上面的数字之和为 S。给定 n，请列出所有可能的 S 值及其相应的概率。
#include<stdio.h>
int main(void)
{
	int n;
	scanf("%d", &n);
	float array[100][100];
    for (int i = 1; i <= 6; i++) {
		array[1][i] = 1.0 / 6;
	}
	for (int i = 2; i <= n; i++)
	{
		for (int j = i; j <= 6 * i; j++)
		{
			for (int k = 1; k <= 6; k++)
			{
				if (j > k)
				{
					array[i][j] += array[i - 1][j - k];
				}
			}
			array[i][j] /= 6.0;
		}
	}
	for (int i = n; i <= n * 6; i++) {
		printf("S值：%d   概率：%f\n", i, array[n][i]);
	}
	return 0;
}