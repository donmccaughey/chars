#ifndef CHARS_QUOTE_H_INCLUDED
#define CHARS_QUOTE_H_INCLUDED


// Quote a null terminated string by wrapping it with prefix and suffix strings.
// The quoted string is written to the buffer given by [buffer, buffer_end).
// If the buffer is not large enough to contain the complete quoted string, an
// empty string is written to the buffer.  The buffer is always null terminated.
// Returns 0 if the quoted string fits in the buffer, otherwise sets `errno' to
// EINVAL and returns -1.
//
// A buffer of size (strlen(prefix) + strlen(s) + strlen(suffix) + 1) will
// guarantee that the complete wrapped string plus null terminator will fit.
int
quote_string(char const *source,
             char const *prefix,
             char const *suffix,
             char *buffer,
             char *buffer_end);


#endif
