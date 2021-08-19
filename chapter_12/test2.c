#include <stdio.h>

extern int g_int;

void func_sec()
{
    g_int += 7;
	printf("g_int in second function %d %p\n", g_int, &g_int);

}