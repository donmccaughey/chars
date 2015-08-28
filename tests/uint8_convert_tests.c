#include <chars/chars.h>

#include "asserts.h"


static void
uint8_to_hex_chars_test(void)
{
    char buffer[3];
    
    uint8_to_hex_chars(0, buffer);
    ASSERT_STR_EQ("00", buffer);
    
    uint8_to_hex_chars(1, buffer);
    ASSERT_STR_EQ("01", buffer);
    
    uint8_to_hex_chars(10, buffer);
    ASSERT_STR_EQ("0a", buffer);
    
    uint8_to_hex_chars(15, buffer);
    ASSERT_STR_EQ("0f", buffer);
    
    uint8_to_hex_chars(16, buffer);
    ASSERT_STR_EQ("10", buffer);
    
    uint8_to_hex_chars(255, buffer);
    ASSERT_STR_EQ("ff", buffer);
}


static void
uint8_to_octal_chars_test(void)
{
    char buffer[4];
    
    uint8_to_octal_chars(0, buffer);
    ASSERT_STR_EQ("000", buffer);
    
    uint8_to_octal_chars(1, buffer);
    ASSERT_STR_EQ("001", buffer);
    
    uint8_to_octal_chars(7, buffer);
    ASSERT_STR_EQ("007", buffer);
    
    uint8_to_octal_chars(8, buffer);
    ASSERT_STR_EQ("010", buffer);
    
    uint8_to_octal_chars(63, buffer);
    ASSERT_STR_EQ("077", buffer);
    
    uint8_to_octal_chars(255, buffer);
    ASSERT_STR_EQ("377", buffer);
}


void
uint8_convert_tests(void)
{
    uint8_to_hex_chars_test();
    uint8_to_octal_chars_test();
}
