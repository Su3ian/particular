# include<stdio.h>
int main(void)
{
    int c, cs;
    char element = 'A';              //行数和列数


        for(cs = 1; cs <= 6; cs++)
        {
            for(c = 0; c < cs; c++)
            {
                printf("%c", element);
                element = element + 1;
            }
            printf("\n");
        }    

    return 0;
}