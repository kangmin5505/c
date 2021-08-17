#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main(void)
{
    unsigned int u_max = UINT_MAX;
    unsigned int u_min = 0;
    signed int i_max = INT_MAX;
    signed int i_min = INT_MIN;
    

    printf("max of uint = %u\n", u_max);
    printf("min of uint = %u\n", u_min);
    printf("max of int = %d\n", i_max);
    printf("min of int = %d\n", i_min);

}
