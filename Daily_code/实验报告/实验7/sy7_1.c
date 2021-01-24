#include <stdio.h>
#define N 5
typedef struct student
{
    int stu;
    char name[10];
    char sex;
    double score[3];

}student;

int main(void)
{
    student stud[N];
    double sum_aver[3];
    printf("请按顺序输入相关数据\n学号 姓名 性别 成绩\n");
    for (int i = 0; i < N; i++)
    {
        printf("请输入第%d个同学的名字:\n", i + 1);
        scanf("%s", &stud[i].name);
        
        printf("请输入第%d个同学的学号，性别，三科成绩:\n", i + 1);
        scanf("%d, %c, %lf, %lf, %lf", 
        &stud[i].stu, &stud[i].sex, &stud[i].score[0], &stud[i].score[1], &stud[i].score[2]);

        while (getchar() != '\n')
        continue;        
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        sum_aver[i] += stud[i].score[j];
    }
    int i = 0;
    student * p = NULL;
    for (p = stud; p < stud + N; i++, p++)
    {
        
        
        printf("%2d%10s%2c %5.2lf %5.2lf %5.2lf %5.2lf\n", 
        (*p).stu, (*p).name, (*p).sex, (*p).score[0], (*p).score[1], (*p).score[2], sum_aver[i]/3);

    }
    return 0;
}