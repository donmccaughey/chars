#include <stdlib.h>


void
c_escape_tests(void);

void
elide_tests(void);

void
uint8_convert_tests(void);


int
main(int argc, char *argv[])
{
    c_escape_tests();
    elide_tests();
    uint8_convert_tests();
    return EXIT_SUCCESS;
}
