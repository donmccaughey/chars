#include <chars/chars.h>

#include "asserts.h"


typedef bool
is_char_fn(int ch);


static void
assert_chars_pass(is_char_fn is_char, char const chars[])
{
    for (int i = 0; chars[i]; ++i) {
        char ch = chars[i];
        assert(is_char(ch));
    }
}


static void
assert_chars_fail(is_char_fn is_char, char const chars[])
{
    for (int i = 0; chars[i]; ++i) {
        char ch = chars[i];
        assert(!is_char(ch));
    }
}


static void
is_ascii_alpha_char_test(void)
{
    assert_chars_pass(is_ascii_alpha_char, "abcdefghijklmnopqrstuvwxyz");
    assert_chars_pass(is_ascii_alpha_char, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");

    assert_chars_fail(is_ascii_alpha_char, "0123456789");
    assert_chars_fail(is_ascii_alpha_char, " .-+_*/");
}


void
is_ascii_digit_char_test(void)
{
    assert_chars_pass(is_ascii_digit_char, "0123456789");
    
    assert_chars_fail(is_ascii_digit_char, "abcdefghijklmnopqrstuvwxyz");
    assert_chars_fail(is_ascii_digit_char, " .-+_*/");
}


void
is_ascii_identifier_char_test(void)
{
    assert_chars_pass(is_ascii_identifier_char, "abcdefghijklmnopqrstuvwxyz");
    assert_chars_pass(is_ascii_identifier_char, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    assert_chars_pass(is_ascii_identifier_char, "0123456789");
    assert_chars_pass(is_ascii_identifier_char, "_");
    
    assert_chars_fail(is_ascii_digit_char, " .-+*/");
}


void
is_ascii_identifier_start_char_test(void)
{
    assert_chars_pass(is_ascii_identifier_start_char, "abcdefghijklmnopqrstuvwxyz");
    assert_chars_pass(is_ascii_identifier_start_char, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    assert_chars_pass(is_ascii_identifier_start_char, "_");
    
    assert_chars_fail(is_ascii_identifier_start_char, "0123456789");
    assert_chars_fail(is_ascii_identifier_start_char, " .-+*/");
}


void
is_url_encode_unreserved_char_test(void)
{
    assert_chars_pass(is_url_encode_unreserved_char, "abcdefghijklmnopqrstuvwxyz");
    assert_chars_pass(is_url_encode_unreserved_char, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    assert_chars_pass(is_url_encode_unreserved_char, "0123456789");
    assert_chars_pass(is_url_encode_unreserved_char, "-_.~");
    
    assert_chars_fail(is_url_encode_unreserved_char, " +*/?!");
}


void
char_class_tests(void)
{
    is_ascii_alpha_char_test();
    is_ascii_digit_char_test();
    is_ascii_identifier_char_test();
    is_ascii_identifier_start_char_test();
    is_url_encode_unreserved_char_test();
}
