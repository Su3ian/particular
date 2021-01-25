/*给出两个数组s[0..k ]和 r[0..k ]. 在数组s[0..k ]中,所有的元素都是互质, 编程找到满足下列条件的最小正数 x
x% s[0] = r[0]
x % s[1] = r[1]
......
x % s[k] = r[k]*/
#include<stdio.h>
#include <stdlib.h>
int main(void)
{
	int n,x=0;
	printf("数组元素个数\n");
	scanf("%d", &n);
	
	int* s;
	s = (int*)calloc(n, sizeof(int));
	printf("数组s元素:\n");
	for (int i = 0; i < n; i++) {
		scanf("%d", &s[i]);
	}
	
	int* r;
	r = (int*)calloc(n, sizeof(int));
	printf("数组r元素:\n");
	for (int i = 0; i < n; i++) {
		scanf("%d", &r[i]);
	}
	
	for (int i = 1; i < 10000; i++) {
		for (int j = 0; j < n; j++) {
			if (i % s[j] == r[j])
				x++;
		}
		if (x == n) {
			x = i;
			break;
		}
		else {
			x = 0;
		}
	}
	
	if(x != 0){
		printf("x的值为:%d\n", x);
	}
	else{
		printf("找不到满足此条件x的值\n");	
	}
	
	return 0;
}