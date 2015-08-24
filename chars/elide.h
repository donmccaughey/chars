#ifndef CHARS_ELIDE_H_INCLUDED
#define CHARS_ELIDE_H_INCLUDED


#include <stdbool.h>


// Elide a null terminated string if it is too long.  The string is copied into
// the given buffer.  If it fits, it is copied unchanged.  If it is too long,
// as many characters as possible are copied and the given ellipsis string is
// appended.  In both cases, the copied string is null terminated and true is
// returned.  If `is_elided' is not NULL, sets `*is_elided' to `true' if the
// string was elided, `false' if not.
//
// If the buffer is too small to contain the ellipsis string, an empty string
// is placed in the buffer and false is returned.
bool
elide_string(char const *string,
             char const *ellipsis,
             char *buffer,
             char *buffer_end,
             bool *is_elided);


#endif
