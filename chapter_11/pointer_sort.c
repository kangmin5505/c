#include <stdio.h>
#include <string.h>

void swap(char** xp, char** yp);
void printStringArray(char* arr[], int size);
void selectionSort(char* arr[], int n);

int main()
{
    char* arr[] = {"Cherry", "AppleBee", "Pineapple", "Apple", "Orange"};
    int n = sizeof(arr) / sizeof(arr[0]);

    printStringArray(arr, n);

    selectionSort(arr, n);

    printStringArray(arr, n);
}

void printStringArray(char* arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        puts(arr[i]);
    printf("\n");
}

void selectionSort(char* arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(arr[j], arr[min_idx]) < 0)
                min_idx = j;
        }
        swap(&arr[i], &arr[min_idx]);
    }
}

void swap(char** xp, char** yp)
{
    char* temp = *xp;
    *xp = *yp;
    *yp = temp;
}