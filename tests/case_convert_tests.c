#include <chars/chars.h>

#include "asserts.h"


static void
upper_case_string_test(void)
{
    char const source[] = "fooBAR";
    char buffer[7];
    char *buffer_end = buffer + sizeof buffer;
    
    char const *actual_end = upper_case_string(source, buffer, buffer_end);
    
    char const *expected_end = source + sizeof source - 1;
    
    assert(expected_end == actual_end);
    assert('\0' == *actual_end);
    ASSERT_STR_EQ("FOOBAR", buffer);
}


void
case_convert_tests(void)
{
    upper_case_string_test();
}
