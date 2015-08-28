#include "transform.h"

#include <errno.h>


bool
add_untransformed_char(char ch, char **buffer, char *buffer_end)
{
    if (buffer_end <= *buffer) {
        return false;
    } else {
        *(*buffer)++ = ch;
        return true;
    }
}


char const *
transform_string(char const *source,
                 add_transformed_char_fn add_transformed_char,
                 char *buffer,
                 char *buffer_end)
{
    if (!source || !add_transformed_char || !buffer || !buffer_end) {
        errno = EFAULT;
        return NULL;
    }
    if (buffer_end - buffer < 1) {
        errno = EINVAL;
        return NULL;
    }
    
    buffer_end -= sizeof(char);
    while (*source && add_transformed_char(*source, &buffer, buffer_end)) {
        ++source;
    }
    *buffer = '\0';
    return source;
}
