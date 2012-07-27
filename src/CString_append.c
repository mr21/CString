#include	<string.h>
#include	"CString.h"

static CString*	append(CString* s, char const* chr, size_t sz)
{
  if (sz >= s->tab_size && CString_resize(s, sz))
    return NULL;
  (!s->size ? strcpy : strcat)(s->str, chr);
  s->size = sz;
  return s;
}

CString*	CString_append_chr(CString* s, char const* cpy)
{
  return append(s, cpy, s->size + strlen(cpy));
}

CString*	CString_append_str(CString* s, CString const* cpy)
{
  return append(s, cpy->str, s->size + cpy->size);
}
