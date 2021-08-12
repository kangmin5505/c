# 문자열과 형식 맞춘 입출력

## 문자열 입출력하기
* 배열에서 배열의 이름은 배열 맨 앞 주소의 메모리를 대표하는 메모리 주소를 의미
```C
  char fruit_name[40]; // stores only one character.
  
  scanf("%s", fruit_name); // be careful with &
  
  printf("You like %s!\n", fruit_name);
```

## sizeof 연산자
* 자료형의 크기를 구함
```C
  int a;
  int b[20];
  
  printf("Size of int data type: %d\n", sizeof(int)); // 4
  printf("Size of char data type: %d\n", sizeof(char)); // 1
  printf("Size of float data type: %d\n", sizeof(float)); // 4
  printf("Size of double data type: %d\n", sizeof(double)); // 8
  printf("Size of int data type: %d\n", sizeof(a)); // 4
  printf("Size of int array: %d\n", sizeof(b)); // 80
```

## 문자열이 메모리에 저장되는 구조
* 문자열은 문자들로 구성
* 문자의 배열 마지막에는 '/0'이 들어가고 문자열의 마지막을 표현
* 중간에 '\0'이 있어도 이후 문자열도 메모리에는 저장이 되지만, 중간에 있는 '\0' 이후로는 출력을 안 함.
![image](https://user-images.githubusercontent.com/74703501/129128568-07f5c7c7-94f6-49cf-b2e8-fe31672529dd.png)   
[출처](https://www.inflearn.com/course/following-c)


## strlen 함수
* 처음 만나는 '\0' 전까지의 길이 반환

## 기호적 상수와 전처리기
* 기호적 상수(Symbolic constants)
  * 반복되는 상수를 치환해서 유지보수를 원활하게 함
  * 컴파일러가 읽을 때는 symbolic constants를 literal constants로 교체해서 읽음   
* 예제
```C
  #define PI 3.141592f // symbolic constants로 변환
  
  float const PI = 3.141592f // 상수로 선언
```

## printf()함수의 변환 지정자와 변환 지정자의 수식어들
* printf()의 return 값은 글자의 수
* 형식 지정자 : %[flags][width][.precision][length]specifier
* flags   
![image](https://user-images.githubusercontent.com/74703501/129129346-132c3daa-5f18-4bc7-b6eb-4e2347b50139.png)   
[출처](https://www.cplusplus.com/reference/cstdio/printf/)
* width   
![image](https://user-images.githubusercontent.com/74703501/129129377-03496fdd-915f-455f-a4ae-78821c084c66.png)   
[출처](https://www.cplusplus.com/reference/cstdio/printf/)
* .precision   
![image](https://user-images.githubusercontent.com/74703501/129129419-db6d68e7-88eb-416a-977f-133f0f52947a.png)   
[출처](https://www.cplusplus.com/reference/cstdio/printf/)
* length   
![image](https://user-images.githubusercontent.com/74703501/129129460-f4c11060-20d2-4b73-9b17-6b9cf44b49ce.png)   
[출처](https://www.cplusplus.com/reference/cstdio/printf/)
* specifier   
![image](https://user-images.githubusercontent.com/74703501/129129206-c6ae2eeb-eec5-4231-a780-bbfa97251dd9.png)   
[출처](https://www.cplusplus.com/reference/cstdio/printf/)


## printf함수가 인자들을 해석하는 법
* float(4 bytes)는 double(8 bytes)로 변환   
![image](https://user-images.githubusercontent.com/74703501/129130050-ffd3ebf5-7d75-4f95-a5bf-c9b47967e30c.png)   
[출처](https://www.inflearn.com/course/following-c)

## scanf함수의 사용법
* return 값은 입력의 개수
* 입력 개수 제한 가능   
![image](https://user-images.githubusercontent.com/74703501/129130184-5dc34d2e-9b95-460b-9de4-b00cb6e164a9.png)   
[출처](https://edu.goorm.io/learn/lecture/42/%ED%94%84%EB%A6%AC%EB%A0%89%EC%B6%9C%ED%8C%90%EC%82%AC-c%EC%96%B8%EC%96%B4%EB%B3%B8%EC%83%89/lesson/1926/2-4-%ED%82%A4%EB%B3%B4%EB%93%9C%EB%A1%9C%EB%B6%80%ED%84%B0-%EB%8D%B0%EC%9D%B4%ED%84%B0-%EC%9E%85%EB%A0%A5%EB%B0%9B%EA%B8%B0-scanf-%ED%95%A8%EC%88%98)

