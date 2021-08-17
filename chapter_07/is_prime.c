#include <stdio.h>
#include <stdbool.h>

int main()
{
    unsigned num;
    bool isPrime = true;

    scanf("%u", &num);

    for (int i = 2; i*i < num; i++)
    {
        if (num % i == 0)
        {
            isPrime = false;
            printf("divide number is %d %d\n", i, num/i);
        }
    }


    if (isPrime)
        printf("%u is a prime number\n", num);
    else
        printf("%u is not a prime number\n", num);
    
    return 0;
}