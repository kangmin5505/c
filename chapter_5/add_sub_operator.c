#include <stdio.h>

int main()
{
    int a = 0;
    a++;
    printf("%d\n", a);

    ++a;
    printf("%d\n", a);

    double b = 0;
    b++;
    printf("%f\n", b);

    ++b;
    printf("%f\n", b);

    int count = 0;
    while (count++ < 10)
    {
        printf("%d ", count);

    }

    printf("\n");

    // int i = 1, j = 1;
    // int i_post, pre_j;

    // i_post = i++;
    // pre_j = ++j;

    // printf("%d %d\n", i, j);
    // printf("%d %d\n", i_post, pre_j);

    int i = 3;
    int l = 2 * --i;
    printf("%d %d\n", i, l);

    i = 1;
    l = 2 * i--;
    printf("%d %d\n", i, l);

    int x, y, z;
    x = 3, y = 4;
    z = x * y++;
    printf("%d %d %d\n", x, y, z);


    return 0; 
}