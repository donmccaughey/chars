#ifndef CHARS_CASE_CONVERT_H_INCLUDED
#define CHARS_CASE_CONVERT_H_INCLUDED


// Convert a string to upper case.  The upper case string is written to the
// buffer given by [buffer, buffer_end).  If the buffer is not large
// enough to contain the complete upper case string, it will contain as many
// upper case characters as will fit.  The buffer is always null terminated.
// 
// If the upper case string fits completely in the buffer, the returned value
// points to the null terminator in the input string.  If the buffer is not big
// enough to fit the full upper case string, the returned value points to the
// first unconverted character in the input string.
char const *
upper_case_string(char const *string, char *buffer, char *buffer_end);


#endif
