#include <stdio.h>
#include <inttypes.h> // intmax_t

int main()
{
    /* multiple inputs with blank separators */
    // int i;
    // float f;
    // char str[30];
    // scanf("%d %f %s", &i, &f, str); 
    // printf("%d %f %s\n", i, f, str);

    /* character */
    // char c;
    // scanf("%c", &c); // try blank
    // printf("%i\n", c); // blank is 32

    /* Unsigned as signed  */
    // unsigned i;
    // scanf("%i", &i); // try negative number
    // printf("%i\n", i);

    /* Unsigned as unsigned */
    // unsigned i2;
    // scanf("%u", &i2);
    // printf("%u\n", i2);

    /* floating point numbers */
    /* l for double for %f, %e, %E, %g */
    // double d = 0.0;
    // scanf("%lf", &d); // if, try E notation
    // printf("%f\n", d);

    /* Width */
    // char str[30];
    // scanf("%5s", str); // width
    // printf("%s\n", str);

    /* h modifier */
    // char i;
    // scanf("%hhd", &i);
    // printf("%i\n", i);

    /* integer with characters */
    // int i;
    // scanf("%i", &i); // try '123ab', '123a456'
    // printf("%i", i);

    /* j modifier */
    // intmax_t i;
    // scanf("%ji", &i);
    // printf("%ji", i);

    /* Regular characters */
    // int a, b;
    // scanf("%d,%d", &a, &b); // try blank separator only
    // scanf("%d ,%d", &a, &b);
    // scanf("%d, %d", &a, &b);
    // scanf("%d,%d", &a, &b);
    // scanf("%d-%d", &a, &b);
    // scanf("%dA%d", &a, &b);
    // printf("%d %d\n", a, b);

    /* char receives blank */
    // int a, b;
    // char c;
    // scanf("%d%c%d", &a, &c, &b);// try 123 456 (blank)
    // printf("%d|%c|%d\n", a, c, b); //| is separator

    /* return value of scanf() */
    // int a, b;
    // int i = scanf("%d%d", &a, &b);
    // printf("%d\n", i);

    return 0;
}