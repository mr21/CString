#include	<stdlib.h>
#include	"CString.h"

CString*	CString_create(char const* str)
{
  CString*	s = calloc(1, sizeof *s);

  return s ? CString_append(s, str) : NULL;
}
