#include "elide.h"


static int
backup_and_replace_suffix(char *start, char *end, char const *suffix)
{
    char const *s = suffix;
    
    while (*s++) end--;
    if (end < start) return false;
    
    s = suffix;
    while (*s) *end++ = *s++;
    return true;
}


bool
elide_string(char const *s,
             char const *ellipsis,
             char *buffer,
             char *buffer_end,
             bool *is_elided)
{
    char *start = buffer;
    char *end = buffer_end - sizeof(char);
    bool result = true;
    bool elided_result = false;
    
    while (*s && buffer < end) *buffer++ = *s++;
    if (*s) {
        if (backup_and_replace_suffix(start, buffer, ellipsis)) {
            elided_result = true;
        } else {
            buffer = start;
            result = false;
        }
    }
    
    *buffer = '\0';
    if (is_elided) *is_elided = elided_result;
    return result;
}
