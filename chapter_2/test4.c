#include <stdio.h>

void say_hello(void);

int main(void)
{
    int x = 1, y = 2;

    int z = x + y;

    say_hello();

    return 0;
}

void say_hello(void)
{
    int x = 10;
    
    x = 20;

    printf("Hello");

    return;
}