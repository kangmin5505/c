#include <stdio.h>

int main(void)
{
    int i = 0, j = 0;

    printf("Enter two number:\n");
    scanf("%d%d", &i, &j);

    int z = i + j;
    printf("Sum is %d", z);

    return 0;
}