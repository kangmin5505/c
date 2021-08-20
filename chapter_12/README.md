# Storage Classes, Linkage and Memory Management

## 메모리 레이아웃(Memory Layout) 훑어보기
![image](https://user-images.githubusercontent.com/74703501/130074987-84b59fa7-ee62-4d2c-9035-cbd002d3e1e2.png)     
[출처](https://www.inflearn.com/course/following-c)   
![image](https://user-images.githubusercontent.com/74703501/130075010-68809077-78c2-4a05-9dd1-2af4475295f9.png)   
[출처](https://www.inflearn.com/course/following-c)   
![image](https://user-images.githubusercontent.com/74703501/130075034-502c30c7-56df-41c6-909b-e0fdb6724497.png)   
[출처](https://www.inflearn.com/course/following-c)   
![image](https://user-images.githubusercontent.com/74703501/130075062-7a4976cf-b7ee-43af-9768-35dcdec1eebe.png)   
[출처](https://www.inflearn.com/course/following-c)   
![image](https://user-images.githubusercontent.com/74703501/130075084-925b6895-d922-4be5-96a1-593e9074421a.png)   
[출처](https://www.inflearn.com/course/following-c)   
![image](https://user-images.githubusercontent.com/74703501/130075107-59d5b129-ba80-4bdc-91f9-4da77f240206.png)   
[출처](https://www.inflearn.com/course/following-c)   
* 함수의 주소(자체)는 프로그램 코드 메모리에 올라감
* Stack : 메모리 사용 크기를 미리 아는 경우 사용
* Heap : 메모리 사용 크기를 모르는 경우 사용
  * 동적으로 할당 받는 과정(운영체제를 통해) 때문에 속도가 느림
  * 사용 후 반납 꼭 필요

## 객체와 식별자(Object and Identifier, L-value와 R-value
* Object 
  * An object is simply a block of memory that can store a value(C language)
  * Object has more developed meaning in C++ and Object Oriented Programming(OPP)
  * Object have storage duration
* Identifiers
  * Names for variables, functions, macros, and otehr entities
  * Identifiers have scope
* L-value
  * L-value is an expression 'referring' to an object
  * left-side of an assignment
* R-value
  * right-side, variable, constant, expressions
* Variables and functions have one of the following linkages
  * external linkage
  * internal linkage
  * no linkage

## 변수의 영역(Scope)과 연결 상태(Linkage), 객체의 지속 기간(Duration)
* Varialbe scopes(visibility)
  * block
  * function
  * function prototype
  * file
* 전역(global) / 정적(static) 변수
  * global variable : 다른 파일에서 extern으로 사용 가능(file scope with external linkage)
  * static : 다른 파일에서 extern 불가(범위 고정)(file scope with internal linkage)
  * 선언 후 초기화를 안 하면 컴파일러가 자동으로 0을 넣어줌
  * BSS(Block Started by Symbol) Segment에 위치
* Storage duration
  * static storage duration
  * automatic storage duration : 지역 변수
  * allocated storage duration
  * thread storage duration
* 예외
  * VLA(Variable-Length Array)는 길이를 지정해줘야 하기 때문에 프로토타입에서 식별자 생략 불가(ex arr[n])
  * goto문은 선언 전에 사용 가능

## 저장 공간의 다섯 가지 분류(Five storage classes)
![image](https://user-images.githubusercontent.com/74703501/130087528-79a9916d-d566-468b-a24a-5d7b0223ac64.png)
[출처](https://www.inflearn.com/course/following-c)
* translation unit == file
* 크게 static과 not static으로 나눔
* BSS(Block Started by Symbol)
* 자동 변수(Automatic variables)
  * Automatic storage duration, block scope, no linkage
  * Any variable declared in a block or function header
  * 메모리 공간을 효율적으로 관리
  * 프로그램이 사용하는 총 메모리 공간을 줄여줌
  * declaration : auto(안 붙여도 자동으로 붙음), 직접 초기화 필요
    * C++에서는 auto가 다른 의미
  * stack frame : 함수 전체가 필요한 메모리, 함수마다 하나의 stack frame을 가짐
```C
int i = 1;
{
  int i = 3; // name hiding
}
```
* 레지스터 변수(Register variables)
  * cpu의 일부
  * declaration : register
  * 선언을 해도 메모리의 위치가 레지스터로 올라갈지 스택에 있을지 정확하게 모름
    * 그래도 레지스터로 올라갈 것을 기대하기 때문에 '&'(주소) 사용 불가
      * 메인 메모리에 저장되는 것이 아니기 때문에
  * 속도 향상을 위해 register 대신 병렬처리, GPU, 분산처리 등 다른 방법을 많이 사용함
* Static with no linkage
  * static is initialized only once
  * 주의(함수 parameter에 static 선언)
    * 함수가 호출될 때 function parameter도 스택프레임 안에 올라가는데 parameter에 static을 선언하면 static variable이 있어야 하는 공간(BSS)과 다르기 때문에 에러 발생
* Static with external linkage
  * declaration 시 컴파일러가 값을 0으로 초기화
  * defining declaration vs referencing declaration(extern 사용 (권장))
  * 두 개 이상의 파일에서 같이 초기화하면 에러 발생(extern이 없는 곳에서 초기화 권장)
* Static with internal linkage
  * static을 사용하면 linkage 불가능
  * 파일 내부에서만 사용 가능
  
## 함수의 저장 공간 분류
* Functions external (by default) or static
* A function declaration(prototyping) is assumed to be extern
* 함수 이름 앞에 static을 붙이면 다른 파일에서 사용 불가
  * 다른 파일에서 사용할 필요 없는 함수를 linkage 되지 않게 할 수 있음

## 난수 생성기 모듈 만들기 예제
* #pragma once : 컴파일러가 한 번만 컴파일 하도록 명령하는 것

## 메모리 동적 할당(Dynamic Storage Allocation)
* 필요한 메모리의 크기를 미리 알 수 없을 경우 사용
  * stack은 크기가 제한되어 있음
  * heap은 가상주소공간을 사용해서 컴퓨터의 메모리를 충분히 사용할 수 있도록 제공
* malloc(할당) / free(반납)
  * malloc() returns a void type pointer(void* : generic pointer)
  * free() deallocates the memory
   * no action occurs when ptr is NULL
     * free() 이후 포인터에 NULL 대입(권장)
   * 메모리를 할당 받아왔을 때 따로 초기화 필요
  * 할당 받을 메모리가 없을 경우에는 NULL 반환
```C
 int n = 0; 
 // n from files, internet, scanf, etc
 char* arr = (char*)malloc(sizeof(char) * n);
 
 // 메모리 할당이 안 된 경우 NULL 반환
 if (arr == NULL)
 {
  puts("Memory allocation failed.");
  
  /*
   exit(EXIT_FAILURE) is similar to return 1 IN main().
   exit(EXIT_SUCCESS) is similar to return 0 IN main().
  */
  exit(EXIT_FAILURE);
 }
 // ...
 
 free(arr);
 // free() 이후 포인터에 NULL 대입(권장) => 포인터의 주소는 변하지 않기 때문에
 arr = NULL;
 
 /*
   Comparision to VLA
   
   VLA
   - not supported by VS compilers.
   - automatic duration, cannot be resized
   - limited by stack size (when compiler places VLA in stack segment)
 */
 
 return 0;
```
  
## 메모리 누수(Leak)와 free()의 중요성
* 메모리 누수를 꼭 체크해야함
 * 메모리 누수가 일어날 경우, 컴퓨터가 가지고 있는 메모리 한계에 도달했을 때 문제 발생

## 동적 할당 메모리를 배열처럼 사용하기
* stack : 크기가 제한 / 메모리 자동 반환
* heap : 가상주소공간을 사용하여 크기가 엄청 큼 / 메모리 수동 반환
* 1차원 배열을 2, 3차원 배열로 사용
```C
#include <stdio.h>
#include <stdlib.h> // malloc()

int main()
{
// Using 1D arrays as 2D arrays
 int row = 3, col = 2;
 int* ptr = (int*)malloc(sizeof(int) * row * col);
 if (ptr == NULL) exit(1);
 
 for (int r = 0; r < row; r++)
  for (int c = 0; c < col; c++)
   ptr[c + col * r] = c + col * r;
 
 for (int r = 0; r < row; r++)
 {
  for (int c = 0; c < col; c++)
   printf("%d ", ptr[c + col * r]);
  printf("\n");
 }
 
// Using 1D arrays as 3D arrays
  int row = 3, col = 2, depth = 2;
  int* ptr = (int*)malloc(sizeof(int) * row * col * depth);
  if (ptr == NULL) exit(1);

  for (int d = 0; d < depth; d++)
      for (int r = 0; r < row; r++)
          for (int c = 0; c < col; c++)
              ptr[c + col * r + (col * row) * d] = c + col * r + (col * row) * d;

  for (int d = 0; d < depth; d++)
  {
      for (int r = 0; r < row; r++)
          {
              for (int c = 0; c < col; c++)
                  printf("%d ", ptr[c + col * r + (col * row) * d]);
              printf("\n");
          }
      printf("-------------\n");
  }

}

```

## calloc(), realloc()
* calloc()
  * contiguous allocation
  * 0으로 초기화를 해줌
* realloc()
  * doesn't initialize the bytes added
  * returns NULL if can't enlarge the memory block
  * If first argument is NULL, it behaves like malloc()
  * If second argument is 0, it frees the memory block
  * 기존 메모리는 복사하고, 추가된 메모리에 대해서 초기화를 해주지 않음
```C
 int n = 10;
 int* ptr = NULL;
 
 //ptr = (int*)malloc(sizeof(int) * n); // 초기화를 안 해줌
 ptr = (int*)calloc(n, sizeof(int)); // contiguous allocation
 
 n = 20;
 int* ptr2 = NULL;
 ptr2 = (int*)realloc(ptr, n * sizeof(int));
 // ptr = (int*)realloc(ptr, n * sizeof(int));
```

## 동적 할당 메모리와 저장 공간 분류
![image](https://user-images.githubusercontent.com/74703501/130170489-8a53503b-b779-4b0f-9c43-38e8a26a427d.png)   
[출처](https://www.inflearn.com/course/following-c)   

## 자료형 한정자들(Type qualifiers) const, volatile, restrict
* const를 쓰려면 초기화 필수
  * const 선언 이후에 값 변경이 안 되는데, 처음에 초기화를 안 해주면 값을 생성할 수가 없음
  * ideompotent : 중복 const 가능(ex. const const const int n = 6;)
```C
 // 값 변경 불가
 const float* ptr = &fl;
 // 주소 변경 불가
 float* const ptr = &fl;
 // ideompotent
 typedef const int zip;
 const zip q = 8; // const const int zip
```
* volatile
  * Do not optimize (ex. hardward clock)
* restrict(\__restrict in VS)
  * Sole initial means of accessing a data object
    * 최적화를 도와줌
  * Compiler can't check this restriction

## 멀티 쓰레딩(Multi-Threading)
* 멀티 코어를 사용하여 병행처리
* Racing condition : 전역 변수 경쟁
 * \_Atomic : racing condition을 막아줌 / 대신 느림
