#include <stdio.h>

void print_binary(unsigned long n);
void print_binary_loop(unsigned long n);

int main()
{
    unsigned long num = 10;

    printf("%d\n", sizeof(num));

    print_binary_loop(num);
    print_binary(num);

    printf("\n");

    return 0;
}

void print_binary(unsigned long n)
{
    int remainder = n % 2;

    if (n >= 2)
        print_binary(n / 2);
    
    printf("%d", remainder);

    return;        
}

void print_binary_loop(unsigned long n)
{
    while (1)
    {
        int quotient = n / 2;
        int remainder = n % 2;

        printf("%d", remainder);

        n = quotient;

        if (n == 0) break;
    }

    printf("\n");
}