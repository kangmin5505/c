#include <stdio.h>
#include <string.h> // strlen(), strcmp()
#include <stdlib.h> // malloc(), free()

#define SLEN 81

struct namect {
    char* fname;
    char* lname;
    int letters;
};

void getinfo(struct namect*); // allocate memory
void makeinfo(struct namect*);
void showinfo(const struct namect*);
void cleanup(struct namect*); // free memory when done
char* s_gets(char* st, int n);

int main()
{
    struct namect p = { "Kang-min", "Kim" };
    printf("%s %s\n", p.fname, p.lname);

    char buffer[SLEN] = { 0, };
    int f2 = scanf("%[^\n]%*c", buffer);
    p.fname = (char*)malloc(strlen(buffer) + 1);
    if (p.fname != NULL)
        strcpy(p.fname, buffer);
    printf("%s %s\n", p.fname, p.lname);

    struct namect person;

    getinfo(&person);
    makeinfo(&person);
    showinfo(&person);
    cleanup(&person);
    
}

void getinfo(struct namect* pst)
{
    int flag;
    char temp[SLEN] = { 0, };

    printf("Please enter your first name.\n");
    flag = scanf("%[^\n]%*c", temp);
    if (flag != 1)
        printf("Wrong input");
    else
    {
        pst->fname = (char*)malloc(strlen(temp) + 1);
        if (pst->fname != NULL)
            strcpy(pst->fname, temp);
        else
            printf("Malloc() failed");
    }

    printf("Please enter your last name.\n");
    s_gets(temp, SLEN);
    if (temp[0] == '\0')
        printf("Wrong input");
    else
    {
        pst->lname = (char*)malloc(strlen(temp) + 1);
        if (pst->lname != NULL)
            strcpy(pst->lname, temp);
        else
            printf("Malloc() faild");
    }
}

void cleanup(struct namect* pst)
{
    free(pst->fname);
    free(pst->lname);
}

void makeinfo(struct namect* pst)
{
    pst->letters = strlen(pst->fname) + strlen(pst->lname);
}

void showinfo(const struct namect* pst)
{
    printf("%s %s, your name contains %d letters.\n",
        pst->fname, pst->lname, pst->letters);
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