#include <stdio.h>

int main()
{
    // int* ptr = 0;

    // printf("%p %lld\n", ptr, (long long)ptr);

    // ptr += 1;

    // printf("%p %lld\n", ptr, (long long)ptr);

    int arr[10];
    int* ptr1 = &arr[1], * ptr2 = &arr[6];

    int i = ptr2 - ptr1;

    printf("%lld %lld %d", ptr1, ptr2, i);
}