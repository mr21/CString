#include	"CString.h"

size_t		CString_capacity(CString const* s)
{
  return s->tab_size;
}
