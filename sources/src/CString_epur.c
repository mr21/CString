#include	"CString.h"

static int	nospace(char c)
{
  return c && c != ' ' && c != '\t';
}

CString*	CString_epur(CString* str)
{
  char*		s = str->str;
  size_t	u, n = 0;

  for (u = 0; s[u]; ++u)
    if (nospace(s[u]))
      s[n] = s[u], ++n;
    else if (n && nospace(s[n - 1]) && nospace(s[u + 1]))
      s[n] = ' ', ++n;
  s[n] = '\0';
  str->size = n;
  return str;
}
