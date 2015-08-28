#ifndef CHARS_TRANSFORM_H_INCLUDED
#define CHARS_TRANSFORM_H_INCLUDED


#include <stdbool.h>


// Character transformation function type.  The source character `ch' is
// transformed and written to the destination given by [*buffer, buffer_end).
// The transformed character may be a sequence of zero or more chars.  If the
// transformed character fits in the buffer, `*buffer' is set to the next
// available location in the buffer and `true' returned.  If the transformed
// character does not fit in the buffer, `*buffer' is not modified and `false'
// is returned.
typedef bool
add_transformed_char_fn(char ch, char **buffer, char *buffer_end);


// Write a char to a string buffer without modification.
bool
add_untransformed_char(char ch, char **buffer, char *buffer_end);

// Transform a null terminated string using the provided char transformation
// function.  The transformed string is written to the buffer given by
// [buffer, buffer_end).  If the buffer is not large enough to contain the
// complete transformed string, it will contain as many transformed character
// sequences as will fit.  The buffer is always null terminated.
//
// If the transformed string fits completely in the buffer, the returned value
// points to the null terminator in the source string.  If the buffer is not
// big enough to fit the full transformed string, the returned value points to
// the first untransformed character in the source string.
//
// If any of the arguments are NULL, `errno' is set to EFAULT and NULL is
// returned.  If the destination buffer does not have a positive size, `errno'
// is set to EINVAL and NULL is returned.
char const *
transform_string(char const *source,
                 add_transformed_char_fn add_transformed_char,
                 char *buffer,
                 char *buffer_end);


#endif
