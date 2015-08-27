#ifndef CHARS_ADD_CHAR_H_INCLUDED
#define CHARS_ADD_CHAR_H_INCLUDED


#include <stdbool.h>


typedef char *
add_transformed_char_fn(char ch, char *buffer, char *buffer_end, bool *is_full);


char *
add_char(char ch, char *buffer, char *buffer_end, bool *is_full);

char const *
transform_string(char const *source,
                 add_transformed_char_fn add_transformed_char,
                 char *destination,
                 char *destination_end);


#endif
