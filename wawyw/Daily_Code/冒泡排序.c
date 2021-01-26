#include<stdio.h>
#include<stdlib.h>
void bubble(int arr[],int len);
int main(void)
{
	int i,j,len;
	printf("Please input array's length\n");
	scanf("%d",&len);
	int* arr;
	arr = (int*)calloc(len,sizeof(int));
	printf("Please input the numbers\n");
	for(i=0;i<len;i++){
		scanf("%d",&arr[i]);
	}
	bubble(arr, len);
	printf("result:\n");
	for (i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}

void bubble(int arr[], int len) {
	int i, j, temp;
	for (i = 0; i < len-1; i++) {
		for (j = 0; j < len - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				temp=arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
