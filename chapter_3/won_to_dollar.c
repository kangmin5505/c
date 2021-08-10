#include <stdio.h>

int main(void)
{
    float won = 0.0f;
    float dollar = 0.0f;

    printf("Enter Won:\n");
    scanf("%f", &won);

    dollar = won * 0.00089f;

    printf("Won to dollar : %f", dollar);

    return 0;
}