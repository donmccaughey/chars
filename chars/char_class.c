#include "char_class.h"

#include <ctype.h>


bool
is_ascii_alpha_char(int ch)
{
    return (ch >= 'A' && ch <= 'Z')
        || (ch >= 'a' && ch <= 'z');
}


bool
is_ascii_digit_char(int ch)
{
    return ch >= '0' && ch <= '9';
}


bool
is_ascii_identifier_char(int ch)
{
    return is_ascii_digit_char(ch) || is_ascii_identifier_start_char(ch);
}


bool
is_ascii_identifier_start_char(int ch)
{
    return is_ascii_alpha_char(ch) || '_' == ch;
}


bool
is_url_encode_unreserved_char(int ch)
{
    return is_ascii_alpha_char(ch)
        || is_ascii_digit_char(ch)
        || ch == '-'
        || ch == '_'
        || ch == '.'
        || ch == '~';
}
