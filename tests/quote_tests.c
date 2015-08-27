#include <chars/chars.h>

#include "asserts.h"


static void
quote_string_test(void)
{
    char const string[] = "foobar";
    char buffer[12];
    char *buffer_end = buffer + sizeof buffer;
    
    bool result = quote_string(string, "<%=", "%>", buffer, buffer_end);
    assert(result);
    ASSERT_STR_EQ("<%=foobar%>", buffer);
}


static void
quote_string_for_empty_quotes_test(void)
{
    char const string[] = "foobar";
    char buffer[7];
    char *buffer_end = buffer + sizeof buffer;
    
    bool result = quote_string(string, "", "", buffer, buffer_end);
    assert(result);
    ASSERT_STR_EQ("foobar", buffer);
}


static void
quote_string_for_buffer_too_small_test(void)
{
    char const string[] = "foobar";
    char buffer[8];
    char *buffer_end = buffer + sizeof buffer;
    
    bool result = quote_string(string, "<%=", "%>", buffer, buffer_end);
    assert(!result);
    ASSERT_STR_EQ("", buffer);
}


void
quote_tests(void)
{
    quote_string_test();
    quote_string_for_empty_quotes_test();
    quote_string_for_buffer_too_small_test();
}