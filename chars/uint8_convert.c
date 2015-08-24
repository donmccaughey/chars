#include "uint8_convert.h"


static char const digit_chars[] = "0123456789abcdef";


void
uint8_to_hex_chars(uint8_t value, char hex_chars[3])
{
    *hex_chars++ = digit_chars[value >> 4];
    *hex_chars++ = digit_chars[value & 0x0f];
    *hex_chars = '\0';
}


void
uint8_to_octal_chars(uint8_t value, char octal_chars[4])
{
    *octal_chars++ = digit_chars[value >> 6];
    *octal_chars++ = digit_chars[value >> 3 & 0x07];
    *octal_chars++ = digit_chars[value & 0x07];
    *octal_chars = '\0';
}
