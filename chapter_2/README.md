# C언어를 소개합니다

## C프로그램 훑어보기
* 전처리기(Preprocessor Instruction)
  * 컴파일 하기 직전에 실행되는 별도의 프로그램

```C
#include <stdio.h>

int main(void)
{
  // variable declaration
  int a;
  int b;
  int c;
  
  // assignment
  a = 1;
  b = 2;
  
  // operation
  c = a + b;
  
  // call or invoke
  printf("Result is %i", c);
  
  // value return
  return 0;
}
```

## 변수가 편리한 이유
* 주소를 거쳐가는 것을 없애줌

## 자료형이 필요한 이유
* 메모리 공간을 효율적으로 사용하기 위해서

## 변수를 선언하는 방법
```C
int main(void)
{
  // 메모리에 int를 담을 공간 확보
  // x라는 변수로 접근 가능
  int x;
  
  // 변수 x가 가리키는 공간에 값을 할당
  a = 1;

  return 0;
}
```
* 변수명 짓는 규칙
  * 변수의 이름은 영문자(대소문자), 숫자, 언더스코어(_)로만 구성
  * 변수의 이름은 숫자로 시작될 수 없음
  * 변수의 이름 사이에는 공백을 포함할 수 없음
  * 변수의 이름으로 C언어에서 미리 정의된 키워드와 예약어는 사용할 수 없음
  
## printf 함수의 기본적인 사용법
* printf : print formatted
```C
#include <stdio.h>

int main(void)
{
  // 변수 선언과 동시에 값 할당
  int x = 1;
  int y = 2;
  
  int z = x + y;
  
  printf("%i + %i = %i", x, y, z);
  
  return 0;
}
```
* escape sequence   
![image](https://user-images.githubusercontent.com/74703501/128684356-5f36f69c-b9d2-4706-88b7-556101ac10b3.png)
[출처](https://kimo87.tistory.com/m/9)

## 주석
* // : 한 줄 주석
* /**/ : 문장 주석
## 함수 만들기
```C
#include <stdio.h>

// Prototyping / Function declaration
void say_hello(void);

int main(void)
{
  say_hello();
  
  return 0;
}

// Function definition
void say_hello(void)
{
  printf("Hello");
}
```

## Debugger 사용법
* error는 syntax errors와 semantic error로 구성
  * syntax error : 문법 오류 => IDE나 컴파일러가 잡아줌
  * semantic error : 의미적 오류 => Debugger를 활용하여 해결
