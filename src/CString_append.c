#include	<stdlib.h>
#include	<string.h>
#include	"CString.h"

static int	_realloc_str(CString* s, size_t sz)
{
  size_t	sz2 = s->tab_size ? s->tab_size : CSTRING_SIZE_START;
  char*		tmp;

  sz2 *= (sz + 1) / sz2 + 1;
  if (!(tmp = realloc(s->str, sz2)))
    return -1;
  s->str = tmp;
  s->tab_size = sz2;
  return 0;
}

static CString*	append(CString* s, char const* chr, size_t sz_chr)
{
  size_t	sz = s->size + sz_chr;

  if (sz >= s->tab_size && _realloc_str(s, sz))
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
