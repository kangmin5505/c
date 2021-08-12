# 연산자, 표현식, 문장

## 반복 루프와의 첫 만남(Loop)
* 이전에는 goto문을 사용했었음
* 현재는 while문을 사용
```C
#include <stdio.h>

int main()
{
  // goto문
  int n = 1;
  
 label:
  printf("%d\n", n);
  n = n + 1;
  
  if (n == 10) goto out;
  
  goto label;
 
 out:
  
  // while문
  while (n++ < 11)
  {
    printf("%d\n", n);
  }

  return 0;
  
}
```

## 대입 연산자와 몇 가지 용어들
* Object, L-value, R-value, Operand
  * Data object(Object)
  * L-value(object locator value)
  * R-value(value of expression)
  * Operator, Operand

## 더하기 빼기, 부호 연산자들
* 이항연산자(binary operator), 단항연산자(Unary operator)

## 연산자 우선 순위(Operator precedence)   
![image](https://user-images.githubusercontent.com/74703501/129131443-3871b0b1-310b-44ad-a990-55a15b5009a8.png)   
[출처](https://marinelifeirony.tistory.com/12)

## 나머지 연산자(Modular operator)
```C
#include <stdio.h>

int main()
{

    div = 11 / 5;
    mod = 11 % 5;
    printf("div = %d, mod = %d\n", div, mod); // 2, 1

    div = 11 / -5;
    mod = 11 % -5;
    printf("div = %d, mod = %d\n", div, mod); // -2, 1

    div = -11 / -5;
    mod = -11 % -5;
    printf("div = %d, mod = %d\n", div, mod); // 2, -1

    div = -11 / 5;
    mod = -11 % 5;
    printf("div = %d, mod = %d\n", div, mod); // -2, -1


    return 0;
}

```

## 증감 연산자
* ++ and -- affect modifiable L-values
* 후위 증감 연산자는 그 줄의 연산이 종료된 후 실행
* 한 문장 안에 증감 연산자를 여러 번 쓰는 것은 지양
```C

    int i = 1, j = 1;
    int i_post, pre_j;

    i_post = i++;
    pre_j = ++j;

    printf("%d %d\n", i, j);
    printf("%d %d\n", i_post, pre_j);

    int i = 3;
    int l = 2 * --i;
    printf("%d %d\n", i, l);

    i = 1;
    l = 2 * i--;
    printf("%d %d\n", i, l);

    int x, y, z;
    x = 3, y = 4;
    z = x * y++;
    printf("%d %d %d\n", x, y, z);
```
## 표현식과 문장(Expressions & Statements)
* 표현식   
![image](https://user-images.githubusercontent.com/74703501/129133293-dbeeb118-cdab-4f56-bd49-41529b2cf55b.png)   
[출처](https://www.inflearn.com/course/following-c)

* 문장
![image](https://user-images.githubusercontent.com/74703501/129133378-4023133a-aa8a-42f9-9f6d-c6c5bdb0200f.png)   
[출처](https://www.inflearn.com/course/following-c)

* Side effects and Sequence points
![image](https://user-images.githubusercontent.com/74703501/129133435-2e114840-2f00-4c9f-8420-b0f03cc85314.png)   
[출처](https://www.inflearn.com/course/following-c)

## 순서도(Flowchars)
![image](https://user-images.githubusercontent.com/74703501/129133515-658ed4d5-f334-4a86-b259-035d78790abb.png)   
[출처](https://blog.naver.com/PostView.nhn?isHttpsRedirect=true&blogId=ya3344&logNo=221685396020)

## 자료형 변환(Type conversion)
* Promotions in assignments
* Demotion in assignments
  * 분수로 정확하게 나타낼 수 있는 값은 truncate가 발생하지 않음
* Ranking of types in operations
* casting operators
* 예제
```C
#include <stdio.h>

int main()
{
    /* promotions in assignments */
    short s = 64;
    int i = s;

    float f = 3.14f;
    double d = f;

    /* demotion in assignments */
    d = 1.25;
    f = 1.25;
    f = 1.123;

    /* ranking of types in operations */
    // long double > double > float
    // unsigned long long, long long
    // unsigned long, long
    // unsigned, int
    // short int, unsigned short int
    // signed char, char, unsigned char
    // _Bool
    // Ref: Google "Integer conversion rank"
    d = f + 1.234;
    f = f + 1.234;

    /* casting operators */
    d = (double)3.14f;
    i = 1.6 + 1.7;
    i = (int)1.6 + (int)1.7;

    /* more examples */
    char c;
    f = i = c = 'A'; // 65
    printf("%c %d %f\n", c, i, f);
    c = c + 2;// 'C', 67
    i = f + 2 * c;// 65.0f + 2 * 67
    printf("%c %d %f\n", c, i, f); // 199
    c = 1106; // demolition, 1106 = 0b10001010010, 0b01010010 = 1106 % 256 = 82 = 'R'
    printf("%c\n", c);
    c = 83.99;
    printf("%c\n", c);


}

```

## 함수의 인수와 매개변수(Arguments & Parameter)
* Arguments vs Parameters
  * actual argument,  actual parameter -> argument (values)
  * formal argument, formal parameter -> parameter (variables)

```C
#include <stdio.h>

void draw(int n);

int main()
{
    int i = 5;
    char c = '#'; // 35
    float f = 7.1f;

    draw(i); // i는 value이기 때문에 arguments
    draw((int)c);
    draw((int)f);
    
    return 0;
}

void draw(int n) // n은 variables이기 때문에 parameters
{
    while (n-- > 0)
    {
        printf("*");
    }
    printf("\n");
}
```
