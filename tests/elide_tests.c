#include <chars/chars.h>

#include <errno.h>

#include "asserts.h"


static void
elide_string_when_string_fits_buffer_test(void)
{
    char string[] = "foofoofoo";
    char ellipsis[] = "...";
    char buffer[10];
    char *buffer_end = buffer + sizeof buffer;
    bool is_elided;
    
    int result = elide_string(string, ellipsis, buffer, buffer_end, &is_elided);
    
    assert(0 == result);
    ASSERT_STR_EQ(string, buffer);
    assert(!is_elided);
}


static void
elide_string_when_is_elided_is_NULL_test(void)
{
    char string[] = "foofoofoo";
    char ellipsis[] = "...";
    char buffer[10];
    char *buffer_end = buffer + sizeof buffer;
    
    int result = elide_string(string, ellipsis, buffer, buffer_end, NULL);
    
    assert(0 == result);
    ASSERT_STR_EQ(string, buffer);
}


static void
elide_string_when_string_is_too_big_test(void)
{
    char string[] = "foofoofoofoofoofoofoofoo";
    char ellipsis[] = "...";
    char buffer[10];
    char *buffer_end = buffer + sizeof buffer ;
    bool is_elided;
    
    int result = elide_string(string, ellipsis, buffer, buffer_end, &is_elided);
    
    assert(0 == result);
    ASSERT_STR_EQ("foofoo...", buffer);
    assert(is_elided);
}


static void
elide_string_when_ellipsis_is_too_big_test(void)
{
    char string[] = "foofoofoofoo";
    char ellipsis[] = "......";
    char buffer[6];
    char *buffer_end = buffer + sizeof buffer ;
    bool is_elided;
    errno = 0;
    
    int result = elide_string(string, ellipsis, buffer, buffer_end, &is_elided);
    
    assert(-1 == result);
    assert(EINVAL == errno);
    ASSERT_STR_EQ("", buffer);
}


static void
elide_string_when_ellipsis_takes_up_whole_buffer_test(void)
{
    char string[] = "foofoofoofoo";
    char ellipsis[] = "...";
    char buffer[4];
    char *buffer_end = buffer + sizeof buffer ;
    bool is_elided;
    
    int result = elide_string(string, ellipsis, buffer, buffer_end, &is_elided);
    
    assert(0 == result);
    ASSERT_STR_EQ("...", buffer);
    assert(is_elided);
}


void
elide_tests(void)
{
    elide_string_when_string_fits_buffer_test();
    elide_string_when_is_elided_is_NULL_test();
    elide_string_when_string_is_too_big_test();
    elide_string_when_ellipsis_is_too_big_test();
    elide_string_when_ellipsis_takes_up_whole_buffer_test();
}
