#include <stdio.h>

long loop_factorial(int n);
long recursive_factorial(int n);

int main()
{
    int num = 5;

    printf("%d\n", loop_factorial(num));
    printf("%d\n", recursive_factorial(num));

    return 0;
}

long loop_factorial(int n)
{
    if (n >= 2)
        return n * loop_factorial(n - 1);
    else
        return 1;
}

long recursive_factorial(int n)
{
    long sum;

    for (sum = 1; n > 1; n--)
    {
        sum *= n;
    }

    return sum;
}