#include <stdio.h>
#include <math.h>  // pow()
#include <string.h> // strlen()
#include <stdlib.h> // exit()

unsigned char to_decimal(const char bi[]);

int main()
{
    printf("Binary (string) to Decimal conversion\n");

    printf("%d\n", to_decimal("00000110"));
    printf("%d\n", to_decimal("00010110"));

    printf("%d\n", to_decimal("10010100"));

    return 0;
}

unsigned char to_decimal(const char bi[])
{
    const size_t bits = strlen(bi);
    unsigned char sum = 0;
    for (size_t i = 0; i < bits; i++) {
        if (bi[i] == '1')
            sum += (int)pow(2, bits - 1- i);
        else if (bi[i] != '0') {
            printf("Wrong character : %c", bi[i]);
            exit(1);
        }
    }

    return sum;
}