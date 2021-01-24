# include<stdio.h>
int main(void)
{
    float tall;
    char name[10];

    printf("Please enter your name:");
    scanf("%s", name);

    printf("Please enter your height(cm):");
    scanf("%f", &tall);

    printf("%s, you are %.2fm feet tall\n", name, tall / 100);

    return 0;
}