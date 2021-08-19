#include <stdio.h>
#include <time.h>
#include "test2.c"

int g_int = 0;

void func_sec();



int main()
{
	printf("g_int in main function %d %p\n", g_int, &g_int);
	func_sec();
	printf("g_int in main function %d %p\n", g_int, &g_int);
	time_t t = time(0);
	printf("%lld\n", t);	
}