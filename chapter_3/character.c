#include <stdio.h>

int main()
{
    char c = 'A';
    char d = 65;

    printf("%c %hhd\n", c, c);
    printf("%c %hhd\n", d, d);

    printf("%c", c + 1);
    
    char a = '\a';
    printf("%c\n", a); 

    float salary;
    printf("$______\b\b\b\b\b\b");
    scanf("%f", &salary);

    printf("AB\tCDEF\tGHIJ\n");
    printf("ABC\tDEFG\tHIJ\n");

    printf("\\ \'HA+\' \"Helloe\" \?\n");

    return 0;
}