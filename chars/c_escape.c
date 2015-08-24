#include "c_escape.h"

#include <stdbool.h>

#include "uint8_convert.h"


static char *
add_char(char ch,
         char *buffer,
         char *buffer_end,
         bool *is_full_out)
{
    if (buffer_end == buffer) {
        *is_full_out = true;
    } else {
        *buffer++ = ch;
        *is_full_out = false;
    }
    return buffer;
}


static char *
add_named_escape(char name,
                 char *escaped,
                 char *escaped_end,
                 bool *is_full_out)
{
    if (escaped_end - escaped < 2) {
        *is_full_out = true;
    } else {
        *escaped++ = '\\';
        *escaped++ = name;
        *is_full_out = false;
    }
    return escaped;
}


static char *
add_octal_escape(uint8_t value,
                 char *escaped,
                 char *escaped_end,
                 bool *is_full_out)
{
    if (escaped_end - escaped < 4) {
        *is_full_out = true;
    } else {
        char octal[4];
        
        uint8_to_octal_chars(value, octal);
        *escaped++ = '\\';
        *escaped++ = octal[0];
        *escaped++ = octal[1];
        *escaped++ = octal[2];
        *is_full_out = false;
    }
    return escaped;
}


static char *
add_c_escaped_char(char unescaped,
                   char *escaped,
                   char *escaped_end,
                   bool *is_full_out)
{
    if (unescaped < ' ') {
        switch (unescaped) {
            case '\a': return add_named_escape('a', escaped, escaped_end, is_full_out);
            case '\b': return add_named_escape('b', escaped, escaped_end, is_full_out);
            case '\f': return add_named_escape('f', escaped, escaped_end, is_full_out);
            case '\n': return add_named_escape('n', escaped, escaped_end, is_full_out);
            case '\r': return add_named_escape('r', escaped, escaped_end, is_full_out);
            case '\t': return add_named_escape('t', escaped, escaped_end, is_full_out);
            case '\v': return add_named_escape('v', escaped, escaped_end, is_full_out);
            default:
                return add_octal_escape(unescaped, escaped, escaped_end, is_full_out);
        }
    } else if (unescaped == '\\') {
        return add_named_escape('\\', escaped, escaped_end, is_full_out);
    } else {
        return add_char(unescaped, escaped, escaped_end, is_full_out);
    }
}


void
c_escape_char(char unescaped, char escaped_out[5])
{
    bool is_full;
    char *escaped_end = escaped_out + sizeof(char[5]) - sizeof(char);
    char *next_ch = add_c_escaped_char(unescaped, escaped_out, escaped_end, &is_full);
    *next_ch = '\0';
}
