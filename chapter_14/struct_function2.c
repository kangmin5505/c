#include <stdio.h>
#include <string.h>

#define NLEN 30

struct name_count {
    char first[NLEN];
    char last[NLEN];
    int num;
};

struct name_count receive_input();
struct name_count count_characters(struct name_count);
void show_result(const struct name_count);
char* s_gets(char* st, int n);

int main()
{
    struct name_count user_name;

    user_name = receive_input();
    user_name = count_characters(user_name);
    show_result(user_name);

    return 0;

}

struct name_count receive_input()
{
    struct name_count nc;

    int flag;

    printf("Input your first name:\n>>");

    s_gets(nc.first, NLEN);

    printf("Input your last name:\n>>");

    s_gets(nc.last, NLEN);

    return nc;
}

struct name_count count_characters(struct name_count nc)
{
    nc.num = strlen(nc.first) + strlen(nc.last);

    return nc;
}

void show_result(const struct name_count nc)
{
    printf("Hi, %s %s. Your name contains %d characters.\n",
        nc.first, nc.last, nc.num);
}

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