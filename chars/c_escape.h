#ifndef CHARS_C_ESCAPE_H_INCLUDED
#define CHARS_C_ESCAPE_H_INCLUDED


// Escape a character using C language escape sequences.  Generates a null
// terminated string in the given array.  Control characters and backslash
// generate the corresponding C language escape sequences; all other characters
// generate a string containing the character.  Single and double quotes are
// not escaped.
void
c_escape_char(char unescaped, char escaped_out[5]);


#endif
