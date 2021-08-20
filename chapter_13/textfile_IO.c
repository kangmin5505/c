#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int ch;
    FILE* fr;
    FILE* fr1;
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
   
   const char* out_filename = "output.txt";

   unsigned long count = 0;

   if (argc != 2)
   {
       printf("Usage: %s filename\n", argv[0]);
       exit(EXIT_FAILURE);
   }

   if ((fr = fopen(argv[1], "r")) == NULL)
   {
       printf("Can't open %s\n", argv[1]);
       exit(EXIT_FAILURE);
   }

   if ((fr1 = fopen(out_filename, "w")) == NULL)
   {
       printf("Can't write %s\n", out_filename);
       exit(EXIT_FAILURE);
   }

    /*
        fopen mode strings for text files
        - r : reading
        - w : creating-and-writing or over-writing
        - a : creating-and-writing or appending
        - r+ : both reading and writing
        - w+ : reading and writing, over-writing or creating
        - a+ : reading and writing, appending or creating
    */

   while ((ch = fgetc(fr)) != EOF) // getc(fr)
   {
       fputc(ch, stdout);
       fputc(ch, fr1);
       count++;
   }


   fclose(fr);
   fclose(fr1);

   printf("FILE %s has %lu characters\n", argv[1], count);

   return 0;
}