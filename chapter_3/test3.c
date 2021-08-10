#include <stdio.h>

int main()
{
    char c = 65;
    short s = 256;
    unsigned int ui = 3000000000U;
    long l = 65537L;
    long long ll = 12345678908642LL;

    printf("char = %hhd, %d, %c\n", c, c, c);
    printf("short = %hhd, %d, %d\n", s, s, s);
    printf("unsigned int = %u, %d\n", ui, ui);
    printf("char = %ld, %hd\n", l, l);
    printf("char = %lld, %ld\n", ll, ll);
}