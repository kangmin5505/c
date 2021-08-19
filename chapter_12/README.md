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
* BSS(Block Started by Symbol
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

## 메모리 동적 할당(Dynamic Storage Allocation)

## 메모리 누수(Leak)와 free()의 중요성

## 동적 할당 메모리를 배열처럼 사용하기

## calloc(), realloc()

## 동적 할당 메모리와 저장 공간 분류

## 자료형 한정자들(Type qualifiers) const, volatile, restrict

## 멀티 쓰레딩(Multi-Threading)
