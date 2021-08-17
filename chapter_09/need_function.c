#include "header.h"

int main()
{
    print_multiple_chars('*', WIDTH, true);

    print_centered_str(NAME);
    print_centered_str(ADDRESS);
    print_centered_str("I love you");

    print_multiple_chars('*', WIDTH, false);

    return 0;
}

