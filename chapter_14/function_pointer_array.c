#include <stdio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>

void update_string(char* str, int(*pf)(int));
void ToUpper(char* str);
void ToLower(char* str);
void Transpose(char* str);

int main()
{
    char options[] = { 'u', 'l', 't' };
    int n = sizeof(options) / sizeof(options[0]);

    typedef void (*FUNC_TYPE)(char*);
    FUNC_TYPE operations[] = { ToUpper, ToLower, Transpose};

    printf("Enter a string\n>> ");

    char input[100];

    while (scanf("%[^\n]%*c", input) != 1) {
        printf("Please try again.\n>> ");
    }
    printf("Before %s\n", input);
    while (true) {
        printf("Choose an option:\n");
        printf("u) to upper\n");
        printf("l) to lower\n");
        printf("t) to transpose\n");

        char c;
        while (scanf("%c%*[^\n]%*c", &c) != 1) {
            printf("Please try again.\n");
        }

        bool found = false;

        for (int i = 0; i < n; i++)
        {
            if (options[i] == c) {
                (*(operations[i]))(input);
                found = true;
                break;
            }
        }

        if (found)
            break;
        else 
            printf("Wrong input. try again.\n");       
    }

    printf("output : %s\n", input);
    printf("%d", input);

    return 0;
}

void update_string(char* str, int(*pf)(int))
{
    while (*str) {
        *str = (*pf)(*str);
        str++;
    }
}

void ToUpper(char* str)
{
    update_string(str, toupper);
}

void ToLower(char* str)
{
    update_string(str, tolower);
}

void Transpose(char* str)
{
    while (*str) {
        if (islower(*str))
            *str = toupper(*str);
        else if (isupper(*str))
            *str = tolower(*str);
        str++;
    }
}
