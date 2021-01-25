//给定一个正整数n，生成一个包含1到n^2所有元素，分别给出元素按顺时针从外到内和从内到外顺序螺旋排列的正方形矩阵。
#include<stdio.h>
void wai(int n);
void nei(int n);
int n,m,array[100][100];

int main(void)
{
	scanf("%d",&n);
	wai(n);
	nei(n);
	return 0;
}

void wai(int n){
	int r=0,c=0,number=1;
	m = n;
	while(n>1){
	for(int i=0;i<n-1;i++){
		array[r][c++] = number++;
		}
	for(int i=0;i<n-1;i++){
		array[r++][c] = number++;
		}
	for(int i=0;i<n-1;i++){
		array[r][c--] = number++;
		}
	for(int i=0;i<n-1;i++){
		array[r--][c] = number++;
		}
		n -= 2;
		r ++;
		c ++;
	} 
	if(n%2==1){
		array[r][c]=number;
	}
	printf("从外到内：\n");
	 for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			printf("%2d ",array[i][j]);
		}
		printf("\n");
	}  
}

void nei(int n){
	int number=n*n;
	m = n;
	if(n%2==0){
		int r=n-1,c=0;
	while(n>1){
	for(int i=0;i<n-1;i++){
		array[r][c++] = number--;
		}
	for(int i=0;i<n-1;i++){
		array[r--][c] = number--;
		}
	for(int i=0;i<n-1;i++){
		array[r][c--] = number--;
		}
	for(int i=0;i<n-1;i++){
		array[r++][c] = number--;
		}
		n -= 2;
		r --;
		c ++;
	} 
	}
	 if(n%2==1){
		 int r=0,c=n-1;
		while(n>1){
	for(int i=0;i<n-1;i++){
		array[r][c--] = number--;
		}
	for(int i=0;i<n-1;i++){
		array[r++][c] = number--;
		}
	for(int i=0;i<n-1;i++){
		array[r][c++] = number--;
		}
	for(int i=0;i<n-1;i++){
		array[r--][c] = number--;
		}
		n -= 2;
		r ++;
		c --;
	} 
	array[r][c]=number;
	}
	printf("从内到外：\n");
	 for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			printf("%2d ",array[i][j]);
		}
		printf("\n");
	}  
}
	