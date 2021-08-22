#include <stdio.h>
#include <string.h>

#define NLEN 30

struct name_count {
    char first[NLEN];
    char last[NLEN];
    int num;
};

void receive_input(struct name_count*);
void count_characters(struct name_count*);
void show_result(const struct name_count*);
char* s_gets(char* st, int n);

int main()
{
    struct name_count user_name;

    receive_input(&user_name);
    count_characters(&user_name);
    show_result(&user_name);

    return 0;
}

void receive_input(struct name_count* ptr_nc)
{
    int flag;

    printf("Input your first name:\n>>");

    // flag = s_gets(ptr_nc->first, NLEN);
    flag = scanf("%[^\n]%*c", ptr_nc->first);
    if (flag != 1)
        printf("Wrong input");
    
    printf("Input your last name:\n>>");

    flag = scanf("%[^\n]%*c", ptr_nc->last);
    if (flag != 1)
        printf("Wrong input");

}

void count_characters(struct name_count* ptr_nc)
{
    ptr_nc->num = strlen(ptr_nc->first) + strlen(ptr_nc->last);
}

void show_result(const struct name_count* ptr_nc)
{
    printf("Hi, %s %s. Your name has %d characters.\n",
        ptr_nc->first, ptr_nc->last, ptr_nc->num);
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