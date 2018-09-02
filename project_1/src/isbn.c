#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

enum
{
    UK_GROUP = 1,
    FR_GROUP = 2,
    RU_GROUP = 5,
    BR_GROUP = 85,
    AR_GROUP = 950,
    OTHER_GROUP = -1
};

bool read_isbn( char *isbn, int const isbn_capacity );
void normalize_isbn( char *normalized, char const *const isbn, int const isbn_capacity );
bool isbn_length_is_valid( char const *const isbn );
bool isbn_is_valid( char const *const isbn );
bool is_valid_10_digit( char const *const isbn );
bool is_valid_13_digit( char const *const isbn );
int get_group( char const *isbn );

int main( void )
{
    int const isbn_capacity = 20;
    char isbn[isbn_capacity];
    char normalized_isbn[isbn_capacity];

    read_isbn( isbn, isbn_capacity );

    normalize_isbn( normalized_isbn, isbn, isbn_capacity );

    if( !isbn_is_valid( normalized_isbn ) )
    {
        printf( "%s is not a valid ISBN\n", isbn );
        return 1;
    }

    printf( "ISBN %s is valid\n", isbn );

    printf( "Book country: " );

    switch( get_group( normalized_isbn ) )
    {
        case UK_GROUP:
            printf( "United Kingdom" );
            break;
        case FR_GROUP:
            printf( "France" );
            break;
        case RU_GROUP:
            printf( "Russia" );
            break;
        case BR_GROUP:
            printf( "Brazil" );
            break;
        case AR_GROUP:
            printf( "Argentina" );
            break;
        default:
            printf( "Other" );
    }

    puts( "\n" );

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

bool isbn_is_valid( char const *const isbn )
{
    int const length = strlen( isbn );

    if( !isbn_length_is_valid( isbn ) )
    {
        return false;
    }

    if( length == 10 )
    {
        return is_valid_10_digit( isbn );
    }

    return is_valid_13_digit( isbn );
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

int get_group( char const *isbn )
{
    int const length = strlen( isbn );

    if( length == 13 )
    {
        isbn = isbn + 3;
    }

    switch( *isbn )
    {
        case '1':
            return UK_GROUP;
            break;
        case '2':
            return FR_GROUP;
            break;
        case '5':
            return RU_GROUP;
            break;
        case '8':
            if( isbn[1] == '5' )
            {
                return BR_GROUP;
            }
            break;
        case '9':
            if( isbn[1] == '5' && isbn[2] == '0' )
            {
                return AR_GROUP;
            }
    }

    return OTHER_GROUP;
}
