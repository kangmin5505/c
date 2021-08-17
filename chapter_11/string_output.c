#include <stdio.h>

void custom_put(const char* str);
int custom_put2(const char* str);

int main()
{
    custom_put("Just ");
    custom_put("Do it!");

    printf("%d\n", custom_put2("12345"));
}

void custom_put(const char* str)
{
    while (*str != '\0')
        putchar(*str++);
}

int custom_put2(const char * str)
{
    int count = 0;
    while (*str)
    {
        putchar(*str++);
        count++;
    }
    putchar('\n');

    return count;
}