# 문자열 함수들

## 문자열을 정의하는 방법들
```C
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
  // 읽기 전용 메모리에 저장된 데이터의 값 변경 시도
  pt1[8] = 'A' // Error
}
```
* 포인터로 문자열을 다룰 때는 const 사용(포인터를 사용하다가 문자열이 변경되는 것을 방지하기 위해)
* 읽기 전용 메모리에 저장된 데이터의 값을 변경하려고 시도하면 운영체제가 중단시킴
* 배열은 읽기/쓰기가 모두 가능한 메모리를 사용하지만, 문자열 리터럴은 프로그램의 일부이기 때문에 읽기 전용 메모리에 저장

## 메모리 레이아웃과 문자열(Memory Layout)
* Memory Layout : 메모리를 효율적이고 안정적으로 사용하기 위해 규칙을 갖고 있음
  * Stack : 메모리가 얼마나 사용될지 아는 경우 사용하는 메모리 공간
  * Heap : 메모리가 얼마나 사용되는지 모르는 경우 사용하는 메모리 공간
  * Segment
* C언어 컴파일러는 동일한 문자열 리터럴이 프로그램 여러 곳에서 사용될 경우 한 곳에서만 저장하고 공유해서 사용(메모리 절약)
  * 여러 포인터가 동일한 문자열을 가리키는 경우가 발생할 수 있는데, 이때 문자열 리터럴의 값이 변경되면 큰 에러가 발생하므로 읽기 전용으로 설정
* 프로그램코드가 메모리에 올라와 있을 때는 운영체제가 읽기전용으로 바꿈
![image](https://user-images.githubusercontent.com/74703501/129749810-dcad89ef-d553-4298-a955-5aeafbe2d7c0.png)   
[출처](https://www.inflearn.com/course/following-c)
![image](https://user-images.githubusercontent.com/74703501/129749832-b911b494-7ee1-4514-bd63-118a5f2c7750.png)   
[출처](https://www.inflearn.com/course/following-c)
![image](https://user-images.githubusercontent.com/74703501/129749856-46487028-342c-4b0c-8f5b-fa20b213e01e.png)   
[출처](https://www.inflearn.com/course/following-c)

## 문자열의 배열
* 실행파일에 저장되어 있던 프로그램이 실제로 실행되기 위해서는 먼저 메모리로 복사되어야 함

## 문자열을 입력받는 다양한 방법들
* 입력을 받기 전에는 항상 메모리를 먼저 확보해야 함
* scanf() vs gets()
  * scanf() : reads one word 
  * gets(char* str) : reads one line and removes '\n' and add '\0'
    * gets receives pointer. No idea when string ends.
* printf() vs puts()
  * printf() : no '\n' at the end
  * puts() : adds '\n' at tne end
* gets_s(pointer, sizeof(words)) : 문자열 포인터와 문자열의 공간을 인수로 넣어줌
* fgets(pointer, sizeof(words), stdin) : 문자열 공간을 넘어가도 에러 발생 안 함(인수로 stdin 넣기) - 원래 파일을 다루는 함수
  * return 값 : 정상작동 시 입력 받은 pointer 반환 EOF 만날 시 NULL characters 반환
* fputs(pointer, stdout) : Does NOT add '\n'(인수로 stdout 넣기) - 원래 파일을 다루는 함수
* scanf_s(pointer, size, pointer, size)

## 문자열을 출력하는 다양한 방법들
* 문자열 배열을 직접 생성할 때 '\0'을 꼭 넣어줘야함
```C
char arr[3] = { 'H', 'i', '\0' };
```
* scanf() : 여러가지 자료형의 입력을 받을 때 유용, 띄어쓰기로 구분
## 다양한 문자열 함수들
* 문자열을 사용할 때는 메모리 공간이 잡혀있는지 확인하는 것이 중요
* strlen()
  * returns length of the string
* strcat(), strncat()
  * string (n) concatenation
* strcmp(), strncmp()
  * compare (n) strings(not characters)
  * 같으면 0 반환, 다른데 앞에 것이 아스키코드로 더 크면 1, 작으면 -1 반환
* strcpy(), strncpy()
  * 문자열을 포인터만 복사하는 것이 아니라, 내용물을 전부(n개) 복사
  * copy() : '\0' is not added
* sprintf() : 파일이름을 만들 때 주로 사용
* strchr(), strpbrk(), strchr(), strstr()

## 문자 함수를 문자열에 사용하기
* inpunct() : 기호인지 확인하는 함수
* strchr(const char* string, int c) : string에서 문자로 변환되는 c의 첫 번째 표시에 대한 포인터를 리턴

## 명령줄 인수
* C나 C++ 언어로 만들어진 실행파일을 다른 스크립팅 언어로 반복해서 실행시킬 경우 많이 사용
* int main(int argc, char* argv)
  * argc : 인수 개수
  * argv[0] : 실행파일의 경로

## 문자열을 숫자로 바꾸는 방법들
* string to integer, double, long
  * atoi(), atof(), atol()
* string to long, unsigned long, double
  * strtol(), strtoul(), strtod()
    * strtod() - converts base 10 only
* numbers to strings
  * use sprintf() instead of _itoa(), _ftoa()
    * _itoa(), _ftoa() : 표준이 아니라 권장하지 않음
    * sprintf(temp, "%x", 10) : 10을 16진수로 바꿔서 temp에 저장
