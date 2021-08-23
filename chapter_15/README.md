# 비트 다루기

## 비트단위 논리 연산자(Bitwise Logical Operators)
* Regular Logical Operators : &&, ||, !
* Bitwise Logical Operators
  * Bitwise NOT ~(Tilde)
  * Bitwise AND &(Ampersand)
  * Bitwise OR |(Vetical bar)
  * Bitwise EXCLUSIVE OR ^(Caret)
* 비트단위 논리 연산자 사용하는 이유
  * 정보의 최소 단위는 1 bit인데 자료형의 최소 단위는 1 byte라서 메모리 낭비가 발생하기 때문에 비트단위 논리 연산자를 사용
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
* Decimal to binary
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
 
## 비트단위 논리 연산자 확인해보기

## 2의 보수 표현법 확인해보기

## 비트단위 쉬프트 연산자

## 비트단위 연산자의 다양한 사용법

## RGBA 색상 비트 마스크 연습문제

## 구조체 안의 비트 필드

## 비트필드의 사용방법

## 비트필드의 패딩

## 메모리 줄맞춤 alignof, alignas
