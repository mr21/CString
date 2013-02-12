#include	<stdlib.h>
#include	"CString.h"

int		CString_resize(CString* s, size_t sz)
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
