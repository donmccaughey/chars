#ifndef CHARS_QUOTE_H_INCLUDED
#define CHARS_QUOTE_H_INCLUDED


#include <stdbool.h>


// Wrap a null terminated string with a prefix and suffix.  The quoted string
// is written to the buffer given by [buffer, buffer_end).  If the buffer is
// not large enough to contain the complete quoted string, an empty string is
// written to the buffer.  The buffer is always null terminated.  Returns true
// if the quoted string fits in the buffer, false if not.
//
// A buffer of size (strlen(prefix) + strlen(s) + strlen(suffix) + 1) will
// guarantee that the complete wrapped string plus null terminator will fit.
bool
quote_string(char const *string,
             char const *prefix,
             char const *suffix,
             char *buffer,
             char *buffer_end);


#endif
