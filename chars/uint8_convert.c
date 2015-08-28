#include "uint8_convert.h"


static char const digit_chars[] = "0123456789abcdef";


void
uint8_to_hex_chars(uint8_t value, char buffer[3])
{
    *buffer++ = digit_chars[value >> 4];
    *buffer++ = digit_chars[value & 0x0f];
    *buffer = '\0';
}


void
uint8_to_octal_chars(uint8_t value, char buffer[4])
{
    *buffer++ = digit_chars[value >> 6];
    *buffer++ = digit_chars[value >> 3 & 0x07];
    *buffer++ = digit_chars[value & 0x07];
    *buffer = '\0';
}
