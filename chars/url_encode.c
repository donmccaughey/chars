#include "url_encode.h"

#include <stdbool.h>

#include "transform.h"
#include "uint8_convert.h"


static char *
add_percent_encoded_char(uint8_t value,
                         char *encoded,
                         char *encoded_end,
                         bool *is_full)
{
    if (encoded_end - encoded < 3) {
        *is_full = true;
    } else {
        char hex_chars[4];
        
        uint8_to_hex_chars(value, hex_chars);
        *encoded++ = '%';
        *encoded++ = hex_chars[0];
        *encoded++ = hex_chars[1];
        *is_full = false;
    }
    return encoded;
}


static char *
add_url_encoded_char(char unencoded,
                     char *encoded,
                     char *encoded_end,
                     bool *is_full)
{
    if (   (unencoded >= 'A' && unencoded <= 'Z')
        || (unencoded >= 'a' && unencoded <= 'z')
        || (unencoded >= '0' && unencoded <= '9')
        || unencoded == '-'
        || unencoded == '_'
        || unencoded == '.'
        || unencoded == '~')
    {
        return add_untransformed_char(unencoded, encoded, encoded_end, is_full);
    } else if (unencoded == ' ') {
        return add_untransformed_char('+', encoded, encoded_end, is_full);
    } else {
        return add_percent_encoded_char(unencoded,
                                        encoded,
                                        encoded_end,
                                        is_full);
    }
}


void
url_encode_char(char unencoded, char encoded[4])
{
    char *encoded_end = encoded + sizeof(char[4]) - sizeof(char);
    bool is_full;
    char *next_char = add_url_encoded_char(unencoded,
                                           encoded,
                                           encoded_end,
                                           &is_full);
    *next_char = '\0';
}


char const *
url_encode_string(char const *unencoded, char *encoded, char *encoded_end)
{
    return transform_string(unencoded,
                            add_url_encoded_char,
                            encoded,
                            encoded_end);
}
