#include "url_encode.h"

#include <stdbool.h>

#include "char_class.h"
#include "transform.h"
#include "uint8_convert.h"


static bool
add_percent_encoded_char(uint8_t char_value, char **buffer, char *buffer_end)
{
    if (buffer_end - *buffer < 3) return false;
    
    char hex_chars[4];
    uint8_to_hex_chars(char_value, hex_chars);
    *(*buffer)++ = '%';
    *(*buffer)++ = hex_chars[0];
    *(*buffer)++ = hex_chars[1];
    return true;
}


static bool
add_url_encoded_char(char ch, char **buffer, char *buffer_end)
{
    if (is_url_encode_unreserved_char(ch)) {
        return add_untransformed_char(ch, buffer, buffer_end);
    } else if (ch == ' ') {
        return add_untransformed_char('+', buffer, buffer_end);
    } else {
        return add_percent_encoded_char(ch, buffer, buffer_end);
    }
}


void
url_encode_char(char ch, char buffer[4])
{
    char *buffer_end = buffer + sizeof(char[4]) - sizeof(char);
    add_url_encoded_char(ch, &buffer, buffer_end);
    *buffer = '\0';
}


char const *
url_encode_string(char const *source, char *buffer, char *buffer_end)
{
    return transform_string(source,
                            add_url_encoded_char,
                            buffer,
                            buffer_end);
}
