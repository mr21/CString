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

CString*	CString_append(CString* s, char const* str)
{
  size_t	tmp = s->size;
  size_t	sz = tmp + strlen(str);

  if (sz >= s->tab_size && _realloc_str(s, sz))
    return NULL;
  s->size = sz;
  if (!tmp)
    s->str[0] = '\0';
  strcat(s->str, str);
  return s;
}
