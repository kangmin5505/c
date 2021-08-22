# 구조체(Structures)

## 구조체가 필요한 이유
* 배열은 자료형이 같은 데이터 오브젝트들이 나열된 형태
* 구조체는 자료형이 서로 다르지만 함께 사용하면 편리한 데이터 오브젝트들 끼리 모아놓은 것
![image](https://user-images.githubusercontent.com/74703501/130322820-17ff5104-d15f-4673-a931-83ea9c7fa8ee.png)   
[출처](https://www.inflearn.com/course/following-c/)   

## 구조체의 기본적인 사용법
* 사용법
```C
#define MAX 41

// 구조체를 선언하는 단계에서는 메모리에 올라가지 않음
struct person /* Person is a tag of structure */
{
  char name[MAX]; // member
  int age;        // member
  float height;   // member
};
```
* 선언 방법
```C
  // 선언하는 순간 메모리에 올라감
  struct person genie;
  
  /* dot(.) is structure membership operator (member access operator, member operator) */
  genie.name = "Kangmin";
  genie.age = 27;
  genie.height = 184.0;  
  
  // Initialization
  
  struct person user = { "Kim Kangmin", 27, 184.0 };
  struct person user1 = { 
    "Kim Kangmin", 
    27, 
    184.0 
    };
  // 권장
  struct person user2 = {
    .name = "Kim Kangmin", 
    .age = 27, 
    .height = 184.0 
  };
  
```
* pointer to a structure variable
  * membership operator가 다름
    * arrow operator(->)
    * ex) user.age => user->age / (*user).age // . has higher precedence than *
* No tag
```C
// 여러 개를 동시에 선언 가능
struct {
  char name[40];
  int age;
  float height;
} user1, user2;
```
* typedef and structure
```C
  typedef struct person my_user;
  
  my_user p3;
  
  typedef struct {
      char name[40];
    int age;
    float height;
  } my_user;
  
  my_user p4;
```

## 구조체의 메모리 할당(Memory Allocation)
* memory padding(struct member alignment) - 컴파일에서 만들어줌
  * 메모리를 효율적으로 보내기 위해서 data를 묶어서 보냄
  * 1word 안에 딱 들어갈 수 있으면 memory padding을 안 하고, 부족하거나 많으면 memory padding을 함
* 1 word(word : data의 기본 전송 단위)
  * 4 bytes in x86
  * 8 bytes in x64

## 구조체의 배열 연습문제
* char* s_gets(char* st, int n)
```C
char* s_gets(char* st, int n)
{
  char* ret_val;
  char* find;
  
  ret_val = fgets(st, n, stdin);
  if (ret_val)
  {
    find = strchr(st, '\n');
    if (find)
    {
      *find = '\0';
    }
    else
    {
      while (getchar() != '\n')
        continue;
    }
  }
  
  return ret_val;
}
```

## 구조체를 다른 구조체의 멤버로 사용하기
* 중첩 구조체
```C
#define LEN 20

struct names {
  char given[LEN]; // first name
  char family[LEN]; // last name
};

struct reservation {
  struct name guest; // a nested structure
  struct name host; // one more nested structure
  char food[LEN];
  char place[LEN];
  
  // time
  int year;
  int month;
  int day;
  int hours;
  int minutes;
};
```
* Tip : '\\' 를 통해 newline에 이어서 code 작성 가능

## 구조체와 포인터
```C
struct my_data
{
  int a;
  char c;
  float* arr;
};

int main()
{
  struct my_data d1 = { 1234, 'A', NULL };
  d1.arr = (float*)malloc(sizeof(float * 2);
  d1.arr[0] = 1.1f;
  d1.arr[1] = 2.2f;
  
  // 구조체끼리 대입 가능
  // 구조체 안에 포인터가 있으면 대입 시 주소를 복사
  // 포인터가 없으면 값만 복사
  struct my_data d2 = d1;
}
```

## 구조체를 함수로 전달하는 방법
* 주로 포인터를 사용
  * 메모리 부담 완화(call by reference)
  
## 구조체와 함수 연습문제
* scanf로 줄 바꿈을 빼고 문자열을 받는 방법
  * scanf("%[^\n]%*c", &string)
  
## 구조체와 할당 메모리
```C
#define SLEN 81

struct namect {
  char* fname;
  char* lname;
  int letters;
};

int main()
{
  /*
    Dangerous usage
  */
  
  struct namect p = { "Kang-Min", "Kim" };
  // p.lname은 수정 불가(p.lname 프로그램코드 메모리에 올라가 있어서)
  int f1 = scanf("%[^\n]%*c", p.lname);
  
  /*
    Recommended usage
  */
  
  char buffer[SLEN] = { 0, };
  int f2 = scanf("%[^\n]%*c", buffer);
  p.fname = (char*)malloc(strlen(buffer) + 1);
  
}
```
## 복합 리터럴(Compound literals)
```C
  struct person user = { "kamgin", 27, 184.0 };
  
  // 바꾸고 싶은 변수로 초기화를 실시
  // 대입
  struct person user2 = { "kimkim", 37, 174.0 };
  user = user2;
  
  // 복합 리터럴(주소를 가지고 있음)
  user = (struct person){ "kimkim", 37, 174.0 };
```

## 신축성있는 배열 멤버(Flexible Array Members)
```C
#include <stdio.h>
#include <stdlib.h>

int main()
{
  /*
    Flexible array member
  */
  
  // flexible array member는 메모리를 차지하지 않기 때문에 sizeof(flex) = 16 bytes 이다( 4 + 4(memory padding) + 8)
  struct flex
  {
    size_t count;
    double average;
    double values[]; // flexible array member (last member!)
  }
  
  const size_t n = 3;
  
  // 배열로 사용하기 싶은 메모리만큼 추가로 동적할당 받음
  struct flex* pf = (struct flex*)malloc(sizeof(struct flex) + n * sizeof(doube));
}
```
* must be last member
* 메모리를 차지하지 않음
* 포인터 멤버 vs 배열 멤버
  * 포인터 멤버
    * 포인터 자체가 메모리를 차지함(x64 : 8 bytes, x86 : 4 bytes)
    * 포인터 동적할당을 받았기 때문에 포인터 멤버는 힙의 알 수 없는 곳의 메모리를 받아서 순차적이지 않음
  * 배열 멤버
    * 메모리가 순차적
    * Don't copy flexible members, use memcpy() instead

## 익명 구조체(anonymous structures)
```C
struct names
{
  char first[20];
  char last[20];
};

struct person
{
  int id;
  struct names name;
};

struct person2
{
  int id;
  struct { char first[20]; char last[20]; };  // anonymous structures
};

int main()
{
  // non-anonymous structures
  struct person ted = {123, {"Bill", "Gates"} };
  puts(ted.name.first);
  
  // anonymous structures
  struct person2 ted2 = {123, {"Bill", "Gates"} };
  // struct person2 ted2 = {123, "Bill", "Gates" }; // also work
  puts(ted.first);
}

```
* member access가 좀 더 수월 

## 구조체의 배열을 사용하는 함수
```C
#define SLEN 101

struct book
{
  char name[SLEN];
  char author[SLEN];
};

int main()
{
  // 구조체의 배열 선언
  struct book my_books[3];
}
```

## 구조체 파일 입출력 연습문제
* text형식 보다 binary형식으로 전송하는 게 더 빠름


## 공용체의 원리(Union)
* Union
  * store different data types in the same memory space
  * union의 메모리는 union 안의 가장 큰 자료형 사이즈가 배정
  * 같은 메모리 공간을 사용
    * 모든 member의 시작 주소가 동일
* 선언
```C
union my_union {
  int i;
  double d;
  char c;
};

int main() 
{
  union my_union uni1;
  
  /*
    Initializing unions
  */
  
  union my_union uni2 = uni1; // Copy another union
  union my_union uni3 = { 10 }; // First element(member) only
  union my_union uni4 = { .c = 'A' }; // Designated initializer
  union my_union uni5 = { .d = 1.23, .i = 100 }; // Do NOT recommend
}
```

## 공용체와 구조체를 함께 사용하기
* 문법이 복잡하진 않지만 구조가 복잡해짐
```C
struct personal_owner {
  char rrn1[7]; // Resident Registration Number
  char rrn2[8]; // ex: 830422-1185600
};

struct company_owner {
  char crn1[4]; // Company Registration Number
  char crn2[3]; // ex: 111-22-33333
  char crn3[6];
};

union data {
  struct personal_owner po;
  struct company_owner co;
};

struct car_data {
  char model[15];
  int status; /* 0 = personal, 1 = company */
  union data ownerinfo;
}
```
## 익명 공용체(Anonymous unions)
* 코드가 간결해짐
```C
struct personal_owner {
  char rrn1[7]; // Resident Registration Number
  char rrn2[8]; // ex: 830422-1185600
};

struct company_owner {
  char crn1[4]; // Company Registration Number
  char crn2[3]; // ex: 111-22-33333
  char crn3[6];
};

struct car_data {
  char model[15];
  int status; /* 0 = personal, 1 = company */
  union {
  struct personal_owner po;
  struct company_owner co;
  }
};
```

## 열거형(enumerated types)
* enumerated type
  * symbolic names to represent integer constants
  * improve readability and make it easy to maintain
  * enum-specifier
* enumerators
  * the symbolic constatns
  * enumerators are not strings
```C
              // 0,     1,      2,     3,    4,     5
enum spectrum { red, orange, yellow, green, blue, violet };
enum levels { low = 100, medium = 500, high = 2000 };
```

## 이름공간(Namespace) 공유하기
* Namespace
  * Identify parts of a program in which a name is recognized
  * You can use the same name for one variable and one tag
  * C++ : use namespace to use the same identifiers in the duplicated scopes
* Namespace pollution
  * names in different files accidentally conflicting with each other
  * 예방하기 위해 최대한 작은 scope 안에 변수를 선언

## 함수 포인터(Function pointers)의 원리
* 반환값의 type과 파라미터의 type을 같이 선언
* 함수 이름 자체가 주소
* 함수 포인터를 통해 함수 실행 가능
```C
void f1()
{
  return;
}

int f2(char i)
{
  return i + 1;
}

int main()
{
  // 함수 이름 자체가 주소
  void (*pf1)() = f1;
  // void (*pf1)() = &f1;
  
  int (*pf2)(char) = f2;
  
  // 함수 포인터를 통해 함수 실행 가능
  (*ptf1)(); // call f1 via pf1
  //pf1();
}
```
* 프로그래머는 함수의 이름을 이용해서 프로그램을 작성하지만, 컴파일러는 이름(식별자)들을 메모리에서의 주소로 번역함. 즉, 함수를 실행시킨다는 것은 메모리에서 함수의 주소 위치에 저장되어 있는 명령어들을 순차적으로 수행한다는 의미

## 함수 포인터의 사용 방법
* \__cdecl is function calling convention

## 자료형에게 별명을 붙여주는 typedef
* typedef specifier
  * give symbolic names (or aliases) to type
  * Does not create new types
* portable data types
  * ex) size_t, time_t
    * sizeof() return type x86 : unsigned int / x64 : unsigned long long
      * 환경에 따라 자료형을 바꿔줌
* typedef(권장) vs #define
  * typedef interpretation is performed by the compiler, not the preprocessor
  * more flexible than #define
  * typedef has scopes
* one good way to synthesize declarations is in small steps with typedef

## 복잡한 선언을 해석하는 요령
* Deciphering complex declarations
  * always read declarations from the inside out
  * when there's a choice, always favor [] and () over \*(asterisk)
* A function can't return an array, but it can return a pointer to an array
* A function can't return a function, but if can return a pointer to a function
* An array of functions aren't possible, but an  array of function pointers are possible

## qsort 함수 포인터 연습문제
```C
void qsort(
   void *base,
   size_t number,
   size_t width,
   int (__cdecl *compare )(const void *, const void *)
);
```
