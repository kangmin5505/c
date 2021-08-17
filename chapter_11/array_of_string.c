#include <stdio.h>

int main()
{
    const char* mythings[3] = {
        "Dancing in the rain",
        "Counting apples",
        "Watching movies with friends"
    };

    char yourthings[3][40] = {
        "Studying the C++ language",
        "Eating",
        "Watching Netfilx"
    };

    for (int i = 0; i < 150; i++)
        printf("%c ", mythings[0][i]);
    printf("\n");
    
    for (int i = 0; i < 150; i++)
        printf("%c ", yourthings[0][i]);
     
}