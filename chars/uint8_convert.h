#ifndef CHARS_UINT8_CONVERT_H_INCLUDED
#define CHARS_UINT8_CONVERT_H_INCLUDED


#include <stdint.h>


// Convert a byte value to a two digit hex string.  The resulting string is
// placed in `hex_chars_out' and always null terminated.
void
uint8_to_hex_chars(uint8_t value, char hex_chars_out[3]);

// Convert a byte value to a three digit hex string.  The resulting string is
// placed in `octal_chars_out' and always null terminated.
void
uint8_to_octal_chars(uint8_t value, char octal_chars_out[4]);


#endif
