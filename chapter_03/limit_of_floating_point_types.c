#include <stdio.h>
#include <float.h>

int main()
{
    // round-off errors (ex1)
    float a, b;
    a = 1.0E20f + 1.0f;
    b = a - 1.0E20f;
    printf("%f\n", b);

    // round-off errors (ex2)
    float c = 0.0f;
    
    for(int i=0; i<100; i++){
        c = c + 0.01f;
    }
    printf("%f\n", c);

    // overflow
    float max = FLT_MAX;
    printf("%f\n", max);
    max = max * 100.0f;
    printf("%f\n", max);

    // underflow
    float f = FLT_MIN;
    printf("%e\n", f);
    f = f / 100000000000000.0f; // subnormal
    printf("%e\n", f);

    float f2 = 104.0f;
    printf("%f\n", f2);
    f2 = f2 / 0.0f;
    printf("%f\n", f2);

    return 0;
}