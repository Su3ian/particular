# include<stdio.h>
int main(void)
{
    char name[10], firstname[10];

    scanf("%s%s", name, firstname);
    printf("\"%s,%s\"\n", name, firstname);
    printf("\"%20s,%s\"\n", name, firstname);
    printf("\"%s,%-20s\"\n", name, firstname);
    printf("\"%3s,%3s\"\n", name, firstname);//搞不来，遗留问题

    return 0;
}