//跑步时间里程转换    20.10.16  20：33
# include<stdio.h>

const int S_PER_M = 60;          //1分钟的秒数
const int S_PER_H = 3600;        //1小时的秒数
const double M_PER_K = 0.62137;  //1公里的英里数

int main(void)
{
    double distk, distm;         //跑过距离（分别为公里，英里）
    double rate;                 //平均速度（英里/小时）
    int min, sec;                //用时（分钟，秒）
    int time;                    //用时（秒）
    double mtime;                //跑1英里所需时间（秒）
    int mmin, msec;              //跑1英里所需时间（分钟，秒）
    
    printf("请输入你所跑公里：");
    scanf("%lf", &distk);

    printf("请输入所用时间(先输入分钟再输入秒数)\n");
    printf("输入分钟：\n");
    scanf("%d", &min);
    printf("输入秒数：\n");
    scanf("%d", &sec);

    time = S_PER_M * min + sec;        //时间转换成秒
    distm = M_PER_K * distk;           //公里转换成英里
    rate = distm / time * S_PER_M;     
    mtime = (double) time / distm;     
    mmin = (int) mtime / S_PER_M;      //求分钟数
    msec = (int) mtime % S_PER_M;      //求剩余秒数

    printf("你跑了%1.2f 公里 (%1.2f 英里)，用时:%d分钟%d秒\n", 
    distk, distm, min, sec);
    printf("每圈用时：%d分钟%d秒\n平均速度为%1.2f英里/小时\n", 
    mmin, msec, rate);

    return 0;
}