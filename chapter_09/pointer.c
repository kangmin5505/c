#include <stdio.h>

int main()
{
    int a, b;

    a = 123;

    int *a_ptr;

    a_ptr = &a;

    printf("%d %d %p\n", a, *a_ptr, a_ptr);

    *a_ptr = 456;

    printf("%d %d %p\n", a, *a_ptr, a_ptr);

    return 0;
}