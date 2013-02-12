#include	<stdlib.h>
#include	"CString.h"

CString*	CString_create_chr(char const* str)
{
  CString*	s = calloc(1, sizeof *s);

  return s ? CString_append_chr(s, str) : NULL;
}

CString*	CString_create_str(CString const* cpy)
{
  CString*	s = calloc(1, sizeof *s);

  return s ? CString_append_str(s, cpy) : NULL;
}
