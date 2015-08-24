#ifndef CHARS_TESTS_ASSERTS_H_INCLUDED
#define CHARS_TESTS_ASSERTS_H_INCLUDED


#include <assert.h>
#include <string.h>


#define ASSERT_STR_EQ(S1, S2) (assert(0 == strcmp((S1), (S2))))


#endif
