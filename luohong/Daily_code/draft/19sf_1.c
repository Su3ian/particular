//同上
#include <stdio.h>
#include <string.h>
int power(int base,unsigned int n)
{
if(n == 0) return 1;
if(n == 1) return base;
int half = power(base,n>>1);
return ((n & 1) == 1 ? base: 1) * half * half;

}
void PrintSumProbabilityOfDices(unsigned int N)
{
	const unsigned int MAX = 12;  //max number of dices
	if(N > MAX)
	{
		printf("Overflow!\n");
		return;
	}
	unsigned int a[MAX + 1][6 * MAX + 1];
	unsigned int n,s,i;
	memset(a,0,sizeof(a));
	for(s = 1;s <= 6;s++)
		a[1][s] = 1;
	for(n = 2; n <= N; n++)
		for(s = n; s <= 6 * n; s++)
		{
			a[n][s]=0;
			for(i = 1; i <= 6 && i < s; i++)
				a[n][s]+=a[n-1][s-i];
		}
	unsigned int nTotal=power(6,N);
	for(i=N;i<=6*N;i++)
	{
		printf("P(s=%d) = %d/%d\n",i,a[N][i],nTotal);
	}
}
int main(void)
{
	puts("***********");
    PrintSumProbabilityOfDices(4);

	return 0;
}
