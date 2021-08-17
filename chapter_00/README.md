# 초보 프로그래머를 위한 컴퓨터의 작동원리

## 컴퓨터의 구성 요소
* User, Input device, Computer, Ouput device
### Hardware
* Mainboard
  * Power supply
  * Primary memory(RAM, ROM)
    * RAM(Random Access Memory)
      * Volatile type of memory
      * Random access
  * Secondary memory(HDD, SSD)
    * HDD(Hard Disk Drive)
    * SSD(Solid State Drive)
    * FDD(Floppy Disk Drive)
    * Magnetic Tape
  * CPU(Central Processing Unit)
  * Graphics card
    * GPU(Graphics Processing Unit)
      * memory와 CPU 포함
  * Display
  * Input-Output Units

### Software

## 컴퓨터를 킬 때 일어나는 일
### 부팅 절차
1. 전원 공급
2. 부트 프로그램 실행(ROM BIOS : 운영체제 중 가장 기본적인 소프트웨어이자 컴퓨터의 입출력을 처리하는 펌웨어)
3. 하드웨어 검사
4. 운영체제 로드 : 운영체제는 보조기억 장치에 설치 됌, 컴퓨터 실행 시 보조기억장치에서 주기억장치로 로드
5. 운영체제 실행

## 운영체제가 해주는 일들
* 자원 관리
  * 메모리 관리
  * 프로세스 관리
  * 주변장치 관리
  * 파일 관리
* 시스템 관리
  * 시스템 보호
  * 네트워킹
  * 명령 해석기


 ![image](https://user-images.githubusercontent.com/74703501/128628297-60eb2d4c-ab15-4a6b-b25c-0f93fc607c50.png)
[출처 위키백과](https://ko.wikipedia.org/wiki/%EC%9A%B4%EC%98%81_%EC%B2%B4%EC%A0%9C)

## 현대적 컴퓨터의 기본 구조
![image](https://user-images.githubusercontent.com/74703501/128628397-64432892-9d23-4cbb-ab1f-9176e0834eac.png)
[출처 위키백과](https://ko.wikipedia.org/wiki/%ED%8F%B0_%EB%85%B8%EC%9D%B4%EB%A7%8C_%EA%B5%AC%EC%A1%B0)
![image](https://user-images.githubusercontent.com/74703501/128628484-38ff82de-e54f-47b8-a82e-832264bef284.png)
[출처 ataCadamia](https://datacadamia.com/computer/organization)
## 컴퓨터 메모리의 기본 구조
Sequential access VS Random access
![image](https://user-images.githubusercontent.com/74703501/128628623-7770bfc6-3641-492d-926a-80c3c8e19838.png)
![image](https://user-images.githubusercontent.com/74703501/128628628-82cfdbdd-affd-4995-8f74-f58935687f07.png)
## CPU의 기본 구조
### 언어 단계
* High level programming language
* Assembly language
* Machine code(CPU의 사용언어)

### CPU의 구성 요소
* Control Unit
* ALU(Arithmetic Logic Unit)
* Registers
  * PC(Program Counter) : 다음 명령어의 메모리 주소 저장
  * Accumulator : 연산에 사용되는 데이터 저장
  * IR(Instruction Register) : 메모리에서 읽어온 명령어 저장
  * Status Register : 현재 CPU의 상태를 저장
  * MAR(Memory Address Register) : 읽거나 쓴 메모리주소 저장
  * MBR(Memory Buffer Register) : 메모리에서 읽어온 데이터 저장
## CPU가 일하는 방법
![image](https://user-images.githubusercontent.com/74703501/128628967-b223539b-260b-4e63-b1a0-4f4fec7bf9e6.png)
## 정보의 단위
* 데이터 => 처리과정 => 정보
* 비트(Bit: Binary digit) : 정보의 기본 단위
* 1바이트(byte) = 8bit : 메모리 주소의 기본 단위
* 16bit, 32bit = word : CPU가 데이터를 다루는 기본 단위(레지스터의 크기)

## 2진수
* 2의 보수 정수 표현법에서 -0과 0은 같다
* signed와 unsigned의 차이 : 숫자의 범위
