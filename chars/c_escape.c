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
add_octal_escape(char ch, char **buffer, char *buffer_end)
{
    if (buffer_end - *buffer < 4) return false;
    
    char octal_chars[4];
    uint8_to_octal_chars(ch, octal_chars);
    *(*buffer)++ = '\\';
    *(*buffer)++ = octal_chars[0];
    *(*buffer)++ = octal_chars[1];
    *(*buffer)++ = octal_chars[2];
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
            default: return add_octal_escape(ch, buffer, buffer_end);
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
c_escape_char(char ch, char buffer[5])
{
    char *buffer_end = buffer + sizeof(char[5]) - sizeof(char);
    add_c_escaped_char(ch, &buffer, buffer_end);
    *buffer = '\0';
}


void
c_escape_char_for_string_literal(char ch, char buffer[5])
{
    char *buffer_end = buffer + sizeof(char[5]) - sizeof(char);
    add_c_string_escaped_char(ch, &buffer, buffer_end);
    *buffer = '\0';
}


char const *
c_escape_string(char const *source, char *buffer, char *buffer_end)
{
    return transform_string(source, add_c_escaped_char, buffer, buffer_end);
}


char const *
c_escape_string_for_string_literal(char const *ch,
                                   char *buffer,
                                   char *buffer_end)
{
    return transform_string(ch, add_c_string_escaped_char, buffer, buffer_end);
}
