#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool read_isbn( char *isbn, int const isbn_capacity );
void normalize_isbn( char *normalized, char const *const isbn, int const isbn_capacity );
bool isbn_length_is_valid( char const *const isbn );
bool is_valid_10_digit( char const *const isbn );
bool is_valid_13_digit( char const *const isbn );

int main( void )
{
    int const isbn_capacity = 20;
    char isbn[isbn_capacity];
    char normalized_isbn[isbn_capacity];


    return 0;
}

bool read_isbn( char *isbn, int const isbn_capacity )
{
    int const format_capacity = 32;
    char format_string[format_capacity];

    snprintf( format_string, 32, " %%%d[^\n]", isbn_capacity - 1 );

    return scanf( format_string, isbn ) == 1;
}

void normalize_isbn( char *normalized, char const *const isbn, int const isbn_capacity )
{
    int index = 0;

    for( int i = 0; isbn[i] && i < ( isbn_capacity - 1 ); ++i )
    {
        if( isdigit( isbn[i] ) )
        {
            normalized[index] = isbn[i];
            ++index;
        }
    }

    normalized[index] = '\0';
}

bool isbn_length_is_valid( char const *const isbn )
{
    int const length = strlen( isbn );

    return length == 10 || length == 13;
}

bool is_valid_10_digit( char const *const isbn )
{
    int verification_digit = 0;

    for( int i = 0; i < 9; ++i )
    {
        verification_digit += ( i + 1 ) * ( isbn[i] - '0' );
    }
    verification_digit %= 11;

    if( verification_digit == 10 )
    {
        verification_digit = 'X';
    }
    else
    {
        verification_digit += '0';
    }

    return verification_digit == isbn[9];
}

bool is_valid_13_digit( char const *const isbn )
{
    int verification_digit = 0;
    int multiplier = 1;

    for( int i = 0; i < 12; ++i )
    {
        verification_digit += multiplier * ( isbn[i] - '0' );

        if( multiplier == 1 )
        {
            multiplier = 3;
        }
        else
        {
            multiplier = 1;
        }
    }
    verification_digit %= 10;
    verification_digit = 10 - verification_digit;

    if( verification_digit == 10 )
    {
        verification_digit = '0';
    }
    else
    {
        verification_digit += '0';
    }

    return verification_digit == isbn[12];
}
