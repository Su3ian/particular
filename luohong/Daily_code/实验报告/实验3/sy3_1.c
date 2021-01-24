#include <stdio.h>               //凯撒密码
int main(void)
{
    int i, key;
    char msg, ct;

    printf("Input a key between 0~25 :\n");
    printf("key = ");
    scanf("%d", &key);           //输入密钥

    printf("Enter a message:\n");
    getchar();                   //读取‘\n’

    for ( i = 0; ; i++)
    {
        scanf("%c", &msg);       //读取字符串，储存在缓冲区
        if(msg >= 'a' && msg <= 'z')
        {
            ct = (msg -'a' +key) % 26 + 'a';
            printf("%c", ct);
        }
        else if (msg >= 'A' && msg <= 'Z')
        {
            ct = (msg -'A' +key) % 26 + 'A';
            printf("%c", ct);
        }
        else if (msg == ' ')
        printf("%c", msg);
        else
        break;

    }
    printf("\n");

    printf("Enter a ciphertext:\n");
    
    for ( i = 0; ; i++)
    {
        scanf("%c", &ct);           //读取字符串，储存在缓冲区
        if(ct >= 'a' && ct <= 'z')
        {
            msg = (ct -'a' -key +26) % 26 + 'a';
            printf("%c", msg);
        }
        else if (ct >= 'A' && ct <= 'Z')
        {
            msg = (ct -'A' -key +26) % 26 + 'A';
            printf("%c", msg);
        }
        else if (ct == ' ')
        printf("%c", ct);
        else
        break;

    }
    printf("\n");
    
    
    return 0;
}