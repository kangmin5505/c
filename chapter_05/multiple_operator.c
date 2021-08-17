#include <stdio.h>

int main()
{
    double seed_money, target_money, annaul_interest;

    printf("Input seed money : ");
    scanf("%lf", &seed_money);

    printf("Input target money : ");
    scanf("%lf", &target_money);

    printf("Input annual_interest (%%): ");
    scanf("%lf", &annaul_interest);

    double fund = seed_money;
    int year_count = 0;

    while (fund < target_money)
    {
        fund += fund * annaul_interest / 100.0;
        year_count++;
    }

    printf("It takes %d years\n", year_count);
}