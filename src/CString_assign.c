#include	"CString.h"

CString*	CString_assign_chr(CString* str, char const* cpy)
{
  str->size = 0;
  return CString_append_chr(str, cpy);
}

CString*	CString_assign_str(CString* str, CString const* cpy)
{
  str->size = 0;
  return CString_append_str(str, cpy);
}
