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


void
c_escape_tests(void)
{
    c_escape_char_test();
    c_escape_char_for_string_literal_test();
}
