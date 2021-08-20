# 파일 입출력

## 파일 입출력의 작동 원리
![image](https://user-images.githubusercontent.com/74703501/130175772-0eb3d71c-dfb1-4da7-bbb9-4c175ff170ec.png)   
[출처](https://www.inflearn.com/course/following-c)   
![image](https://user-images.githubusercontent.com/74703501/130175776-3d7a4b60-306a-4bf2-9485-f45d86d97640.png)   
[출처](https://www.inflearn.com/course/following-c)   
![image](https://user-images.githubusercontent.com/74703501/130175789-7850d221-f4a0-49ff-ae5f-bc202d6f69a4.png)   
[출처](https://www.inflearn.com/course/following-c)   

## 텍스트 파일 입출력 예제
```C
#include <stdio.h>
#include <stdlib.h> // EXIT_FAILURE

int main()
{
  int ch;
  FILE* fr, fw;
  /*
  typedef struct _iobuf
  {
    char* _ptr;
    int _cnt;
    char* _base;
    int _flag;
    int _file;
    int _charbuf;
    int _bufsiz;
    char* _tmpfname;
  }
  */
  const char* out_filename = "output.txt"
  unsigned long count = 0;
  
  // 에러 처리 중략
  
  while ((ch = fgetc(fr)) != EOF) // fgetc()(권장) == getc()
  {
    fputc(ch, stdout); // fputc()(권장) == putc() == putchar()
    fputc(ch, fw);
    count++;
  }
  
  fclose(fr);
  fclose(fw);
  
  return 0;
}
```
* fopen mode strings for text files
  * r : reading
  * w : creating-and-writing or over-writing
  * a : creating-and-writing or appending
  * r+ : both reading and writing
  * w+ : reading and writing, over-writing or creating
  * a+ : reading and writing, appending or creating
  
## 텍스트 인코딩(encoding)과 코드 페이지(code page)
* 코드 페이지
  * 특정한 문자 인코딩 테이블

## 텍스트 파일 입출력 함수들
* fprintf(), fscanf(), fgets(), fputs()
* r+ : 파일이 없으면 열지를 못 함 / writing 시 앞에 appending
* rewind() : go back to beginning of file
* fscanf(), fprintf() vs fgets(), fputs()
  * 단어 단위로 끊음
    * fscanf(FILE *stream, const char *format-string, argument-list)
    * fprintf(FILE *stream, const char *format-string, argument-list)
  * 문장 단위로 끊음
    * fgets(char *string, int n, FILE *stream)
    * fputs(const char *string, FILE *stream)
    
## 바이너리(binary) 파일 입출력
* fopen() mode string for binary IO
  * "rb", "wb", "ab"
  * "ab+", "a+b"
  * "wb+", "w+b"
  * "ab+", "a+b"
* 'x' mode fails if the file exists, instead of overwriting it.
  * "wx", "wbx", "w+x", "wb+x", "w+bx"
* feof() : returns non-zero at EOF
* ferror() : returns 0 is ok, non-zero otherwise

## 파일 임의 접근(random access)
* ftell() == fgetpos()
  * 현재 위치 알려줌
* fseek() == fsetpos()
  * SEEK_SET : 시작점에서 이동
  * SEEK_CUR : 현재 위치에서 이동
  * SEEK_END : 마지막으로 이동
* fpos_t : 형식지정자가 따로 있지 않음

## 기타 입출력 함수들
* ungetc(), fflush(), setvbuf()
  * ungetc() : 다시 버퍼에 넣어줌
  * fflush() : Writing a large amount of data
  * setvbuf() : 버퍼의 설정을 바꿔줌
    * _IOLBF, _IOFBF, _IONBF

## 텍스트 파일을 바이너리 처럼 읽어보기
* CRLF('\r', '\n'), LF('\r', '\n')
  * CRLF(Carriage Return, Line Feed)
  * LF(Line Feed)
  * '\r' : 아스키코드 13
  * '\n' : 아스키코드 10
