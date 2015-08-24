#include "add_char.h"


char *
add_char(char ch, char *buffer, char *buffer_end, bool *is_full)
{
    if (buffer_end == buffer) {
        *is_full = true;
    } else {
        *buffer++ = ch;
        *is_full = false;
    }
    return buffer;
}
