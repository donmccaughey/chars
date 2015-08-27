#include "c_escape.h"

#include <errno.h>
#include <stdbool.h>

#include "add_char.h"
#include "uint8_convert.h"


static char *
add_named_escape(char name, char *escaped, char *escaped_end, bool *is_full)
{
    if (escaped_end - escaped < 2) {
        *is_full = true;
    } else {
        *escaped++ = '\\';
        *escaped++ = name;
        *is_full = false;
    }
    return escaped;
}


static char *
add_octal_escape(uint8_t value,
                 char *escaped,
                 char *escaped_end,
                 bool *is_full)
{
    if (escaped_end - escaped < 4) {
        *is_full = true;
    } else {
        char octal[4];
        
        uint8_to_octal_chars(value, octal);
        *escaped++ = '\\';
        *escaped++ = octal[0];
        *escaped++ = octal[1];
        *escaped++ = octal[2];
        *is_full = false;
    }
    return escaped;
}


static char *
add_c_escaped_char(char unescaped,
                   char *escaped,
                   char *escaped_end,
                   bool *is_full)
{
    if (unescaped < ' ') {
        switch (unescaped) {
            case '\a': return add_named_escape('a', escaped, escaped_end, is_full);
            case '\b': return add_named_escape('b', escaped, escaped_end, is_full);
            case '\f': return add_named_escape('f', escaped, escaped_end, is_full);
            case '\n': return add_named_escape('n', escaped, escaped_end, is_full);
            case '\r': return add_named_escape('r', escaped, escaped_end, is_full);
            case '\t': return add_named_escape('t', escaped, escaped_end, is_full);
            case '\v': return add_named_escape('v', escaped, escaped_end, is_full);
            default:
                return add_octal_escape(unescaped, escaped, escaped_end, is_full);
        }
    } else if (unescaped == '\\') {
        return add_named_escape('\\', escaped, escaped_end, is_full);
    } else {
        return add_char(unescaped, escaped, escaped_end, is_full);
    }
}


static char *
add_c_string_escaped_char(char unescaped,
                          char *escaped,
                          char *escaped_end,
                          bool *is_full)
{
    if (unescaped == '"') {
        return add_named_escape('"', escaped, escaped_end, is_full);
    } else {
        return add_c_escaped_char(unescaped, escaped, escaped_end, is_full);
    }
}


void
c_escape_char(char unescaped, char escaped[5])
{
    char *escaped_end = escaped + sizeof(char[5]) - sizeof(char);
    bool is_full;
    char *next_char = add_c_escaped_char(unescaped,
                                         escaped,
                                         escaped_end,
                                         &is_full);
    *next_char = '\0';
}


void
c_escape_char_for_string_literal(char unescaped, char escaped[5])
{
    char *escaped_end = escaped + sizeof(char[5]) - sizeof(char);
    bool is_full;
    char *next_char = add_c_string_escaped_char(unescaped,
                                                escaped,
                                                escaped_end,
                                                &is_full);
    *next_char = '\0';
}


char const *
c_escape_string(char const *unescaped, char *escaped, char *escaped_end)
{
    return transform_string(unescaped,
                            add_c_escaped_char,
                            escaped,
                            escaped_end);
}


char const *
c_escape_string_for_string_literal(char const *unescaped,
                                   char *escaped,
                                   char *escaped_end)
{
    return transform_string(unescaped,
                            add_c_string_escaped_char,
                            escaped,
                            escaped_end);
}
