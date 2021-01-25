#include <stdio.h>  //统计字符数，单词数，行数 20.10.27  18：05
#include <ctype.h>
#include <stdbool.h>
#define STOP '|'

int main(void)
{
    char c;  //读入字符
    char prev;  //读入的前一个字符
    long n_chars = 0L;  //字符数
    int lines = 0, words = 0, p_lines = 0;  //行数，单词数，不完整行数
    bool inword = false;  //读取单词时，inword为ture

    printf("输入段落（输入|停止）：");
    prev = '\n';
    while((c = getchar()) != STOP)
    {
        n_chars++;  //统计字符

        if(c == '\n')
        lines++;    //统计行数
        if(!isspace(c) && !inword)
        {
            inword = true;  //开始新的单词
            words++;        //统计单词
        }
        if(isspace(c) && inword)
        inword = false;     //打到单词末尾

        prev = c;           //保存字符的值
    }

    if(prev != '\n')
    p_lines = 1;

    printf("字符数：%ld，单词数：%d，行数：%d，不完整行数：%d\n", 
    n_chars, words, lines, p_lines);

    return 0;
}