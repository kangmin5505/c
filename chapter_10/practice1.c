#include <stdio.h>

#define MONTHS 12
#define YEARS 3

int main()
{
    double year[YEARS][MONTHS] = {
        { -4.0, -1.6, 8.1, 13.0, 18.2,	23.1, 27.8, 28.8, 21.5,	13.1, 7.8, -0.6 },
        { -0.9, 1.0, 7.1, 12.1, 19.4, 22.5, 25.9, 27.2, 22.6, 16.4, 8.6, 1.4 },
        { 1.6, 2.5, 7.7, 11.1, 18.0, 23.9, 24.1, 26.5, 21.4, 14.3, 8.0, -0.4 }
    };

    printf("[Temperature Data]\n");
    printf("Year index :");
    for (int i = 0; i < MONTHS; i++)
        printf("\t%d", i + 1);
    printf("\n");

    for (int i = 0; i < YEARS; i++)
    {
        printf("YEAR %d :", i + 2018);
        for (int j = 0; j < MONTHS; j++)
            printf("\t%0.1f", year[i][j]);
        printf("\n");
    }
    printf("\n");

    printf("[Yearly average tmperatures of 3 years]\n");
    for (int i = 0; i < YEARS; i++)
    {
        printf("YEAR %d : ", i + 2018);
        double total = 0.0;
        for (int j = 0; j < MONTHS; j++)
            total += year[i][j];
        printf("average temperature = %0.1f\n", total / MONTHS);
    }
    printf("\n");

    printf("[Monthly average temperatures for 3 years]\n");
    printf("Year index : ");
    for (int i = 0; i < MONTHS; i++)
    {
        printf("\t%d", i + 1);
    }
    printf("\n");

    printf("Avg temps :");
    for (int i = 0; i < MONTHS; i++)
    {
        double total = 0.0;
        for (int j = 0; j < YEARS; j++)
            total += year[j][i];
        printf("\t%0.1f", total / YEARS);
    }
    printf("\n");
}