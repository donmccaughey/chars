#include <chars/chars.h>

#include <ctype.h>
#include <errno.h>

#include "asserts.h"


static char *
add_capitalized_char(char ch, char *buffer, char *buffer_end, bool *is_full)
{
    if (buffer_end == buffer) {
        *is_full = true;
    } else {
        *buffer++ = toupper(ch);
        *is_full = false;
    }
    return buffer;
}


static void
transform_string_test(void)
{
    char const source[] = "foobar";
    char buffer[7];
    char *buffer_end = buffer + sizeof buffer;
    
    char const *actual_end = transform_string(source,
                                              add_capitalized_char,
                                              buffer,
                                              buffer_end);
    
    char const *expected_end = source + sizeof source - 1;
    assert(expected_end == actual_end);
    assert('\0' == *actual_end);
    ASSERT_STR_EQ("FOOBAR", buffer);
}


static void
transform_string_stops_at_end_of_buffer_test(void)
{
    char const source[] = "foobar";
    char buffer[5];
    char *buffer_end = buffer + sizeof buffer;
    
    char const *actual_end = transform_string(source,
                                              add_capitalized_char,
                                              buffer,
                                              buffer_end);
    
    char const *expected_end = source + sizeof source - 3;
    assert(expected_end == actual_end);
    assert('a' == *actual_end);
    ASSERT_STR_EQ("FOOB", buffer);
}


static void
transform_string_NULL_arguments_test(void)
{
    char const source[] = "foobar";
    char buffer[7];
    char *buffer_end = buffer + sizeof buffer;
    
    errno = 0;
    char const *actual_end = transform_string(NULL,
                                              add_capitalized_char,
                                              buffer,
                                              buffer_end);

    assert(NULL == actual_end);
    assert(EFAULT == errno);
    
    errno = 0;
    actual_end = transform_string(source,
                                  NULL,
                                  buffer,
                                  buffer_end);
    assert(NULL == actual_end);
    assert(EFAULT == errno);
    
    errno = 0;
    actual_end = transform_string(source,
                                  add_capitalized_char,
                                  NULL,
                                  buffer_end);
    assert(NULL == actual_end);
    assert(EFAULT == errno);

    errno = 0;
    actual_end = transform_string(source,
                                  add_capitalized_char,
                                  buffer,
                                  NULL);
    assert(NULL == actual_end);
    assert(EFAULT == errno);
}


static void
transform_string_zero_size_buffer_test(void)
{
    char const source[] = "foobar";
    char buffer[7];
    char *buffer_end = buffer;
    
    errno = 0;
    char const *actual_end = transform_string(source,
                                              add_capitalized_char,
                                              buffer,
                                              buffer_end);
    
    assert(NULL == actual_end);
    assert(EINVAL == errno);
}


void
transform_tests(void)
{
    transform_string_test();
    transform_string_stops_at_end_of_buffer_test();
    transform_string_NULL_arguments_test();
    transform_string_zero_size_buffer_test();
}
