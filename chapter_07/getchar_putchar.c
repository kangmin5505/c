#include <stdio.h>

int main(void)
{
    char ch;

    while ((ch = getchar()) != '\n')
    {
        if (ch >= 'a' && ch <= 'z')
            ch -= 32;
        else if (ch >= 'A' && ch <= 'Z')
            ch += 'a' - 'A';      
             
        putchar(ch);
    }
    

    return 0;
}