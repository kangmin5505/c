#include <stdio.h>

long get_long(void);

int main()
{
    long number;
    
    while (1)
    {
        printf("Please input a integer between 1 and 100.\n");
        number = get_long();

        if (number > 1 && number < 100)
        {
            printf("OK. Thank you\n");
            break;
        }
        else
            printf("Wrong input. Please try again.\n");
    }
        
    return 0;
}

long get_long(void)
{
    printf("Please input an integer and press enter.\n");

    long input;
    char c;

    while (scanf("%ld", &input) != 1)
    {
        printf("Your input - ");

        while ((c = getchar()) != '\n')
            putchar(c);

        printf(" - is not an integer. Please try again.\n");
    }

    printf("Your input %ld is an integer. Thank you.\n", input);

    return input;
}
