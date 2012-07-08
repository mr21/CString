#include	"CString.h"

void		CString_clear(CString* s)
{
  s->str[0] = '\0';
  s->size = 0;
}
