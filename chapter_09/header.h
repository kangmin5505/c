#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define WIDTH 30
#define NAME "Kang-Min Kim"
#define ADDRESS "Ansan-si"


void print_centered_str(char str[]); 
void print_multiple_chars(char c, int n_stars, bool end_line);

void print_centered_str(char str[])
{
    int n_blanks = 0;
    n_blanks = (WIDTH - strlen(str)) / 2;
    print_multiple_chars(' ', n_blanks, false);
    printf("%s\n", str);
}

void print_multiple_chars(char c, int n_stars, bool end_line)
{
    for (int i = 0; i < n_stars; ++i)
        printf("%c", c);
    
    if (end_line)
        printf("\n");
    
}