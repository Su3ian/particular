#include <stdio.h>               //凯撒密码
# define NUM 40
int main(void)
{
    int i, key;
    char msg[NUM];
    char ct[NUM];

    printf("Input a key between 0~25 :\n");
    printf("key = ");
    scanf("%d", &key);           //输入密钥

    printf("Enter a message:\n");
    getchar();                   //读取‘\n’

    for ( i = 0; ; i++)
    {
        scanf("%c", msg + i);
        
        if(msg[i] >= 'a' && msg[i] <= 'z')
            msg[i] = (msg[i] -'a' +key) % 26 + 'a';
        else if (msg[i] >= 'A' && msg[i] <= 'Z')
            msg[i] = (msg[i] -'A' +key) % 26 + 'A';
        else if (msg[i] == ' ')
        {
            printf(" ");
            continue;
        }
        else
        break;
        
        printf("%c", msg[i]);
    }
    printf("\n");

    printf("Enter a ciphertext:\n");
    
    for ( i = 0; ; i++)
    {
        scanf("%c", ct + i);           //读取字符串，储存在缓冲区
        
        if(ct[i] >= 'a' && ct[i] <= 'z')
            ct[i] = (ct[i] -'a' -key +26) % 26 + 'a';
        else if (ct[i] >= 'A' && ct[i] <= 'Z')
            ct[i] = (ct[i] -'A' -key +26) % 26 + 'A';
        else if (ct[i] == ' ')
        {
            printf(" ");
            continue;
        }        
        else
        break;
        
        printf("%c", ct[i]);
    }
    printf("\n");
    
    
    return 0;
}