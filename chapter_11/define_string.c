#include <stdio.h>

#define MESSAGE "A symbolic string contant"
#define MAXLENGTH 81

int main()
{
    // 배열로 문자열을 선언하는 경우, 배열이 가지고 있는 메모리에 문자열이 저장 되는 것
    char words[MAXLENGTH] = "A string in an array";
    // 포인터로 문자열을 선언하는 경우, 어딘가에 있는 문자열의 첫 번째 주소만 가져오는 것
    const char* pt1 = "A pointer to a string";

    puts("Puts() adds a newline at the end:"); // puts() add \n at the end
    puts(MESSAGE);
    puts(words);
    puts(pt1);
    words[3] = 'p'; // OK
    puts(words);
    //   pt1[8] = 'A' // Error

    const char m1[15] = "Love you!";

    for (int i = 0; i < 15; i++)
        printf("%d ", m1[i]);
    printf("\n");
    printf("%c", *m1);
}