#include "c_escape.h"

#include <errno.h>
#include <stdbool.h>

#include "transform.h"
#include "uint8_convert.h"


static bool
add_named_escape(char ch, char **buffer, char *buffer_end)
{
    if (buffer_end - *buffer < 2) return false;
    
    *(*buffer)++ = '\\';
    *(*buffer)++ = ch;
    return true;
}


static bool
add_octal_escape(uint8_t value, char **buffer, char *buffer_end)
{
    if (buffer_end - *buffer < 4) return false;
    
    char octal[4];
    uint8_to_octal_chars(value, octal);
    *(*buffer)++ = '\\';
    *(*buffer)++ = octal[0];
    *(*buffer)++ = octal[1];
    *(*buffer)++ = octal[2];
    return true;
}


static bool
add_c_escaped_char(char ch, char **buffer, char *buffer_end)
{
    if (ch < ' ') {
        switch (ch) {
            case '\a': return add_named_escape('a', buffer, buffer_end);
            case '\b': return add_named_escape('b', buffer, buffer_end);
            case '\f': return add_named_escape('f', buffer, buffer_end);
            case '\n': return add_named_escape('n', buffer, buffer_end);
            case '\r': return add_named_escape('r', buffer, buffer_end);
            case '\t': return add_named_escape('t', buffer, buffer_end);
            case '\v': return add_named_escape('v', buffer, buffer_end);
            default:
                return add_octal_escape(ch, buffer, buffer_end);
        }
    } else if (ch == '\\') {
        return add_named_escape('\\', buffer, buffer_end);
    } else {
        return add_untransformed_char(ch, buffer, buffer_end);
    }
}


static bool
add_c_string_escaped_char(char ch, char **buffer, char *buffer_end)
{
    if (ch == '"') {
        return add_named_escape('"', buffer, buffer_end);
    } else {
        return add_c_escaped_char(ch, buffer, buffer_end);
    }
}


void
c_escape_char(char unescaped, char escaped[5])
{
    char *buffer = escaped;
    char *buffer_end = escaped + sizeof(char[5]) - sizeof(char);
    add_c_escaped_char(unescaped, &buffer, buffer_end);
    *buffer = '\0';
}


void
c_escape_char_for_string_literal(char unescaped, char escaped[5])
{
    char *buffer = escaped;
    char *buffer_end = escaped + sizeof(char[5]) - sizeof(char);
    add_c_string_escaped_char(unescaped, &buffer, buffer_end);
    *buffer = '\0';
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
