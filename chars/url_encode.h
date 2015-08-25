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


// URL encode a null terminated string suitable for use in a URL query string
// or HTML form post.
//
// The encoded string is written to the buffer given by [encoded, encoded_end).
// If the buffer is not large enough to contain the complete encoded string, it
// will contain as many encoded character sequences as will fit.  The buffer
// is always null terminated.
//
// Alphanumeric characters, '-', '_', '.' and '~' generate a string containing
// the character unchanged.  The space character generates a string containing
// a '+'.  All other characters generate a string containing a percent followed
// by the two digit hexadecimal value of the character.
//
// Since the largest URL encoded sequence is three characters long, a buffer of
// size (3 * strlen(unescaped) + 1) will guarantee that the complete URL
// encoded string plus null terminator will fit.
//
// If the URL encoded string fits completely in the buffer, the returned value
// points to the null terminator in the unencoded string.  If the buffer is not
// big enough to fit the full URL encoded string, the returned value points to
// the first unencoded character in the unencoded string.
char const *
url_encode_string(char const *unencoded, char *encoded, char *encoded_end);


#endif
