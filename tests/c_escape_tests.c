#include <chars/chars.h>

#include "asserts.h"


static void
c_escape_char_test(void)
{
    char escaped[5];
    
    c_escape_char('\0', escaped);
    ASSERT_STR_EQ("\\000", escaped);
    
    c_escape_char('\1', escaped);
    ASSERT_STR_EQ("\\001", escaped);
    
    c_escape_char('\a', escaped);
    ASSERT_STR_EQ("\\a", escaped);
    
    c_escape_char('\b', escaped);
    ASSERT_STR_EQ("\\b", escaped);
    
    c_escape_char('\f', escaped);
    ASSERT_STR_EQ("\\f", escaped);
    
    c_escape_char('\n', escaped);
    ASSERT_STR_EQ("\\n", escaped);
    
    c_escape_char('\r', escaped);
    ASSERT_STR_EQ("\\r", escaped);
    
    c_escape_char('\t', escaped);
    ASSERT_STR_EQ("\\t", escaped);
    
    c_escape_char('\v', escaped);
    ASSERT_STR_EQ("\\v", escaped);
    
    c_escape_char('\\', escaped);
    ASSERT_STR_EQ("\\\\", escaped);
    
    c_escape_char('\37', escaped);
    ASSERT_STR_EQ("\\037", escaped);
    
    c_escape_char('"', escaped);
    ASSERT_STR_EQ("\"", escaped);
    
    c_escape_char('\'', escaped);
    ASSERT_STR_EQ("'", escaped);
    
    c_escape_char(' ', escaped);
    ASSERT_STR_EQ(" ", escaped);
}


static void
c_escape_char_for_string_literal_test(void)
{
    char escaped[5];
    
    c_escape_char_for_string_literal('\0', escaped);
    ASSERT_STR_EQ("\\000", escaped);
    
    c_escape_char_for_string_literal('\1', escaped);
    ASSERT_STR_EQ("\\001", escaped);
    
    c_escape_char_for_string_literal('\a', escaped);
    ASSERT_STR_EQ("\\a", escaped);
    
    c_escape_char_for_string_literal('\b', escaped);
    ASSERT_STR_EQ("\\b", escaped);
    
    c_escape_char_for_string_literal('\f', escaped);
    ASSERT_STR_EQ("\\f", escaped);
    
    c_escape_char_for_string_literal('\n', escaped);
    ASSERT_STR_EQ("\\n", escaped);
    
    c_escape_char_for_string_literal('\r', escaped);
    ASSERT_STR_EQ("\\r", escaped);
    
    c_escape_char_for_string_literal('\t', escaped);
    ASSERT_STR_EQ("\\t", escaped);
    
    c_escape_char_for_string_literal('\v', escaped);
    ASSERT_STR_EQ("\\v", escaped);
    
    c_escape_char_for_string_literal('\\', escaped);
    ASSERT_STR_EQ("\\\\", escaped);
    
    c_escape_char_for_string_literal('\37', escaped);
    ASSERT_STR_EQ("\\037", escaped);
    
    c_escape_char_for_string_literal('"', escaped);
    ASSERT_STR_EQ("\\\"", escaped);
    
    c_escape_char_for_string_literal(' ', escaped);
    ASSERT_STR_EQ(" ", escaped);
}


static void
c_escape_string_test(void)
{
    char const unescaped[] = "foobar";
    char escaped[7];
    char *escaped_end = escaped + sizeof escaped;
    
    char const *actual_end = c_escape_string(unescaped, escaped, escaped_end);
    
    char const *expected_end = unescaped + sizeof unescaped - 1;
    assert(expected_end == actual_end);
    assert('\0' == *actual_end);
    ASSERT_STR_EQ(unescaped, escaped);
}


static void
c_escape_string_stops_at_end_of_buffer_test(void)
{
    char const unescaped[] = "foobar";
    char escaped[5];
    char *escaped_end = escaped + sizeof escaped;
    
    char const *actual_end = c_escape_string(unescaped, escaped, escaped_end);
    
    char const *expected_end = unescaped + sizeof unescaped - 3;
    assert(expected_end == actual_end);
    assert('a' == *actual_end);
    ASSERT_STR_EQ("foob", escaped);
}


static void
c_escape_string_doesnt_write_partial_escapes_test(void)
{
    char const unescaped[] = "\037--";
    char escaped[4];
    char *escaped_end = escaped + sizeof escaped;
    
    char const *actual_end = c_escape_string(unescaped, escaped, escaped_end);
    
    char const *expected_end = unescaped;
    assert(expected_end == actual_end);
    assert('\037' == *actual_end);
    ASSERT_STR_EQ("", escaped);
}


static void
c_escape_string_all_escapes_test(void)
{
    char const unescaped[] = "\a\b\f\n\r\v\037\\";
    char escaped[40];
    char *escaped_end = escaped + sizeof escaped;
    
    char const *actual_end = c_escape_string(unescaped, escaped, escaped_end);
    
    char const *expected_end = unescaped + sizeof unescaped - 1;
    assert(expected_end == actual_end);
    assert('\0' == *actual_end);
    ASSERT_STR_EQ("\\a" "\\b" "\\f" "\\n" "\\r" "\\v" "\\037" "\\\\", escaped);
}


static void
c_escape_string_quotes_test(void)
{
    char const unescaped[] = "\"'";
    char escaped[3];
    char *escaped_end = escaped + sizeof escaped;
    
    char const *actual_end = c_escape_string(unescaped, escaped, escaped_end);
    
    char const *expected_end = unescaped + sizeof unescaped - 1;
    assert(expected_end == actual_end);
    assert('\0' == *actual_end);
    ASSERT_STR_EQ(unescaped, escaped);
}


static void
c_escape_string_for_string_literal_test(void)
{
    char const unescaped[] = "\"foo\tbar\"";
    char escaped[13];
    char *escaped_end = escaped + sizeof escaped;
    
    char const *actual_end = c_escape_string_for_string_literal(unescaped,
                                                                escaped,
                                                                escaped_end);
    
    char const *expected_end = unescaped + sizeof unescaped - 1;
    assert(expected_end == actual_end);
    assert('\0' == *actual_end);
    ASSERT_STR_EQ("\\\"" "foo" "\\t" "bar" "\\\"", escaped);
}


void
c_escape_tests(void)
{
    c_escape_char_test();
    c_escape_char_for_string_literal_test();
    c_escape_string_test();
    c_escape_string_stops_at_end_of_buffer_test();
    c_escape_string_doesnt_write_partial_escapes_test();
    c_escape_string_all_escapes_test();
    c_escape_string_quotes_test();
    c_escape_string_for_string_literal_test();
}
