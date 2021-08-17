#include <stdio.h>

int main()
{
    const char* pt2 = "I am a string!";
    const char* pt3 = "I am a string!";
    const char* pt4 = "I am a string!!!!";
    const char arr1[] = "I am a string!";
    const char arr2[] = "I am a string!";
    const char arr3[] = "I am a string!!!";

    printf("rodata low %llu %llu %llu %llu\n", 
    (unsigned long long)pt2, (unsigned long long)pt3, (unsigned long long)pt4,
    (unsigned long long)"I am a string!");

    printf("stack high %llu %llu %llu\n", 
    (unsigned long long)arr1, (unsigned long long)arr2, (unsigned long long)arr3);
}