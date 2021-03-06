#include "elide.h"

#include <errno.h>


static bool
backup_and_replace_suffix(char *start, char *end, char const *suffix)
{
    char const *s = suffix;
    
    while (*s++) end--;
    if (end < start) return false;
    
    s = suffix;
    while (*s) *end++ = *s++;
    return true;
}


int
elide_string(char const *source,
             char const *ellipsis,
             char *buffer,
             char *buffer_end,
             bool *is_elided)
{
    char *buffer_start = buffer;
    buffer_end -= sizeof(char);
    while (*source && buffer < buffer_end) *buffer++ = *source++;
    if (*source) {
        if (!backup_and_replace_suffix(buffer_start, buffer, ellipsis)) {
            *buffer_start = '\0';
            errno = EINVAL;
            return -1;
        }
        if (is_elided) *is_elided = true;
    } else {
        if (is_elided) *is_elided = false;
    }
    *buffer = '\0';
    return 0;
}
