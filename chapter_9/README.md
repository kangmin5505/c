# 함수

## 함수가 필요할 때
* 불필요한 반복 제거
* 가독성 향상
* 유지보수 수월
* 작성법 : 하나의 함수는 하나의 기능만 수행하도록 작성

## 함수의 프로토타입(Prototype)
* 구조 : 반환형태 + 함수이름 ( 매개변수(매개변수 자료형 + 매개변수 이름(생략가능)) );
  * 하지만 매개변수 이름을 적어주는 것이 좋음
  * 중요한 것이 반환자료형, 매개변수 자료형, 함수이름
* 예시
```C
void print_center_str(char str[]);
void print_mutiple_chars(char c, int n_stars, bool print_newline);
```

## 함수의 자료형과 반환값
* 정수형 반환 자료형은 생략 가능
  * 하지만 생략하지 않는 것을 권장
* void : 자료형 또는 반환값이 없을 경우
  
## 변수의 영역과 지역 변수(Scope and Local variable)
![image](https://user-images.githubusercontent.com/74703501/129479390-ddf92967-51ae-4e43-b4cf-5e0407a2683c.png)   
[출처](https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=qkrghdud0&logNo=220859390675)
* 지역변수 auto 예약어는 생략 가능

## 지역 변수와 스택(Local variable and Stack)
![image](https://user-images.githubusercontent.com/74703501/129479475-d4e696e0-4374-426c-9e24-e1e91501da7f.png)   
[출처](http://ehpub.co.kr/wp-content/uploads/2016/06/2-29.png)

## 재귀 호출과 스택(Recursive and Stack)
![image](https://user-images.githubusercontent.com/74703501/129479512-1c2eae40-c5ba-4ea5-adba-33a818c8a4ce.png)   
[출처](https://dojang.io/mod/page/view.php?id=584)
* 재귀 호출은 무조건 종료 조건이 필요
* 스택에 쌓일 때 변수 뿐만 아니라, 함수의 정보까지 스택에 저장 됨

## 피보나치 예제와 재귀 호출의 장단점
```C
int fibonacci(int number)
{
  if (number > 2)
    return fibonacci(number - 1) + fibonacci(number - 2);
  else
    return 1;
}
```
* 장점 : 코드가 간결해짐
* 단점 : 반복적인 계산이 많음

## 헤더 파일 만드는 방법
* header.h
  * #pragma once : 현재 소스 파일이 단일 컴파일에 한 번만 포함되도록 설계된 비표준이지만 널리 지원되는 전처리기 지시문
  * 주로 header.h에는 prototyping만 함
* header.c
  * 주로 header.c에는 function description을 함

## 포인터의 작동 원리
![image](https://user-images.githubusercontent.com/74703501/129481926-c1445b23-6ffe-40b0-9adb-e163c9156c43.png)   
[출처](https://www.inflearn.com/course/following-c)   
![image](https://user-images.githubusercontent.com/74703501/129481958-b9d7d356-0f16-4c47-84fc-8e1279af03a8.png)   
[출처](https://www.inflearn.com/course/following-c)   
![image](https://user-images.githubusercontent.com/74703501/129481989-ecb6c7b6-9fbf-4df5-8e19-33a3d76ce838.png)   
[출처](https://www.inflearn.com/course/following-c)   
![image](https://user-images.githubusercontent.com/74703501/129482045-793eda99-b715-4762-9896-392c92bcdeae.png)   
[출처](https://www.inflearn.com/course/following-c)   
![image](https://user-images.githubusercontent.com/74703501/129482082-cead4ff0-4fd0-45f6-a638-87f04e96a2f5.png)   
[출처](https://www.inflearn.com/course/following-c)   

## 포인터와 코딩 스타일
* int \*a_ptr vs int\* a_ptr

## NULL 포인터와 런타임 에러
```C
#include <stdio.h>

int main()
{
  // error 발생
  // 1234주소로 실제로 가지만 실제로 할당받은 메모리가 아니라서 운영체제가 제한시킴
  int *ptr = 1234;
  
  // safer_ptr이 선언만 하고 뒤에서 호출하면 error 발생
  // 그래서 NULL값을 넣는 것이 일반적
  int* safer_ptr = NULL;
  
  int a = 123;
  
  if (a % 2 == 0)
    safer_ptr = &a;
  
  if (safer_ptr != NULL)
    printf("%p\n", safer_ptr);
}

```
## 포인터 변수의 크기
* 포인터 변수의 크기는 일반적으로 4 byte로 알려져있으나, 컴파일러의 bit에 따라서 포인트 변수의 크기가 달라짐

## 포인터형 매개변수
* call by value
```C
void swap(int a, int b); // 값에 의한 호출(call by value)

int main()
{
  int a = 123;
  int b = 456;
  
  swap(a, b); // 값을 넘겨줌
  
  // 이하 생략
}
```
* call by pointer
```C
void swap(int* u, int* v); // 주소(포인터)에 의한 호출(call by pointer)

int main()
{
  int a = 123;
  int b = 456;
  
  swap(&a, &b); // 주소를 넘겨줌
  
  // 이하 생략
}
```

