#include <stdio.h>
#include <ctype.h>

void UpdateString(char* str, int(*pt)(int));

int main()
{
    char str[] = "Hello, World!";

    UpdateString(str, toupper);

    printf("Toupper %s\n", str);

    UpdateString(str, tolower);

    printf("Tolower %s\n", str);

    return 0;
}

void UpdateString(char* str, int(*pf)(int))
{
    while (*str) {
        *str = (*pf)(*str);
        str++;
    }
}