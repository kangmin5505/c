# 전처리기와 라이브러리

## 전처리기가 해주는 일들
![image](https://user-images.githubusercontent.com/74703501/130544028-5f8e8972-7543-416d-a409-c64a26000356.png)   
[출처](https://www.inflearn.com/course/following-c)

## 전처리를 준비하는 번역 단계
* Program written in C
  1. Translating
  2. Preprocessing
  3. Compiling
  4. Linking
  5. Executable 
* International characters
* Trigraph Sequences
  * Some keyboards don't provide all the symbols used in C.
  * Three-character sequences
  * /Zc: trigraphs(옵션설정)
  
  |Trigraph|Replacement|
  |---|---|
  |??=|#|
  |??/|\\|
  |??'|^|
  |??(|[|
  |??)|]|
  |??!|\||
  |??<|{|
  |??>|}|
  |??-|~|
* Digraphs
  * Two-character sequences
  
  |Digraph|Equivalent|
  |---|---|
  |<:|[|
  |:>|]|
  |<%|{|
  |%>|}|
  |%:|#|
* Two physical lines vs One logical line
  * '\' 사용
```C
  printf("This is a very very very very \
    very very very long long long long line.\n");
```
* Tokens
  * Groups separated from each other by spaces, tabs, or line breaks \
    Whitespace characters -> a single space
## #define 매크로
* Preprocessor directive
  * Preprocessor directives begins with # symbol at the beginning of a line.
* Macro
  * An instruction that represents a sequence of instructions in abbreviated form.
  ```C
          #define            SAY_HELLO      printf("Hello, World!");
  preprocessor directive    Macro(name)    body(or replacement list)
  ```
* Object-like macros vs Function-like macros
```C
#define ONE 1
#define SQUARE(X) X*X
```
* Redefining Constants
  ```C
  #define SIX 2*3
  #define SIX 2*3
  //#undef SIX // 기존에 선언한 것을 취소하고 재선언(아래 에러를 해결)
  #define SIX 2*3 // Warning (다른 값으로 재 선언하면 에러)
  ```
```C
#define MESSAGE "kangmin"

printf("%s\n", MESSAGE); // replaced
printf("MESSAGE\n"); //  Not replaced
```

## 함수 같은 매크로
* Function-like macros
```C
#define ADD(X,Y) ((X)+(Y)) // X and Y : macro arguments
#define ADD1(X,Y) X+Y // 괄호를 넣지 않았을 경우 의도한 대로 작동하지 않을 수 있음
// 2 * ADD1(2, 2) => 2 * 2 + 2 // 덧셈을 먼저 수행하지 않고, 곱셈을 먼저 실행
```
* stringizing operator #
  * converts macro parameters to string literals
  ```C
  #define SQUARE(X) (X)*(X)
  #define PRINT_SQR1(x) printf("The square of %d is %d.\n", x, SQUARE(x))
  // # 사용
  #define PRINT_SQR2(x) printf("The square of " #x " is %d.\n", SQUARE(x))
  ```
* ## operator combines two tokens into a single token
```C
#define XNAME(x) x ## n

int XNAME(1) = 1; // int x1 = 1;
```
* Macro or Function ?
  * no space in the macro name
  * Use paretheses
  * Use capital letters for macro function names
  * Speed up??
  * 요즘은 기본 내장 함수를 사용하는 추세임

## 가변 인수 매크로
* Variadic Macros accept a variable number of arguments
```C
#define PRINT(X, ...) printf("Message " #X ": __VA_ARGS__)
// ...: ellipses
// __VA_ARGS__: one of the predefined macros

/*
prinf(...)
stdvar.h Variadic arguments
*/
```

## #include와 헤더 파일
* 표준 라이브러리나 외부 라이브러리는 <>를 사용
* 개인이 만든 라이브러리는 "" 안에 경로를 적어서 사용
* [헤더가드(header guard)가 없는 경우의 중복 include 예시]
  * A.h를 B.h가 include하고 main.c에서 A.h와 B.h를 모두 include한다면 \
    main.c에서는 A.h가 B.h를 통해서 한번 더 include되는 형태가 됨
  * 헤더가드는 인클루드 가드(include guard)라고 불림

## 조건에 따라 다르게 컴파일하기
* #define, #undef, #if, #ifdef, #ifndef, #else, #elif, #endif
* empty macro
  * 매크로 이름만 정의되어 있는 것
  ```C
  #define REPORT
  ```
* \_WIN64, \_WIN32, \_\_linux__ (미리 매크로 정의되어 있음)

## 미리 정의된 매크로들, #line, #error
```C
__FILE__
__DATE__
__TIME__
__LINE__
__func__
__STDC__ : comforms to the C standard
__STDC_HOSTED__ : hosted vs freestanding implementation
__STDC_VERSION__
```
* #line : 현재 줄 번호를 변경
* #error : 에러를 발생시켜서 컴파일을 못하게 만듦

## #pragma 지시자
* pragma token(ex: once, pack, warning(disable:, error:))

## \_Generic 표현식
* Generic selection expression
  * Generic programming : code is not specific to a particular type
  * \_Generic
```C
#define MYTYPE(X) _Generic((X), \
  int: "int", \
  float: "float", \
  double: "double", \
  long: "long", \
  int*: "int*" \
  default: "other", 
)
```

## inline 함수
* 작은 함수가 반복적으로 실행될 때, 속도를 올리기 위해 사용
* Function call has overhead
  * set up the call, pass arguments, jump to the function code, and return.
* Inline function specifier
  * Suggests inline replacements
* Inline functions shold be short
* A function with internal linkage can be made inline
* You can't take its address // 메모리에 올라가지 않음
```C
inline static int foo()
{
  return 5;
}

int main()
{
  int ret;
  
  ret = foo();
}
```

## 라이브러리
* 사용자가 만든 라이브러리를 내장 라이브러리로 설정할 수 있음(debug / release 모드에 따라 설정이 다름)

## 표준 수학 라이브러리
* <math.h>, <tgmath.h>
## 표준 유틸리티 라이브러리
* <stdlib.h>
  * rand(), srand(), malloc(), free(), qsort() ...
  * atexit(\func*) : 프로그램이 종료될 때, 어떤 함수가 실행될지 설정
* \_Noreturn

## assert 라이브러리
* <assert.h>
  * assert(조건) : 원하는 조건이 아니면 에러를 발생시킴( debug / release 모드에따라 다름)
  * \_Static\_assert() : compile time에서 잡아주는 assert

## memcpy()와 memmove()
* <string.h> // memcpy(), memmove()
* overlapping region
  * pointer-to-void (datatype is unknown)

## 가변 인수(Variable Arguments)
* <stdarg.h> // Variable Arguments
```C
/*
Variable Arguments
  - int printf(char const* const \_Format, ...);
  
1. Provide a function prototype using an ellipsis

void vaf1(int n, ...); // OK
int vaf2(const char * s, int k, ...); // OK
char vaf3(char c1, ..., char c2); // Not OK, ellipsis should be the last.
double vaf4(...); // Not OK, no parameter

2. Create a va_list type variable in the function definition
3. Use a macro to initialize the variable to an argument list
4. Use a macro to access the argument list
*/
```
* 예시
```C
#include <stdio.h>
#include <string.h>

double average(int, ...);
double average2(char* format_string, ...);

int main()
{
  double a, b;
  
  a = average(2, 1.1, 2.2, 3.3);
  b = average(6, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6);
}

double average(int num, ...)
{
  va_list ap;
  double sum = 0.0;
  int i;
  
  va_start(ap, num);
  for (i = 0; i < num; i++)
    sum += va_arg(ap, double);
  va_end(ap);
  
  return sum / (double)num;
}

double average2(char* format_string, ...)
{
  int num = strlen(format_string);
  
  va_list ap;
  double sum = 0.0;
  int i;
  
  va_start(ap, format_string);
  for (i = 0; i <num; i++)
    sum += va_arg(ap, double);
  va_end(ap);
  
  return sum / (double)num;
}
```

