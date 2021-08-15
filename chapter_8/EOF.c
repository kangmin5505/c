#include <stdio.h>

int main()
{
    char c;

    while (1)
    {
        c = getchar();
        printf("%d\n", c);
        if (c == EOF)
        {
            printf("EOF is %d\n", c);
            break;
        }
    }

    return 0;
}