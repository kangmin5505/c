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

## 복합 리터럴

## 신축성있는 배열 멤버

## 익명 구조체

## 구조체의 배열을 사용하는 함수

## 구조체 파일 입출력 연습문제

## 공용체의 원리

## 공용체와 구조체를 함께 사용하기

## 익명 공용체

## 열거형

## 열거형 연습문제

## 이름공간 공유하기

## 함수 포인터의 원리

## 함수 포인터의 사용 방법

## 자료형에게 별명을 붙여주는 typedef

## 복잡한 선언을 해석하는 요령

## qsort 함수 포인터 연습문제

## 함수 포인터의 배열 연습문제
