#include <chars/chars.h>

#include "asserts.h"


static void
url_encode_char_test(void)
{
    char encoded[4];
    
    url_encode_char('A', encoded);
    ASSERT_STR_EQ("A", encoded);
    
    url_encode_char('Z', encoded);
    ASSERT_STR_EQ("Z", encoded);
    
    url_encode_char('a', encoded);
    ASSERT_STR_EQ("a", encoded);
    
    url_encode_char('z', encoded);
    ASSERT_STR_EQ("z", encoded);
    
    url_encode_char('0', encoded);
    ASSERT_STR_EQ("0", encoded);
    
    url_encode_char('9', encoded);
    ASSERT_STR_EQ("9", encoded);
    
    url_encode_char('-', encoded);
    ASSERT_STR_EQ("-", encoded);
    
    url_encode_char('_', encoded);
    ASSERT_STR_EQ("_", encoded);
    
    url_encode_char('.', encoded);
    ASSERT_STR_EQ(".", encoded);
    
    url_encode_char('~', encoded);
    ASSERT_STR_EQ("~", encoded);
    
    url_encode_char(' ', encoded);
    ASSERT_STR_EQ("+", encoded);
    
    url_encode_char('/', encoded);
    ASSERT_STR_EQ("%2f", encoded);
    
    url_encode_char('?', encoded);
    ASSERT_STR_EQ("%3f", encoded);
}


void
url_encode_tests(void)
{
    url_encode_char_test();
}
