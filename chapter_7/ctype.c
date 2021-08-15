#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch;

    while ((ch = getchar()) != '\n')
    {
        if (isalpha(ch))
            ch = 'a';
        else
            ch = '0';
        putchar(ch);
    }

    putchar(ch);
    
    return 0;
}