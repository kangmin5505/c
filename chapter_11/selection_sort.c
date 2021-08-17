#include <stdio.h>

void swap(int* xp, int* yp);
void printArray(int arr[], int size);
void selectionSort(int arr[], int n);

int main()
{
    int arr[] = { 64, 25, 12, 22, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);

    printArray(arr, n);

    return 0;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[min_idx] > arr[j])
                min_idx = j;
        }
        swap(&arr[i], &arr[min_idx]);
    }
}

void swap(int* xp, int* yp)
{
    int tmp = *xp;
    *xp = *yp;
    *yp = tmp;
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}