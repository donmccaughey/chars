#include "quote.h"


bool
quote_string(char const *string,
             char const *prefix,
             char const *suffix,
             char *buffer,
             char *buffer_end)
{
    char *buffer_start = buffer;
    char const *sources[3];
    int i = 0;
    
    sources[0] = prefix;
    sources[1] = string;
    sources[2] = suffix;
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