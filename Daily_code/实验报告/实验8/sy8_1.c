#include <stdio.h>
#include <stdlib.h>
#define K 3
#define NUM 10
int main(void)
{
    FILE *f1, *f2, *f3;
    int key = K;
    int m, temp, mesg;
    char c, ct, cc;
    char name[NUM][10];
    printf("输入1为文件加密，输入2为文件解密，输入其他字符结束程序\n");


    while (scanf("%d", &m))
    {
        if (m == 1)
        {
            //由用户输入需加密文件并自定义输出密文文件名
            printf("请输入需加密文件名:\n");
            scanf("%s", name[0]);
            getchar();
            f1 = fopen(name[0],"r");
            printf("请输入密文所需倒入文件名:\n");
            scanf("%s", name[1]);
            f2 = fopen(name[1],"w");
            
            if (f1 == NULL || f2 == NULL)
            {
                printf("无法打开file1\n");
                exit(0);
            }

            while ( ( c = getc(f1) ) != EOF)
            {
                temp = (int)c + key;
                cc = (char)temp;
                printf("%c", cc);
                fprintf(f2,"%c",cc);

            }
            fclose(f2);
            fclose(f1);
            printf("\nfile1已加密\n");    
        }

        else if (m == 2)
        {
            //由用户输入需解密文件名并自定义输出明文文件名
            printf("请输入需解密文件名:\n");
            scanf("%s", name[2]);
            getchar();
            f1 = fopen(name[2],"r");
            printf("请输入明文所需导入文件名:\n");
            scanf("%s", name[3]);
            f2 = fopen(name[3],"w");
            
            if (f1 == NULL || f2 == NULL)
            {
                printf("file2无法打开\n");
                exit(0);
            }

            while (fscanf(f1,"%c",&temp) != EOF)
            {
                mesg = (int)temp - key;
                ct = (char)mesg;
                printf("%c", ct);
                fprintf(f2,"%c",ct);
            }
            fclose(f2);
            fclose(f1);
            printf("\nfile2已解密\n");
        }

        else
        {
            printf("程序结束运行\n");
            break;
        }
    }

    return 0;
}