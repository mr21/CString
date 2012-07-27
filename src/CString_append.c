#include	<string.h>
#include	"CString.h"

static CString*	append(CString* s, char const* chr, size_t sz_chr)
{
  size_t	sz = s->size + sz_chr;

  if (sz >= s->tab_size && CString_resize(s, sz))
    return NULL;
  (!s->size ? strcpy : strcat)(s->str, chr);
  s->size = sz;
  return s;
}

CString*	CString_append_chr(CString* str, char const* cpy)
{
  return append(str, cpy, strlen(cpy));
}

CString*	CString_append_str(CString* str, CString const* cpy)
{
  return append(str, cpy->str, cpy->size);
}
