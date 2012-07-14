#ifndef		CSTRING_H
# define	CSTRING_H

# include	<sys/types.h>

# define	CSTRING_SIZE_START	4

typedef		struct
{
  char*		str;
  size_t	size, tab_size;
}		CString;

CString*	CString_create(char const*);
CString*	CString_copy(CString*);
char const*	CString_c_str(CString*);
size_t		CString_size(CString*);
size_t		CString_capacity(CString*);
CString*	CString_append(CString*, char const*);
CString*	CString_assign(CString*, char const*);
void		CString_clear(CString*);
void		CString_destroy(CString*);

#endif
