#ifndef CHARS_CHAR_CLASS_H_INCLUDED
#define CHARS_CHAR_CLASS_H_INCLUDED


#include <stdbool.h>


bool
is_ascii_alpha_char(int ch);

bool
is_ascii_digit_char(int ch);

bool
is_ascii_identifier_char(int ch);

bool
is_ascii_identifier_start_char(int ch);

bool
is_url_encode_unreserved_char(int ch);


#endif
