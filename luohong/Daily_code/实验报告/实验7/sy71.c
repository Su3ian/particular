#include <stdio.h>
#define N 5
struct student{	long num;	char name[10];	char sex;	float score[3];};
void print(struct student str[N]);

int main( void)
{	
    struct student str[N];	int a;	
    for (a = 0; a < N; a++)	
    {		
        printf("Enter the No.%d student name:\n", a + 1);
        scanf("%s", &str[a].name);	
        printf("Enter his or her num and sex and three scores:\n");
        scanf("%ld, %c, %f, %f, %f", 
        &str[a].num, &str[a].sex, &str[a].score[0], &str[a].score[1], &str[a].score[2]);		
        
        while (getchar() != '\n')	
        continue;	
    }	
    print(str);
    return 0;
}
void print(struct student str[])
{	
    int a;	
    float average[N];	
    struct student *p = NULL;	
    for (a = 0, p = str; p < str + N; a++, p++)	
    {		
        printf("The No.%d student personal information:\n", a + 1);		
        printf("%ld%10s%2c %5.2f %5.2f %5.2f\n", 
        (*p).num, (*p).name, (*p).sex, (*p).score[0], (*p).score[1], (*p).score[2]);	
    
    }	
    for (a = 0; a < N; a++)	
    {		
        average[a] = (str[a].score[0] + str[a].score[1] + str[a].score[2]);		
        printf("The No.%d student average grades: %5.2f\n", a + 1, average[a]/3);	    
    }
}
