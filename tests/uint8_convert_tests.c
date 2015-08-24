#include <chars/chars.h>

#include "asserts.h"


static void
uint8_to_hex_chars_test(void)
{
    char hex[3];
    
    uint8_to_hex_chars(0, hex);
    ASSERT_STR_EQ("00", hex);
    
    uint8_to_hex_chars(1, hex);
    ASSERT_STR_EQ("01", hex);
    
    uint8_to_hex_chars(10, hex);
    ASSERT_STR_EQ("0a", hex);
    
    uint8_to_hex_chars(15, hex);
    ASSERT_STR_EQ("0f", hex);
    
    uint8_to_hex_chars(16, hex);
    ASSERT_STR_EQ("10", hex);
    
    uint8_to_hex_chars(255, hex);
    ASSERT_STR_EQ("ff", hex);
}


static void
uint8_to_octal_chars_test(void)
{
    char octal[4];
    
    uint8_to_octal_chars(0, octal);
    ASSERT_STR_EQ("000", octal);
    
    uint8_to_octal_chars(1, octal);
    ASSERT_STR_EQ("001", octal);
    
    uint8_to_octal_chars(7, octal);
    ASSERT_STR_EQ("007", octal);
    
    uint8_to_octal_chars(8, octal);
    ASSERT_STR_EQ("010", octal);
    
    uint8_to_octal_chars(63, octal);
    ASSERT_STR_EQ("077", octal);
    
    uint8_to_octal_chars(255, octal);
    ASSERT_STR_EQ("377", octal);
}


void
uint8_convert_tests(void)
{
    uint8_to_hex_chars_test();
    uint8_to_octal_chars_test();
}
