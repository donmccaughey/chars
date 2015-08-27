#include "add_char.h"

#include <errno.h>


char *
add_char(char ch, char *buffer, char *buffer_end, bool *is_full)
{
    if (buffer_end == buffer) {
        *is_full = true;
    } else {
        *buffer++ = ch;
        *is_full = false;
    }
    return buffer;
}


char const *
transform_string(char const *source,
                 add_transformed_char_fn add_transformed_char,
                 char *destination,
                 char *destination_end)
{
    if (!source || !destination || !destination_end) {
        errno = EFAULT;
        return NULL;
    }
    
    destination_end -= sizeof(char);
    while (*source) {
        bool is_full;
        destination = add_transformed_char(*source,
                                           destination,
                                           destination_end,
                                           &is_full);
        if (is_full) break;
        ++source;
    }
    *destination = '\0';
    return source;
}
