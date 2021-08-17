#include <stdio.h>

int main()
{
    // int seconds = 0, minutes = 0, hours = 0;

    // printf("Input seconds : ");
    // scanf("%d", &seconds);

    // hours = seconds / 3600;
    // minutes = seconds % 3600 / 60;
    // seconds %= 60;

    // printf("%d hours, %d minutes, %d seconds\n", hours, minutes, seconds);

    int div, mod;

    div = 11 / 5;
    mod = 11 % 5;
    printf("div = %d, mod = %d\n", div, mod);

    div = 11 / -5;
    mod = 11 % -5;
    printf("div = %d, mod = %d\n", div, mod);

    div = -11 / -5;
    mod = -11 % -5;
    printf("div = %d, mod = %d\n", div, mod);

    div = -11 / 5;
    mod = -11 % 5;
    printf("div = %d, mod = %d\n", div, mod);


    return 0;
}