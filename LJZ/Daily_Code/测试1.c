#include<stdio.h>
#include<stdbool.h>
struct date{
	int month;
	int day;
	int year;
};
bool isleap(struct date d);
int numberofdate(struct date day);
int main()
{
	struct date today,tomorrow;
	printf("请输入今天的日期");
	scanf("%i,%i,%i",&today.day,&today.month,&today.year);
	if(today.day != numberof(today)){
		tomorrow.day = today.day + 1;
		tomorrow.month = today.month ;
		tomorrow.year = today.year;
	} else if(today.month == 12){
		tomorrow.day = 1;
		tomorrow.month = 1;
		tomorrow.year = today.year + 1;
	}else{
		tomorrow.day = 1;
		tomorrow.month = today.month + 1;
		tomorrow.year = today.year;
	}
	return 0;
}
 int numberofdate(struct date d){
 	int days;
	 const int month [] = {31,28,31,30,31,31,31,30,31,31,30,31};
 	if (d.month == 2 && isleap(d)){
 		days = 29;
	 }else {
	 	days = month[d.month - 1];
	 }
	 return days;
 }
 
 bool isleap(struct date d)
 {
 	bool isleap = false;
 	if(((d.year % 4 == 0 )&& (d.year % 100 ==0) ) || (d.year % 400 == 0))
 	isleap = true;
 	return isleap;
 }
