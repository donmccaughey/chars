#ifndef CHARS_QUOTE_H_INCLUDED
#define CHARS_QUOTE_H_INCLUDED


// Wrap a null terminated string with a prefix and suffix.  The quoted string
// is written to the buffer given by [buffer, buffer_end).  If the buffer is
// not large enough to contain the complete quoted string, an empty string is
// written to the buffer.  The buffer is always null terminated.  Returns 0
// if the quoted string fits in the buffer, -1 if not.
//
// A buffer of size (strlen(prefix) + strlen(s) + strlen(suffix) + 1) will
// guarantee that the complete wrapped string plus null terminator will fit.
int
quote_string(char const *string,
             char const *prefix,
             char const *suffix,
             char *buffer,
             char *buffer_end);


#endif
