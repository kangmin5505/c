# 데이터와 C언어

## 데이터와 자료형
* 메모리(자원)를 효율적으로 사용하기 위해 나뉘어져 있음
* 문자도 정수에 포함   
![image](https://user-images.githubusercontent.com/74703501/128963827-ae06044c-0fd9-4f99-a853-d75f0adac55b.png)
[출처](https://swpfun.tistory.com/572)

## Variable and Constant
```C
  const int angle = 1004;
  // const : qualifier
  // int : data type
  // symbolic constant
  // literal constant
```

## scanf()함수의 기본적인 사용법
```C
  int i = 0;
  
  scanf("%d", &i); // 중요! &(ampersand)를 통해 i의 주소를 넘겨줌
```

## Printf format specifier
|Format Specifier|Type|
|:------------------------------|:------------------------------|
|%c|	Character|
|%d|	Signed integer|
|%e or %E|	Scientific notation of floats|
|%f|	Float values|
|%g or %G|	Similar as %e or %E|
|%hi|	Signed integer (short)|
|%hu|	Unsigned Integer (short)|
|%i|	Unsigned integer|
|%l or %ld or %li	|Long|
|%lf|	Double|
|%Lf|	Long double|
|%lu|	Unsigned int or unsigned long|
|%lli or %lld	|Long long|
|%llu|	Unsigned long long|
|%o|	Octal representation|
|%p|	Pointer|
|%s|	String|
|%u|	Unsigned int|
|%x or %X	|Hexadecimal representation|
|%n|	Prints nothing|
|%%|	Prints % character|

[출처](https://www.tutorialspoint.com/format-specifiers-in-c)

## Integers and Real-numbers
* floating point 표현법 사용
* Sign, Exponent, Fraction
  * Sign : 부호를 의미
  * Exponent : 지수 부분
  * Fraction : 분수 부분
![image](https://user-images.githubusercontent.com/74703501/128965514-64ff30e8-845f-4ed0-afd9-a1e3d2ff3010.png)   
[출처](https://bravenamme.github.io/2020/08/10/cpu-bit/)

## 정수의 overflow와 underflow
![image](https://user-images.githubusercontent.com/74703501/128965838-61a6bd26-2bc5-4adb-8010-0c7c96cafbab.png)   
[출처](https://dojang.io/mod/page/view.php?id=32)

## 2진수와 8진수와 16진수
* 2진수(Binary) : 숫자 앞에 0b를 표기
* 8진수(Octal) : 숫자 앞에 0을 표기하며, 출력시 format specifier로 %o를 사용
* 16진수(Hexadecimal) : 숫자 앞에 0x를 표기하며, 출력시 format specifier로 %x를 사용

## Fixed-width-integers
```C
#include <stdio.h>
#include <stdint.h>    // 크기별로 정수 자료형이 정의된 헤더 파일

int main()
{
    int8_t num1 = -128;                    // 8비트(1바이트) 크기의 부호 있는 정수형 변수 선언
    int16_t num2 = 32767;                  // 16비트(2바이트) 크기의 부호 있는 정수형 변수 선언 
    int32_t num3 = 2147483647;             // 32비트(4바이트) 크기의 부호 있는 정수형 변수 선언
    int64_t num4 = 9223372036854775807;    // 64비트(8바이트) 크기의 부호 있는 정수형 변수 선언

    // int8_t, int16_t, int32_t는 %d로 출력하고 int64_t는 %lld로 출력
    printf("%d %d %d %lld\n", num1, num2, num3, num4); // -128 32767 2147483647 9223372036854775807

    uint8_t num5 = 255;                      // 8비트(1바이트) 크기의 부호 없는 정수형 변수 선언
    uint16_t num6 = 65535;                   // 16비트(2바이트) 크기의 부호 없는 정수형 변수 선언
    uint32_t num7 = 4294967295;              // 32비트(4바이트) 크기의 부호 없는 정수형 변수 선언
    uint64_t num8 = 18446744073709551615;    // 64비트(8바이트) 크기의 부호 없는 정수형 변수 선언

    // uint8_t, uint16_t, uint32_t는 %u로 출력하고 uint64_t는 %llu로 출력
    printf("%u %u %u %llu\n", num5, num6, num7, num8); // 255 65535 4294967295 18446744073709551615

    return 0;
}
```   
[출처](https://dojang.io/mod/page/view.php?id=35)

## Charater
* 문자도 2진수로 표기
* ASCII(American Standard Code for Information Interchange)
![image](https://user-images.githubusercontent.com/74703501/128966825-87a424f6-4bcd-4edf-9dd3-4b965c1d92c1.png)
[출처](https://www.asciitable.com/)

## Floating-point types
* Scientific Notations 
![image](https://user-images.githubusercontent.com/74703501/128967287-02f5da84-ef77-4f05-b9b9-c77666ee4081.png)
[출처](https://scientificnotation.org/)

* 4byte(32bit)부동소수점수
![image](https://user-images.githubusercontent.com/74703501/128967483-9861451e-6adf-4907-b6d2-5f773c5ecd62.png)
[출처](https://www.inflearn.com/course/following-c/)
![image](https://user-images.githubusercontent.com/74703501/128967574-d9ea5945-8cd4-4fd0-a813-52de87b8372d.png)
[출처](https://www.inflearn.com/course/following-c/)
## Limit of Floating-point types
* round-off errors
* overflow
* underflow

## Boolean types
* 내부는 정수형
* 크기는 1byte(메모리의 주소를 배정 받을 수 있는 가장 작은 단위가 1byte라서)
* 컴퓨터는 false가 아닌 것은 모두 true로 처리

