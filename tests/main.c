#include <stdlib.h>


void
c_escape_tests(void);

void
case_convert_tests(void);

void
char_class_tests(void);

void
elide_tests(void);

void
quote_tests(void);

void
transform_tests(void);

void
uint8_convert_tests(void);

void
url_encode_tests(void);


int
main(int argc, char *argv[])
{
    c_escape_tests();
    case_convert_tests();
    char_class_tests();
    elide_tests();
    quote_tests();
    transform_tests();
    uint8_convert_tests();
    url_encode_tests();
    return EXIT_SUCCESS;
}
