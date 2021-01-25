#include<stdio.h>
#include<stdbool.h>

bool Is_LeapYear(int year);
int Month_Days(int year, int month);
int Year_Days(int month,int day);
int year,month,day;

bool Is_LeapYear(int year){
	if(year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)){
		return true;
	}
	else
		return false;
}

int Month_Days(int year, int month){
	int arr[] = {31,(Is_LeapYear(year)?29:28),31,30,31,30,31,31,30,31,30,31 };
	return arr[month-1];
}

int Year_Days(int month,int day){
	int sum = 0;
	for(int i=1;i<month;i++){
		sum += Month_Days(year,i);
	}
	return (sum+day);
}

int main(void) {
		while (1){
	printf("请输入年月日 ，年月日中间用空格隔开！\n");
	scanf("%d %d %d",&year,&month,&day);
	if (year < 0 || month<=0 || month>12){
		printf("输入有误，请重新输入\n");
		continue;
	}
	if (day >Month_Days(year, month) || day <= 0){
		printf("天数输入有误\n");
		continue;
	}
	if (Is_LeapYear(year)){
		printf("这年为闰年，共有366天\n",year);
	}
	else{
		printf("这年为平年，共有365天\n",year);
	}
	printf("这个月有%d天\n", Month_Days(year, month));
	printf("这是一年中的第%d天\n", Year_Days(month, day));
	printf("请输入是否继续(y/n)\n");
	char c;
	scanf("%s", &c);
	if (c == 'n'){
		printf("程序结束！");
		break;
		}
	}
	return 0;
}