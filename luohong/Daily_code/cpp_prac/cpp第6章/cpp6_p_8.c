#include <stdio.h>//da和de不同储蓄方式比较 20.10.27  17：03
int main(void)
{
    float de = 100, da_m, da = 100;//成本都为100
    int year;

    da_m = 0.1 * da;  //da每年所得利息

    for ( year = 0; de <= da; year++)
    {
        da += da_m;
        de *= 1.05;  //本带息
    }

    printf("经过%d年，De的总资产超过Da\n", year);
    printf("De的总资产为%f美元，Da的总资产为%f美元.\n", de, da);
    
    return 0;
}