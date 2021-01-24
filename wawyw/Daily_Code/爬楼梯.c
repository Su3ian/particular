//假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
//每次你可以爬 1 或 2 级台阶。你有多少种不同的方法可以爬到楼顶呢？
#include<stdio.h>
int floors(int i);

int main(void) {
	int n,i;
	printf("你想爬到多少阶楼梯？");
	scanf("%d", &n);
	for (i = 1; i < n; i++) {
		floors(i);
	}
	printf("方法共有%d种。", floors(i));
	return 0;
}

int floors(int i) {
	if (i == 1) {
		return 1;
	}
	else if (i == 2) {
		return 2;
	}
	else{
	return floors(i - 1) + floors(i - 2);
	}
}