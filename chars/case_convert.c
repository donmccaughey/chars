#include "case_convert.h"

#include <ctype.h>


char const *
upper_case_string(char const *source, char *buffer, char *buffer_end)
{
    while (*source) {
        *buffer = toupper(*source);
        ++buffer;
        if (buffer_end == buffer) break;
        ++source;
    }
    *buffer = '\0';
    return source;
}
