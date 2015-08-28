#include "quote.h"

#include <errno.h>


int
quote_string(char const *source,
             char const *prefix,
             char const *suffix,
             char *buffer,
             char *buffer_end)
{
    char *buffer_start = buffer;
    char const *sources[3] = { prefix, source, suffix };
    
    int i = 0;
    while (i < 3 && buffer < buffer_end) {
        if (*sources[i]) {
            *buffer++ = *sources[i]++;
        } else {
            ++i;
        }
    }
    if (i == 3) {
        *buffer = '\0';
        return 0;
    } else {
        *buffer_start = '\0';
        errno = EINVAL;
        return -1;
    }
}
