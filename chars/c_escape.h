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


#endif
