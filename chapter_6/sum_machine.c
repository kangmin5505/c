#include <stdio.h>

int main()
{
    int num, sum = 0;

    printf("Enter an integer(q to quit) : ");

    while (scanf("%d", &num) == 1)
    {
        sum += num;

        printf("Enter an integer(q to quit) : ");

    }

    printf("Sum is %d\n", sum);
    
    return 0;
}