# 반복문

## 의사코드(Pseudocode)
* 의사소통을 위한 도구로써, 논리 자체에 집중하기 위해 언어의 문법을 신경쓰지 않고, 인간의 언어로 표현하는 것

## 관계 연산자(Relational operators)
* <  is less than
* <= is less than or equal to
* \>  is greater than
* \>= is greater than or equal to
* == is equal to
* != is not equal to   
   
* 실수 비교시 자주 사용하는 fabs() : 절댓값을 return
```C
#include <stdio.h>
#include <math.h>

int main()
{
    const double PI = 3.1415926535897932;
    double guess = 0.0;
    
    printf("Input PI : ");
    scanf("%lf", &guess);
    while (fabs(PI - guess) < 0.01)
    {
      printf("Fool! Try again.\n");
      scanf("%lf", &guess);
    }
    
    printf("Good!");
    
    return 0;
}
```

## 사실과 거짓(True and False)
* 0은 false 나머지 숫자는 true로 처리

## _Bool 자료형
* 기존에 작성된 코드와의 호환성을 위해 자료형을 _Bool로 지음
* 내부적으로는 정수형으로 처리
* Boolean을 위한 format specifier가 없어서 %d를 사용
```C
  // 99년도에 정립된 표준
  _Bool boolean_true = 1;
  _Bool boolean_false = 0;
  
  // 현재 사용 중인 방법(#include <stdbool.h>)
  bool boolean_true = 1;
  bool boolean_false = 0;
```

## 관계 연산자와 우선 순위
![image](https://user-images.githubusercontent.com/74703501/129381618-c42f3df1-6582-403a-85e4-ece698031740.png)   
[출처](https://marinelifeirony.tistory.com/12)

## for 루프 소개
* while : Indefinite loop
* for : Counting loop
  * for(initialize; test; update)
  {
    statement
  }

## 다양한 대입 연산자들
* +=, -=, *=, /=, %=

## 콤마 연산자
* Comma is a sequence point
* x / 2 보다 x * 0.5가 계산이 더 빠름(나눗셈 보다 곱셈이 빠름)

## 탈출 조건 루프
```C
#include <stdio.h>
int main()
{
  // while문 사용
  scanf("%d", &guess);
  
  while (guess != secret_code)
  {
    printf("Enter secret code : ");
    scanf("%d", &guess);
  }
  
  // do while문 사용
  do
  {
    printf("Enter secret code : ");
    scanf("%d", &guess);
  }while (guess != secret_code)
  
}
```

## 어떤 루프를 사용할까
* 진입조건(while, for) vs 탈출조건(do while)

## 중첩된 루프들
```C
  for (i = 0; i < n; ++i)
  {
    for (j = 0; j < n; ++j)
    {
      printf("%d %d\n", i, j);
    }
  }
```

## 배열과 런타임에러
* 배열: 데이터를 쉽게 다루기 위해 사용
```C
  int my_numbers[5];
  
  my_numbers[0] = 1;
  my_numbers[1] = 2;
  my_numbers[2] = 3;
  my_numbers[3] = 4;
  my_numbers[4] = 5;
```

* compiletime error: 컴파일 도중 발생하는 에러
* runtime error: 실행 도중 발생하는 에러

## for루프를 배열과 함께 사용하기
* for문은 기능별로 쪼개는 것이 효율적
* 5개의 숫자를 입력 받아 출력하는 코드
```C
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
```

## 루프 안에서 함수의 반환값 사용하기
* Scope: global variable, local variable
```C
#include <stdio.h>

 int compute_pow(int base, int exp);

int main()
{
  // local variable
  int base, exp, i, result;
  
  while (scanf("%d %d", &base, &exp) == 2)
  {
    result = compute_pow(base, exp);
    print("Result = %d\n", result);
  }
  
  return 0;
}

int compute_pow(int base, int exp)
{
  // local variable
  int i, result;
  
  result = 1;
  for (i = 0; i < exp; ++i)
    result *= base;
    
   return result;
}
```
