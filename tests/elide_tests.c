#include <chars/chars.h>

#include "asserts.h"


static void
elide_string_when_string_fits_buffer_test(void)
{
    char s[] = "foofoofoo";
    char ellipsis[] = "...";
    char buffer[10];
    char *buffer_end = buffer + sizeof(buffer);
    bool is_elided;
    
    bool result = elide_string(s, ellipsis, buffer, buffer_end, &is_elided);
    
    assert(result);
    ASSERT_STR_EQ(s, buffer);
    assert(!is_elided);
}


static void
elide_string_when_is_elided_is_NULL_test(void)
{
    char s[] = "foofoofoo";
    char ellipsis[] = "...";
    char buffer[10];
    char *buffer_end = buffer + sizeof(buffer);
    
    bool result = elide_string(s, ellipsis, buffer, buffer_end, NULL);
    
    assert(result);
    ASSERT_STR_EQ(s, buffer);
}


static void
elide_string_when_string_is_too_big_test(void)
{
    char s[] = "foofoofoofoofoofoofoofoo";
    char ellipsis[] = "...";
    char buffer[10];
    char *buffer_end = buffer + sizeof(buffer);
    bool is_elided;
    
    bool result = elide_string(s, ellipsis, buffer, buffer_end, &is_elided);
    
    assert(result);
    ASSERT_STR_EQ("foofoo...", buffer);
    assert(is_elided);
}


static void
elide_string_when_ellipsis_is_too_big_test(void)
{
    char s[] = "foofoofoofoo";
    char ellipsis[] = "......";
    char buffer[6];
    char *buffer_end = buffer + sizeof(buffer);
    bool elided;
    
    bool result = elide_string(s, ellipsis, buffer, buffer_end, &elided);
    
    assert(!result);
    ASSERT_STR_EQ("", buffer);
    assert(!elided);
}


static void
elide_string_when_ellipsis_takes_up_whole_buffer_test(void)
{
    char s[] = "foofoofoofoo";
    char ellipsis[] = "...";
    char buffer[4];
    char *buffer_end = buffer + sizeof(buffer);
    bool elided;
    
    bool result = elide_string(s, ellipsis, buffer, buffer_end, &elided);
    
    assert(result);
    ASSERT_STR_EQ("...", buffer);
    assert(elided);
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
