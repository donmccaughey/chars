#include "case_convert.h"

#include <ctype.h>


char const *
upper_case_string(char const *string, char *buffer, char *buffer_end)
{
    while (*string) {
        *buffer = toupper(*string);
        ++buffer;
        if (buffer_end == buffer) break;
        ++string;
    }
    *buffer = '\0';
    return string;
}
