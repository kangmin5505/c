#include <stdio.h>

int main()
{
    FILE* fp = fopen("input.txt", "rb");

    unsigned char ch;

    while (fread(&ch, sizeof(unsigned char), 1, fp) > 0)
        printf("%hhu %c\n", ch, ch);
    fclose(fp);

    return 0;
}