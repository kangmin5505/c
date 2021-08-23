#include <stdio.h>
#include <math.h> // pow()
#include <string.h> // strlen()
#include <stdlib.h> // exit()
#include <stdbool.h>

unsigned char to_decimal(const char bi[]);
void print_binary(const unsigned char num);

int main()
{
    unsigned char a = to_decimal("0000110");
    unsigned char b = to_decimal("0000101");

    printf("%hhu\n", a);
    print_binary(a);

    printf("%hhu\n", b);
    print_binary(b);

    printf("%hhu\n", a & b);
    print_binary(a & b);

    printf("%hhu\n", a | b);
    print_binary(a | b);

    printf("%hhu\n", a ^ b);
    print_binary(a ^ b);

    printf("%hhu\n", (unsigned char)~a);
    print_binary(~a);

}

unsigned char to_decimal(const char bi[])
{
    const size_t bits = strlen(bi);
    unsigned char sum = 0;
    for (size_t i = 0; i < bits; i++) {
        if (bi[i] == '1')
            sum += (int)pow(2, bits - 1 - i);
        else if (bi[i] != '0') {
            printf("Wrong character : %c", bi[i]);
            exit(1);
        }
    }

    return sum;
}

void print_binary(const unsigned char num)
{
    const size_t bits = sizeof(num) * 8;
    for (size_t i = 0; i < bits; i++) {
        const unsigned mask = (unsigned char)pow((double)2, (double)bits - 1 - i);

        if ((num & mask) == mask)
            printf("%d", 1);
        else
            printf("%d", 0);
    }
printf("\n");
}