# 문자 입출력과 입력 유효성 검증

## 입출력 버퍼(Buffer)
![image](https://user-images.githubusercontent.com/74703501/129468603-663cf5d2-68ca-40a1-9862-df9ed0b02486.png)   
[출처](http://tcpschool.com/c/c_io_console)   
* Buffer : 데이터를 한 곳에서 다른 한 곳으로 전송하는 동안 일시적으로 그 데이터를 보관하는 메모리의 영역
  * 장점 
    * 문자를 하나씩 전달하는 것이 아닌 묶어서 한 번에 전달하므로, 전송 시간이 적게 걸려 성능이 향상
    * 사용자가 문자를 잘못 입력했을 경우 수정을 할 수 있음
  * 단점
    * 빠른 반응이 요구되는 게임과 같은 프로그램에서는 부적절함
    
## 파일의 끝(EOF: End Of File)
* EOF : 데이터 소스로부터 더 이상 읽을 수 있는 데이터가 없음을 나타냄(myust be negative(but is commonly -1)
* EOF == ctrl + z

## 입출력 방향 재지정(Redirection)
* 기존 입출력 : 콘솔을 통해 입출력을 실행
* file에 output을 넣을 수 도 있고, file로 input을 받을 수도 있음
```bash
// create output.txt & renew output
$ test.exe > output.txt
// create output.txt & update 
$ test.exe >> output.txt

// file로 input 받기
$ test.exe < input.txt

```

## 입력 스트림과 숫자
* 기본적으로 프로그램이 콘솔 입력을 받아 올 때 한 글자씩 문자로 받아옴
* 항상 문자로 입력을 받아들이는데, 숫자로 변경이 가능하면 숫자로 변경을 해줌
* 하지만 내부적으로는 2진수로 변환이 된 데이터의 스트림으로 통신함

## 텍스트 파일 읽기
* getc(), putc() vs getchar(), putchar()
  * getc(), putc() : stream을 인자로 받음
  * getchar(), putchar() : stream을 인자로 받지 못함
* open file & close file
```C
  file = fopen(file_name, 'r') // r : read, w : write
  
  fclose(file) // 파일을 닫지 않으면 다른 사람이 접근 못함
```
