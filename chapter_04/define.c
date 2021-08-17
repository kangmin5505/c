#include <stdio.h>
// #define PI 3.141592f

int main()
{
    float radius, area, circum;

    float const PI = 3.141592f;

    printf("Input radius\n");

    scanf("%f", &radius);

    area = PI * radius * radius;
    circum = 2.0f * PI * radius;

    printf("Area is %f\n", area);
    printf("Circumference is %f\n", circum);

    return 0;
}