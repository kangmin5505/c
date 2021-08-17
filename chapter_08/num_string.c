#include <stdio.h>

void display(char c, int rows, int cols);

int main()
{
    char c;
    int rows, cols;

    printf("Input one character and two integers:\n");
    while ((c = getchar()) != '\n')
    {
        scanf("%d %d", &rows, &cols);
        while (getchar() != '\n') continue;

        display(c, rows, cols);
        printf("Input another character and two integers:\n");
    }

    return 0;
}

void display(char c, int rows, int cols)
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
            putchar(c);
        putchar('\n');
    }
}