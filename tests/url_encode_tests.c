#include <chars/chars.h>

#include "asserts.h"


static void
url_encode_char_test(void)
{
    char buffer[4];
    
    url_encode_char('A', buffer);
    ASSERT_STR_EQ("A", buffer);
    
    url_encode_char('Z', buffer);
    ASSERT_STR_EQ("Z", buffer);
    
    url_encode_char('a', buffer);
    ASSERT_STR_EQ("a", buffer);
    
    url_encode_char('z', buffer);
    ASSERT_STR_EQ("z", buffer);
    
    url_encode_char('0', buffer);
    ASSERT_STR_EQ("0", buffer);
    
    url_encode_char('9', buffer);
    ASSERT_STR_EQ("9", buffer);
    
    url_encode_char('-', buffer);
    ASSERT_STR_EQ("-", buffer);
    
    url_encode_char('_', buffer);
    ASSERT_STR_EQ("_", buffer);
    
    url_encode_char('.', buffer);
    ASSERT_STR_EQ(".", buffer);
    
    url_encode_char('~', buffer);
    ASSERT_STR_EQ("~", buffer);
    
    url_encode_char(' ', buffer);
    ASSERT_STR_EQ("+", buffer);
    
    url_encode_char('/', buffer);
    ASSERT_STR_EQ("%2f", buffer);
    
    url_encode_char('?', buffer);
    ASSERT_STR_EQ("%3f", buffer);
}


static void
url_encode_string_for_safe_chars_test(void)
{
    char const source[] = "foobar";
    char buffer[7];
    char *buffer_end = buffer + sizeof buffer;
    
    char const *actual_end = url_encode_string(source, buffer, buffer_end);
    
    char const *expected_end = source + sizeof source - 1;
    assert(expected_end == actual_end);
    assert('\0' == *actual_end);
    ASSERT_STR_EQ(source, buffer);
}


static void
url_encode_string_for_unsafe_chars_test(void)
{
    char const source[] = "\t\n\r !%&+/=";
    char buffer[31];
    char *buffer_end = buffer + sizeof buffer;
    
    char const *actual_end = url_encode_string(source, buffer, buffer_end);
    
    char const *expected_end = source + sizeof source - 1;
    assert(expected_end == actual_end);
    assert('\0' == *actual_end);
    ASSERT_STR_EQ("%09" "%0a" "%0d" "+" "%21" "%25" "%26" "%2b" "%2f" "%3d", buffer);
}


static void
url_encode_string_doesnt_write_partial_escapes_test(void)
{
    char const source[] = "///";
    char buffer[9];
    char *buffer_end = buffer + sizeof buffer;
    
    char const *actual_end = url_encode_string(source, buffer, buffer_end);
    
    char const *expected_end = source + 2;
    assert(expected_end == actual_end);
    assert('/' == *actual_end);
    ASSERT_STR_EQ("%2f%2f", buffer);
}


void
url_encode_tests(void)
{
    url_encode_char_test();
    url_encode_string_for_safe_chars_test();
    url_encode_string_for_unsafe_chars_test();
    url_encode_string_doesnt_write_partial_escapes_test();
}
