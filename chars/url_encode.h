#ifndef CHARS_URL_ENCODE_H_INCLUDED
#define CHARS_URL_ENCODE_H_INCLUDED


// URL encode a character suitable for use in a URL query string or HTML form
// post.  Generates a null terminated string in the given array.  Alphanumeric
// characters, '-', '_', '.' and '~' generate a string containing the character
// unchanged.  The space character generates a string containing a '+'.  All
// other characters generate a string containing a percent followed by the two
// digit hexadecimal value of the character.
void
url_encode_char(char unencoded, char encoded[4]);


#endif
