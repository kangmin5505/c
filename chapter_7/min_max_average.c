#include <stdio.h>
#include <float.h>

int main()
{
    float max = -FLT_MAX;
    float min = FLT_MAX;
    float sum = 0.0f;
    float input;
    int n = 0;

    printf("Enter number between 1 and 100\n");

    while (scanf("%f", &input) == 1)
    {
        if (input < 0.0f || input > 100.0f) continue;

        max = input > max ? input : max;
        min = input < min ? input : min;
        sum += input;
        n++;
    }

    if (n > 0)
        printf("max : %f min : %f sum : %f\n", max, min, sum);
    else
        printf("No input\n");

    return 0;
}