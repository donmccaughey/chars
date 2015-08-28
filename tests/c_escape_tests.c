#include <chars/chars.h>

#include <errno.h>

#include "asserts.h"


static void
c_escape_char_test(void)
{
    char buffer[5];
    
    c_escape_char('\0', buffer);
    ASSERT_STR_EQ("\\000", buffer);
    
    c_escape_char('\1', buffer);
    ASSERT_STR_EQ("\\001", buffer);
    
    c_escape_char('\a', buffer);
    ASSERT_STR_EQ("\\a", buffer);
    
    c_escape_char('\b', buffer);
    ASSERT_STR_EQ("\\b", buffer);
    
    c_escape_char('\f', buffer);
    ASSERT_STR_EQ("\\f", buffer);
    
    c_escape_char('\n', buffer);
    ASSERT_STR_EQ("\\n", buffer);
    
    c_escape_char('\r', buffer);
    ASSERT_STR_EQ("\\r", buffer);
    
    c_escape_char('\t', buffer);
    ASSERT_STR_EQ("\\t", buffer);
    
    c_escape_char('\v', buffer);
    ASSERT_STR_EQ("\\v", buffer);
    
    c_escape_char('\\', buffer);
    ASSERT_STR_EQ("\\\\", buffer);
    
    c_escape_char('\37', buffer);
    ASSERT_STR_EQ("\\037", buffer);
    
    c_escape_char('"', buffer);
    ASSERT_STR_EQ("\"", buffer);
    
    c_escape_char('\'', buffer);
    ASSERT_STR_EQ("'", buffer);
    
    c_escape_char(' ', buffer);
    ASSERT_STR_EQ(" ", buffer);
}


static void
c_escape_char_for_string_literal_test(void)
{
    char buffer[5];
    
    c_escape_char_for_string_literal('\0', buffer);
    ASSERT_STR_EQ("\\000", buffer);
    
    c_escape_char_for_string_literal('\1', buffer);
    ASSERT_STR_EQ("\\001", buffer);
    
    c_escape_char_for_string_literal('\a', buffer);
    ASSERT_STR_EQ("\\a", buffer);
    
    c_escape_char_for_string_literal('\b', buffer);
    ASSERT_STR_EQ("\\b", buffer);
    
    c_escape_char_for_string_literal('\f', buffer);
    ASSERT_STR_EQ("\\f", buffer);
    
    c_escape_char_for_string_literal('\n', buffer);
    ASSERT_STR_EQ("\\n", buffer);
    
    c_escape_char_for_string_literal('\r', buffer);
    ASSERT_STR_EQ("\\r", buffer);
    
    c_escape_char_for_string_literal('\t', buffer);
    ASSERT_STR_EQ("\\t", buffer);
    
    c_escape_char_for_string_literal('\v', buffer);
    ASSERT_STR_EQ("\\v", buffer);
    
    c_escape_char_for_string_literal('\\', buffer);
    ASSERT_STR_EQ("\\\\", buffer);
    
    c_escape_char_for_string_literal('\37', buffer);
    ASSERT_STR_EQ("\\037", buffer);
    
    c_escape_char_for_string_literal('"', buffer);
    ASSERT_STR_EQ("\\\"", buffer);
    
    c_escape_char_for_string_literal(' ', buffer);
    ASSERT_STR_EQ(" ", buffer);
}


static void
c_escape_string_test(void)
{
    char const source[] = "foobar";
    char buffer[7];
    char *buffer_end = buffer + sizeof buffer;
    
    char const *actual_end = c_escape_string(source, buffer, buffer_end);
    
    char const *expected_end = source + sizeof source - 1;
    assert(expected_end == actual_end);
    assert('\0' == *actual_end);
    ASSERT_STR_EQ(source, buffer);
}


static void
c_escape_string_doesnt_write_partial_escapes_test(void)
{
    char const source[] = "\037--";
    char buffer[4];
    char *buffer_end = buffer + sizeof buffer;
    
    char const *actual_end = c_escape_string(source, buffer, buffer_end);
    
    char const *expected_end = source;
    assert(expected_end == actual_end);
    assert('\037' == *actual_end);
    ASSERT_STR_EQ("", buffer);
}


static void
c_escape_string_all_escapes_test(void)
{
    char const source[] = "\a\b\f\n\r\v\037\\";
    char buffer[40];
    char *buffer_end = buffer + sizeof buffer;
    
    char const *actual_end = c_escape_string(source, buffer, buffer_end);
    
    char const *expected_end = source + sizeof source - 1;
    assert(expected_end == actual_end);
    assert('\0' == *actual_end);
    ASSERT_STR_EQ("\\a" "\\b" "\\f" "\\n" "\\r" "\\v" "\\037" "\\\\", buffer);
}


static void
c_escape_string_quotes_test(void)
{
    char const source[] = "\"'";
    char buffer[3];
    char *buffer_end = buffer + sizeof buffer;
    
    char const *actual_end = c_escape_string(source, buffer, buffer_end);
    
    char const *expected_end = source + sizeof source - 1;
    assert(expected_end == actual_end);
    assert('\0' == *actual_end);
    ASSERT_STR_EQ(source, buffer);
}


static void
c_escape_string_for_string_literal_test(void)
{
    char const source[] = "\"foo\tbar\"";
    char buffer[13];
    char *buffer_end = buffer + sizeof buffer;
    
    char const *actual_end = c_escape_string_for_string_literal(source,
                                                                buffer,
                                                                buffer_end);
    
    char const *expected_end = source + sizeof source - 1;
    assert(expected_end == actual_end);
    assert('\0' == *actual_end);
    ASSERT_STR_EQ("\\\"" "foo" "\\t" "bar" "\\\"", buffer);
}


void
c_escape_tests(void)
{
    c_escape_char_test();
    c_escape_char_for_string_literal_test();
    
    c_escape_string_test();
    c_escape_string_doesnt_write_partial_escapes_test();
    c_escape_string_all_escapes_test();
    c_escape_string_quotes_test();
    
    c_escape_string_for_string_literal_test();
}
