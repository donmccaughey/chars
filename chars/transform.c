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
                 char *destination,
                 char *destination_end)
{
    if (!source || !add_transformed_char || !destination || !destination_end) {
        errno = EFAULT;
        return NULL;
    }
    if (destination_end - destination < 1) {
        errno = EINVAL;
        return NULL;
    }
    
    destination_end -= sizeof(char);
    while (*source && add_transformed_char(*source, &destination, destination_end)) {
        ++source;
    }
    *destination = '\0';
    return source;
}
