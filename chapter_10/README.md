# 배열과 포인터

## 배열과 메모리
![Capture](https://user-images.githubusercontent.com/74703501/129678102-72871c76-9765-4822-9cc3-80845380052b.PNG)   
[출처](https://www.inflearn.com/course/following-c/)
![Capture1](https://user-images.githubusercontent.com/74703501/129678962-4412ba6d-f814-447e-b2ba-7a77e62624a4.PNG)   
[출처](https://www.inflearn.com/course/following-c/)
![Capture2](https://user-images.githubusercontent.com/74703501/129679010-fb91063b-869d-43f6-b512-00845b593df7.PNG)   
[출처](https://www.inflearn.com/course/following-c/)
![Capture3](https://user-images.githubusercontent.com/74703501/129679015-b8be2637-3eb5-4a4b-a1aa-b86054b3720b.PNG)   
[출처](https://www.inflearn.com/course/following-c/)
![Capture4](https://user-images.githubusercontent.com/74703501/129679017-21ea659a-1d16-4892-85d5-3f7c48922a7c.PNG)   
[출처](https://www.inflearn.com/course/following-c/)
![Capture5](https://user-images.githubusercontent.com/74703501/129679020-15c06d34-664d-4fda-aba8-085528cdebb8.PNG)   
[출처](https://www.inflearn.com/course/following-c/)

## 배열의 기본적인 사용방법
```C
// 배열 array의 주소와 array[0]의 주소는 같다(index는 array의 첫 번째 주소로부터 떨어진 거리를 의미)
array == &array[0]

// 배열의 선언과 동시에 값을 넣은 경우에는 값을 변경하고 싶으면 하나씩 변경해야 함
int array[4] = { 1, 2, 3, 4};

array[1] = 1;
array[2] = 2;
array = { 2, 3, 4, 5} // Not working

// const 사용(배열의 값 변경 불가)
const int low[3] = { 2, 3, 4 };

int insuff[4] = { 2, 4 } // 나머지 부분은 컴파일러가 0으로 채워줌

// 배열의 크기를 모를 경우 배열을 선언, 크기를 구하는 방법
const int power_of_twos[] = { 1, 2, 4, 8, 16, 32, 64 };
int array_size = sizeof power_of_twos / sizeof power_of_twos[0]

// Variable-Length Array(VLA)
int n = 8;
float arr9[n];
```

## 포인터의 산술 연산(Pointer Arithmetic)
* 포인터에 어떤 숫자를 더한다는 것은 포인터의 자료형 크기만큼 더하는 것을 의미
* void : 자료형이 없는 것
* 포인터끼리 뺄셈은 가능하고, 덧셈은 안 됨

## 포인터와 배열
```C
int arr[5] = { 1, 2, 3, 4, 5 };
int* ptr = arr;

*(ptr + 1) == arr[1]; // 포인터 산술연산으로 주소 이동 가능
```

## 2차원 배열과 메모리
* 2차원 배열도 메모리 주소의 공간은 1차원임
* 메모리에 저장된 순서와 메모리에서 읽는 순서가 같으면 속도가 빠름   
![image](https://user-images.githubusercontent.com/74703501/129687619-a0829da5-f8ce-420b-a350-e2a73f271ec5.png)
[출처](https://www.inflearn.com/course/following-c/)

## 배열을 함수에게 전달해주는 방법
* 배열을 함수에게 전달할 경우의 이점
  * 데이터 자체를 복사하는 것이 아니라, 주소를 얻는 것이기 때문에 속도와 메모리 측면에서 성능이 향상
* 함수에서 배열을 받을 때는 포인터로 받음
  * 배열 자체를 받는 것은 데이터를 전부 복사해야하기 때문에 비효율적
* 주소 공유를 통한 메모리 절약 예시
![image](https://user-images.githubusercontent.com/74703501/129693350-109bec95-f2a5-4101-9be0-33d4c69c2f3d.png)   
[출처](https://www.inflearn.com/course/following-c/)
* 프로토타입 선언 방법
```C
// 모두 가능
double average(double *, int n); // 권장
double average(double [], int n);
double average(double* array, int n);
double average(double array[], int n);
```

## 두 개의 포인터로 배열을 함수에게 전달해주는 방법
* 주로 배열의 첫 번째 주소와 마지막 주소+1을 전달
```C
// prototyping
// 시작과 마지막 주소를 받아서 평균을 반환하는 함수
double average(double*, double*);

// 중략

double average(double* start, double* end)
{
  int count = end - start;
  double avg = 0.0;
  while (start < end)
  {
    avg += *start++;
  }
  avg /= (double)count;
  
  return avg;
}
```

## 포인터 연산 총정리
* 포인터 변수의 차이 format specifier : %td
* 포인터도 결국 변수다

## const와 배열과 포인터
* const 배열을 포인터로 받고 값을 변경하면 가능
```C
const double arr[3] = { 1.0, 2.0, 3.0 };
arr[2] = 1.1; // error

double* pd = arr;
*pd = 3.0;
pd[2] = 1024.0; // 가능

// pd가 가리키고 있는 곳의 메모리 값을 못 바꿈
const double* pd = arr;
pd++; // 가능

// pd 주소 자체를 못 바꿈
double* const pd = arr;
pd++; // 불가
```

## 배열 매개변수와 const
* 함수에게 배열을 매개변수로 사용하면 주소를 보내는 것이기 때문에, 기존 값이 변경될 수 있음
* 내용이 바뀌면 안 되는 것들을 미리 const로 변경이 안 되게 함

## 포인터에 대한 포인터(2중 포인터)의 작동 원리
![image](https://user-images.githubusercontent.com/74703501/129699390-0f8c3af4-7b08-476a-933e-0c4f1fa085e4.png)   
[출처](https://www.inflearn.com/course/following-c/)
![image](https://user-images.githubusercontent.com/74703501/129699515-7d4bae15-0f27-4161-be39-ce3e0136b145.png)   
[출처](https://www.inflearn.com/course/following-c/)

* 이중포인터는 배열의 배열을 나타낼 때 쓰임

## 포인터의 배열과 2차원 배열
![Capture11](https://user-images.githubusercontent.com/74703501/129702359-f8ef17ba-26bc-4d32-87cd-9cd1ac6bd751.PNG)   
[출처](https://www.inflearn.com/course/following-c/)
![Capture22](https://user-images.githubusercontent.com/74703501/129702352-4a991173-7235-46b6-9d92-ac557629b055.PNG)   
[출처](https://www.inflearn.com/course/following-c/)
![Capture33](https://user-images.githubusercontent.com/74703501/129702356-e0bb7726-5137-4eac-b1aa-f1459e1965b1.PNG)   
[출처](https://www.inflearn.com/course/following-c/)
* arr와 &arr[0]는 동일하지만 포인터와 다른 점은 주소를 따로 저장하는 공간을 갖고 있지 않음

## 2차원 배열과 포인터
![image](https://user-images.githubusercontent.com/74703501/129710089-64baab06-a2f0-472f-8b80-a0cf31f44a9c.png)   
[출처](https://www.inflearn.com/course/following-c/)
```C
float (*pa)[4]; // a SINGLE pointer to an array of 4 floats
float* ap[2]; // an array of TWO pointers-to-float

printf("%zu\n", sizeof(pa)); // 8 in x64
printf("%zu\n", sizeof(ap)); // 16 in x64
```

## 포인터의 호환성(Compatibility)
* 서로 다른 자료형 포인터의 호환(권장하지 않음)
```C
int n = 5;
double x;
x = n;
int* p1 = &n;
double* pd = &x;
pd = p1; // warning
```

## 다차원 배열을 함수에게 전달해주는 방법
```C
// prototyping
int sum2d(int* ar, int row, int col);
int sum2d(int ar[][5], int row);
```
## 변수로 길이를 정할 수 있는 배열(Variable-Length-Arrays(VLAs)
```C
int n = 5;
float my_arr[n];
```
* 동적할당 메모리를 더 많이 사용하기 때문에 잘 사용하진 않음
* 배열은 한 번 길이가 정해지면 변경 불가

## 복합 리터럴과 배열(Compound Literals)
```C
int arr1[2] = { 1, 2 };
int arr2[2][4] = { {1, 2, 3, 4}, {5, 6, 7, 8} };

// 일반적인 형태
sum_1d(arr1,2);
sum_2d(arr2,2);

// Compound Literals(잘 안 쓰이지만, 코드의 길이를 줄일 수 있어서 가끔 사용함)
sum_1d((int[2]) {1, 2}, 2);
sum_2d((int[2][4]) { {1, 2, 3, 4}, {5, 6, 7, 8} }, 2);
```
