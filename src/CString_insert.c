#include	<string.h>
#include	"CString.h"

static CString*	insert(CString* s, char const* cpy, size_t sz, size_t n)
{
  size_t	new_sz = s->size + sz;

  if (new_sz >= s->tab_size && CString_resize(s, new_sz))
    return NULL;
  memmove(s->str + n + sz, s->str + n, s->size + 1 - n);
  strncpy(s->str + n, cpy, sz);
  s->size = new_sz;
  return s;
}

CString*	CString_insert_chr(CString* s, char const* cpy, size_t n)
{
  return n < s->size ? insert(s, cpy, strlen(cpy), n) :
    CString_append_chr(s, cpy);
    
}

CString*	CString_insert_str(CString* s, CString const* cpy, size_t n)
{
  return n < s->size ? insert(s, cpy->str, cpy->size, n) :
    CString_append_str(s, cpy);
}
