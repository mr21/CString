#include	<stdlib.h>
#include	"CString.h"

void		CString_destroy(CString* s)
{
  free(s->str);
  free(s);
}
