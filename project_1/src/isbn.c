#include <stdbool.h>
#include <stdio.h>

bool read_isbn( char isbn[], int const isbn_capacity );

int main( void )
{
    int const isbn_capacity = 20;
    char isbn[isbn_capacity];


    return 0;
}

bool read_isbn( char isbn[], int const isbn_capacity )
{
    int const format_capacity = 32;
    char format_string[format_capacity];

    snprintf( format_string, 32, " %%%d[^\n]", isbn_capacity - 1 );

    return scanf( format_string, isbn ) == 1;
}
