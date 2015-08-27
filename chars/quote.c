#include "quote.h"


bool
quote_string(char const *string,
             char const *prefix,
             char const *suffix,
             char *buffer,
             char *buffer_end)
{
    char *buffer_start = buffer;
    char const *sources[3] = { prefix, string, suffix };
    
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
        return true;
    } else {
        *buffer_start = '\0';
        return false;
    }
}
