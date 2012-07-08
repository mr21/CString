#include	<stdlib.h>
#include	<string.h>
#include	"CString.h"

CString*	CString_copy(CString* src)
{
  CString*	s = malloc(sizeof *s);

  if (!s)
    return NULL;
  if (!(s->str = malloc(src->tab_size)))
    {
      free(s);
      return NULL;
    }
  s->size = src->size;
  s->tab_size = src->tab_size;
  strncpy(s->str, src->str, s->size + 1);
  return s;
}
