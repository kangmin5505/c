#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row = 3, col = 2, depth = 2;
    int* ptr = (int*)malloc(sizeof(int) * row * col * depth);
    if (ptr == NULL) exit(1);

    for (int d = 0; d < depth; d++)
        for (int r = 0; r < row; r++)
            for (int c = 0; c < col; c++)
                ptr[c + col * r + col * row * d] = c + col * r + col * row * d;

    for (int d = 0; d < depth; d++)
    {
        for (int r = 0; r < row; r++)
            {
                for (int c = 0; c < col; c++)
                    printf("%d ", ptr[c + col * r + col * row * d]);
                printf("\n");
            }
        printf("-------------\n");
    }
        

    return 0;
}