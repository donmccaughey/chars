#ifndef CHARS_H_INCLUDED
#define CHARS_H_INCLUDED


#include <stdint.h>


// Convert a byte value to a two digit hex string.  The resulting string is
// placed in `hex_chars' and always null terminated.
void
uint8_to_hex_chars(uint8_t value, char hex_chars[3]);

// Convert a byte value to a three digit hex string.  The resulting string is
// placed in `octal_chars' and always null terminated.
void
uint8_to_octal_chars(uint8_t value, char octal_chars[4]);


#endif
