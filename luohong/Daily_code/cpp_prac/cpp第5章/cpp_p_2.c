//棋盘问题（指数增长）   20.10.16   19:39
# include<stdio.h>
# define SQUARES 64    //棋盘中方格数
int main(void)
{
    const double CROP = 2E16;   //世界小麦年产总数
    double current, total;
    int count = 1;

    printf(" square    qrains        total     ");
    printf("fraction of  \n");
    printf("           added        qrains     world total\n");
    total = current = 1.0;
    do
    {
        printf("%4d %13.2e %12.2e %12.2e\n", count, current, total, 
               total / CROP);
               count++;
               current = 2.0 * current;  //下个方格谷粒翻倍
               total = total + current;  //更新总数

    } while (count < SQUARES);

    printf("That is all\n");

    return 0;
}