#include	"CString.h"

CString*	CString_assign(CString* s, char const* str)
{
  s->size = 0;
  return CString_append(s, str);
}
