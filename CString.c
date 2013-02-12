#include	<string.h>
#include	"CString.h"

static CString*	append(CString* s, char const* chr, size_t sz)
{
  if (sz >= s->tab_size && CString_resize(s, sz))
    return NULL;
  (!s->size ? strcpy : strcat)(s->str, chr);
  s->size = sz;
  return s;
}

CString*	CString_append_chr(CString* s, char const* cpy)
{
  return append(s, cpy, s->size + strlen(cpy));
}

CString*	CString_append_str(CString* s, CString const* cpy)
{
  return append(s, cpy->str, s->size + cpy->size);
}
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
#include	"CString.h"

size_t		CString_capacity(CString const* s)
{
  return s->tab_size;
}
#include	"CString.h"

void		CString_clear(CString* s)
{
  s->str[0] = '\0';
  s->size = 0;
}
#include	<stdlib.h>
#include	"CString.h"

CString*	CString_create_chr(char const* str)
{
  CString*	s = calloc(1, sizeof *s);

  return s ? CString_append_chr(s, str) : NULL;
}

CString*	CString_create_str(CString const* cpy)
{
  CString*	s = calloc(1, sizeof *s);

  return s ? CString_append_str(s, cpy) : NULL;
}
#include	"CString.h"

char const*	CString_c_str(CString const* s)
{
  return s->str;
}
#include	<stdlib.h>
#include	"CString.h"

void		CString_destroy(CString* s)
{
  free(s->str);
  free(s);
}
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
#include	"CString.h"

size_t		CString_size(CString const* s)
{
  return s->size;
}
