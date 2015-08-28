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


static void
url_encode_string_for_safe_chars_test(void)
{
    char const unencoded[] = "foobar";
    char encoded[7];
    char *encoded_end = encoded + sizeof encoded;
    
    char const *actual_end = url_encode_string(unencoded, encoded, encoded_end);
    
    char const *expected_end = unencoded + sizeof unencoded - 1;
    assert(expected_end == actual_end);
    assert('\0' == *actual_end);
    ASSERT_STR_EQ(unencoded, encoded);
}


static void
url_encode_string_for_unsafe_chars_test(void)
{
    char const unencoded[] = "\t\n\r !%&+/=";
    char encoded[31];
    char *encoded_end = encoded + sizeof encoded;
    
    char const *actual_end = url_encode_string(unencoded, encoded, encoded_end);
    
    char const *expected_end = unencoded + sizeof unencoded - 1;
    assert(expected_end == actual_end);
    assert('\0' == *actual_end);
    ASSERT_STR_EQ("%09" "%0a" "%0d" "+" "%21" "%25" "%26" "%2b" "%2f" "%3d", encoded);
}


static void
url_encode_string_doesnt_write_partial_escapes_test(void)
{
    char const unencoded[] = "///";
    char encoded[9];
    char *encoded_end = encoded + sizeof encoded;
    
    char const *actual_end = url_encode_string(unencoded, encoded, encoded_end);
    
    char const *expected_end = unencoded + 2;
    assert(expected_end == actual_end);
    assert('/' == *actual_end);
    ASSERT_STR_EQ("%2f%2f", encoded);
}


void
url_encode_tests(void)
{
    url_encode_char_test();
    url_encode_string_for_safe_chars_test();
    url_encode_string_for_unsafe_chars_test();
    url_encode_string_doesnt_write_partial_escapes_test();
}
