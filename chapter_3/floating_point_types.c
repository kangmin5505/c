#include <stdio.h>
#include <float.h>

int main()
{
    printf("%u\n", sizeof(float));
    printf("%u\n", sizeof(double));
    printf("%u\n", sizeof(long double));

    float f = 123.456f;
    double d = 123.456;

    float f2 = 123.456f; //123.456은 작은 자료형에 큰 자료형을 넣어서 에러 남
    double d2 = 123.456;

    int i = 3;
    float f3 = 3.0f;
    double d3 = 3.0;

    float f4 = 1.234e10f;

    float f5 = 0xb.ap1;
    double d5 = 1.0625e0;

    printf("%f %F %e %E\n", f, f, f, f);
    printf("%f %F %e %E\n", d, d, d, d);
    printf("%a %A\n", f5, f5);
    printf("%a %A\n", d5, d5);

    return 0;
}