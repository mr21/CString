#include	<string.h>
#include	"CString.h"

static CString*	assign(CString* s, char const* cpy, size_t sz)
{
  if (sz >= s->tab_size && CString_resize(s, sz))
    return NULL;
  strcpy(s->str, cpy);
  s->size = sz;
  return s;
}

CString*	CString_assign_chr(CString* s, char const* cpy)
{
  return assign(s, cpy, strlen(cpy));
}

CString*	CString_assign_str(CString* s, CString const* cpy)
{
  return assign(s, cpy->str, cpy->size);
}
