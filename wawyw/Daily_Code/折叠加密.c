/*给一个长度为2的k次方的字符数组和两个长度为k的01数组req1和req2，根据要求编写折叠加密和解密的算法。
reg1[i]=0,表示从左到右折叠;reg1[i]=1,表示从右到左折叠;
reg2[i]=0,表示向上折叠;reg2[i]=1,表示向下折叠。        */
#include <stdio.h>
#include <string.h>
int main(void)
{
	int a,b=1,c=2,n,m,p;
	char str[100],req1[100],req2[100];
	
	printf("请输入字符串："); 
	scanf("%s",&str);
	printf("请输入req1："); 
	scanf("%s",&req1);
	printf("请输入req2：");
	scanf("%s",&req2);
	
	n=strlen(str);
	p=n;
	m=strlen(req1);
	char arr[n*2][n*2];

	for(a=0;a<n*2;a++)
	 for(int l=0;l<n*2;l++)
	  arr[a][l]=0;
	
	for(a=0;a<n;a++)
	arr[n-1][a]=str[a];
	for(int j=0;j<m;j++)
	{
		int d=0;
		if(req1[j]=='1'&&req2[j]=='0')
		{
			for(int l=0;l<b;l++)
			{
				for(int i=p/2;i<p;i++)
				{
					arr[n-c+d][p-i-1]=arr[n-1-d][i];
					arr[n-1-d][i]=0;
				}
				d++;							
			}
		}
		else if(req1[j]=='0'&&req2[j]=='0')
		{
			for(int l=0;l<b;l++)
			{
				for(int i=0;i<p/2;i++)
				{
					arr[n-c+d][p/2-i-1]=arr[n-1-d][i];
					arr[n-1-d][i]=arr[n-1-d][p/2+i];
					arr[n-1-d][p/2+i]=0;
				}
				d++;
			}
		}
		else if(req1[j]=='1'&&req2[j]=='1')
		{
			for(int l=0;l<b;l++)
			{
				for(int i=0;i<p/2;i++)
				{
					arr[n-2+c+d][i]=arr[n-1-d][n-1-i];
					arr[n-1-d][n-1-i]=0;
					arr[n-c+d][i]=arr[n-1-d][i];
					arr[n-1-d][i]=arr[n-2+c+d][i];
				}
				d++;							
			}
		}
		p=p/2;
		b*=2;
		c*=2;
		printf("第%d次加密后为：\n", j+1);
		for(int i=n-b;i<n;i++)
			{
			printf("\t\t%s",arr[i]);
			printf("\n");
			}	
	}
	return 0;
 } 
