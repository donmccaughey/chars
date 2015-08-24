#ifndef CHARS_C_ESCAPE_H_INCLUDED
#define CHARS_C_ESCAPE_H_INCLUDED


// Escape a character using C language escape sequences.  Generates a null
// terminated string in the given array.  Control characters and backslash
// generate the corresponding C language escape sequences; all other characters
// generate a string containing the character.  Single and double quotes are
// not escaped.
void
c_escape_char(char unescaped, char escaped[5]);

// Escape a character using C language escape sequences for inclusion in a
// double quoted string.  Generates a null terminated string in the given
// array.  Control characters, double quote and backslash generate the
// corresponding C language escape sequences; all other characters generate a
// string containing the character.  The resulting string is suitable for
// inclusion in a C string literal or other double quoted string.
void
c_escape_char_for_string_literal(char unescaped, char escaped[5]);

// Escape a null terminated string using C language escape sequences.  The
// escaped string is written to the buffer given by [escaped, escaped_end).  If
// the buffer is not large enough to contain the complete escaped string, it
// will contain as many escaped character sequences as will fit.  The buffer is
// always null terminated.
//
// Control characters and backslash generate the corresponding C language
// escape sequence; all other characters are unmodified.
//
// Since the largest escape sequence is four characters long, a buffer of size
// (4 * strlen(unescaped) + 1) will guarantee that the complete escaped string
// plus null terminator will fit.
//
// If the escaped string fits completely in the buffer, the returned value
// points to the null terminator in the unescaped string.  If the buffer is not
// big enough to fit the full escaped string, the returned value points to the
// first unescaped character in the unescaped string.
char const *
c_escape_string(char const *unescaped, char *escaped, char *escaped_end);

// Escape a null terminated string using C language escape sequences for
// inclusion in a double quoted string.  The escaped string is written to the
// buffer given by [escaped, escaped_end).  If the buffer is not large enough
// to contain the complete escaped string, it will contain as many escaped
// character sequences as will fit.  The buffer is always null terminated.
//
// Control characters, backslash and double quote generate the corresponding C
// language escape sequences; all other characters are unmodfied.
//
// Since the largest escape sequence is four characters long, a buffer of size
// (4 * strlen(unescaped) + 1) will guarantee that the complete escaped string
// plus null terminator will fit.
//
// The resulting string is suitable for inclusion in a C string literal or
// other double quoted string.
//
// If the escaped string fits completely in the buffer, the returned value
// points to the null terminator in the unescaped string.  If the buffer is not
// big enough to fit the full escaped string, the returned value points to the
// first unescaped character in the unescaped string.
char const *
c_escape_string_for_string_literal(char const *unescaped,
                                   char *escaped,
                                   char *escaped_end);


#endif
