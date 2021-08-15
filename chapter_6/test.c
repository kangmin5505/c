#include <stdio.h>
#define SIZE 5

int main()
{
  int my_arr[SIZE];
  int number = 0;
  
  for (int i = 0; i < SIZE; i++)
  {
    scanf("%d", &number);
    my_arr[i] = number;
  }

  for (int i = 0; i < SIZE; i++)
  {
      printf("%d\n", my_arr[i]);
  }

  return 0;
}