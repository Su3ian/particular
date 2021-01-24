/* 输入一个长为2的k次方（k≤8）的字符串s，按照"ABC编码规则"进行编码，ABC编码规则是：
若s串全为0，T(s)=A;若s串全为1，T(s)=B;否则T(s)=CT(s1)T(s2),把s串分成两个子串s1,s2
如：T(01001011)=CT(0100)T(1011)=CCT(01)T(00)CT(10)T(11)=CCCT(0)T(1)ACCT(1)T(0)B=CCCABACCBAB */
#include<stdio.h>
#include<string.h> 
int len;
char s[100000];
int judge(int l,int r)
{
	int sum0=0,sum1=0;
	for(int i=l;i<=r;i++)
	 if(s[i]=='0') sum0++;
	 else sum1++;
	if(sum0==r-l+1) return 1;
	else if(sum1==r-l+1) return 2;
    else return 0;
	
} 
void dfs(int l,int r)
{
	if(judge(l,r)==1)
	{
		printf("A");
		return ; 
	}
	else if(judge(l,r)==2)
	{
		printf("B");
		return ;
	}
	else
	{
		printf("C");
		dfs(l,(l+r)/2);
		dfs((l+r)/2+1,r);
	}
}
int main() 
{
	scanf("%s",s);
	len=strlen(s);
	dfs(0,len-1);
}