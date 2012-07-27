#include	"CString.h"

static CString*	assign(CString* str, void const* cpy, int is_chr)
{
  size_t	tmp = str->size;

  str->size = 0;
  if (( is_chr && CString_append_chr(str, cpy)) ||
      (!is_chr && CString_append_str(str, cpy)))
    return str;
  str->size = tmp;
  return str;
}

CString*	CString_assign_chr(CString* str, char const* cpy)
{
  return assign(str, cpy, 1);
}

CString*	CString_assign_str(CString* str, CString const* cpy)
{
  return assign(str, cpy, 0);
}
