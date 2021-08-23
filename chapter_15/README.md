# 비트 다루기

## 비트단위 논리 연산자(Bitwise Logical Operators)
* 비트단위 논리 연산자 사용하는 이유
  * 정보의 최소 단위는 1 bit인데 자료형의 최소 단위는 1 byte라서 메모리 낭비가 발생하기 때문에 비트단위 논리 연산자를 사용
* Regular Logical Operators : &&, ||, !
* Bitwise Logical Operators
  * Bitwise NOT ~(Tilde)
  * Bitwise AND &(Ampersand)
  * Bitwise OR |(Vetical bar)
  * Bitwise EXCLUSIVE OR ^(Caret)   

![image](https://user-images.githubusercontent.com/74703501/130376058-a5ac95f3-412c-4947-bfd7-ed088b56cab2.png)   
[출처](https://www.inflearn.com/course/following-c/l)   
![image](https://user-images.githubusercontent.com/74703501/130376080-88cf0ed5-6eeb-4de9-8624-effbf8361464.png)   
[출처](https://www.inflearn.com/course/following-c/l)   
![image](https://user-images.githubusercontent.com/74703501/130376090-f68352c3-6c1e-4868-acf3-692653ef7c2a.png)   
[출처](https://www.inflearn.com/course/following-c/l)   
![image](https://user-images.githubusercontent.com/74703501/130376098-752d556f-7782-4287-8f03-c5f071295d32.png)   
[출처](https://www.inflearn.com/course/following-c/l)   
![image](https://user-images.githubusercontent.com/74703501/130376105-9e215726-2cd7-43db-991a-85ac332d0ead.png)   
[출처](https://www.inflearn.com/course/following-c/l)   

## 이진수를 십진수로 바꾸기 연습문제
```C
unsigned char to_decimal(const char bi[])
{
  const size_t bits = strlen(bi);
  unsigned char sum = 0;
  for (size_t i = 0; i < bits; i++) {
    if (bi[i] == '1')
      sum += (int)pow(2, bits - 1 - i);
    else if (bi[i] != '0') {
      printf("Wrong character : %c", bi[i]);
      exit(1);
    }
  }
  return sum;
}
```

## &를 이용해서 십진수를 이진수로 바꾸기
```C
void print_binary(const unsigned char num)
{
  printf("Decimal %3d \t== Binary ", num);
  
  const size_t bits = sizeof(num) * 8;
  for (size_t i = 0; i < bits; i++) {
    const unsigned mask = (unsigned char)pow((double)2, (double)bits - 1 - i));
    // unsigned char mask = pow(2, (bits - 1 - i));
    
    if ((num & mask) == mask)
      printf("%d", 1);
    else
      printf("%d", 0);
  }
  printf("\n")
}

// for (size_t i = bits - 1; i >= 0; i--); // size_t ERROR(size_t는 unsigned임)
// for (int i = bits - 1; i >= 0; i--); // working
```

## 2의 보수 표현법 확인해보기
* Signed Integers
  * Sign-magnitude representation
     * 00000001 is 1 and 10000001 is -1 \
       00000000 is +0, 10000000 is -0 \
       Two zeros +0, -0 from -127 to +127
  * One's complement method
    * To reverse the sign, invert each bit. \
      00000001 is 1 and 11111110 is -1. \
      11111111 is -0 \
      from -127 to +127
  * Two's complement method
    * To reverse the sign, invert each bit and add 1.
      from -128 to +127

## 비트단위 쉬프트 연산자
* Bitwise shift operators
  * Left shift
    * number << n : multiply number by 2^n
  * Right shift
    * number >> n : divide by 2^n (for non-negative numbers)
* The signed result is machine dependent
  * Visual Studio에서는 맨 앞 숫자가 0이면 0으로, 1이면 1로 채움
* 주의
```C
  // 의도한 결과가 나오지 않음
  printf("%hhd\n", -119 << 4);  // -112
  printf("%hhd\n", 137 << 4); // 144
```
* int_binary
```C
void int_binary(const int num)
{
 printf("Decimal %12d == Binary ", num);
 
 const size_t bits = sizeof(num) * CHAR_BIT; // CHAR_BIT : macro
 for (size_t i = 0; i < bits; i++) {
  const int mask = 1 << (bits - 1 - i);
  
  if ((num & mask) == mask)
   printf("%d", '1');
  else
   printf("%d", '1');
 }
 printf("\n");
}
```

## 비트단위 연산자의 다양한 사용법
* 예시(아이템)
 * ( ) & (~ ) : 아이템 제거
 * ( ) | (  ) : 아이템 장착
 * ( ) ^ (  ) : toggling
* Trim
```C
 int int_flag = 0xffffffff;
 int_flag &= 0xff;
 // Trim by 11111111
```

## RGBA 색상 비트 마스크 연습문제
```C
#include <stdio.h>

#define BYTE_MASK 0xff

int main()
{
 unsigned int rgba_color = 0x66CDAAFF;
 
 unsigned char red, green, blue, alpha;
 
 alpha = rgba_color & BYTE_MASK;
 blue = rgba_color >> 8 & BYTE_MASK;
 green = rgba_color >> 16 & BYTE_MASK;
 red = rgba_color >> 24 & BYTE_MASK;
}
```
## 구조체 안의 비트 필드
* 비트필드는 scanf가 안 됨
  * 비트필드는 비트 단위로 데이터를 다루기 때문에, 바이트 단위로 다루는 메모리처럼 다룰 수 없다
* Bits-field
  * 비트가 나열되어 있는 형태
```C
struct
{
 // 비트 필드의 값을 어떤 정수 자료형으로 해석할지(주로 signed vs unsigned 차이)
 // 사용할 비트 개수(주의: 바이트 아님)
 bool has_sword : 1;
 bool has_shield : 1;
 bool has_potion : 1;
 bool has_guntlet : 1;
 bool has_hammer : 1;
 bool has_key : 1;
 bool has_ring : 1;
 bool has_amulet : 1;
} items_flag; // items_flag가 차지하는 메모리 크기는 8 비트 (1 바이트)

items_flag.has_sword = 1; 
```

## 메모리 줄맞춤 alignof, alignas
* alignof(type) : 지정된 형식의 맞춤(바이트)을 형식의 값으로 size_t 반환
* alignas(type) : alignas 또는 \_Alignas 를 사용하여 변수 또는 사용자 정의 형식에 대한 사용자 지정 맞춤을 지정. 구조체, 공용 구조체, 열거형 또는 변수에 적용
