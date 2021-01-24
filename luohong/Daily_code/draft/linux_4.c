#include <stdio.h>
int main(int argc, char * argv[])
{
    char ch = 'A';
    int i = 65;
    unsigned int f = 33554433;
    
    *(int *)&f >>= 24;                                  
    /*&f取f的地址，(int *)将该指针强制转换成整形指针，
    然后最左边的*就是取该指针指向的值，即f，而>>=是将f
    的值转换成二进制，之后再将二进制值右移24位(33554433
    对应二进制为10[24个0]1,右移后即10,对应十进制为2,则
    f的值为2)*/
    *(int *)&f = *(int *)&f + '?';
    
    printf("ch = %c i = %c f = %c\n", ch, i, *(int *)&f);
    printf("%d\n", '@' - '?');
    printf("%d\n", 'A' - '?');
    return 0;
}