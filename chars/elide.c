#include "elide.h"


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
elide_string(char const *string,
             char const *ellipsis,
             char *buffer,
             char *buffer_end,
             bool *is_elided)
{
    char *buffer_start = buffer;
    buffer_end -= sizeof(char);
    while (*string && buffer < buffer_end) *buffer++ = *string++;
    if (*string) {
        if (!backup_and_replace_suffix(buffer_start, buffer, ellipsis)) {
            *buffer_start = '\0';
            return -1;
        }
        if (is_elided) *is_elided = true;
    } else {
        if (is_elided) *is_elided = false;
    }
    *buffer = '\0';
    return 0;
}
