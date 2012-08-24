#ifndef		CSTRING_H
# define	CSTRING_H

# include	<sys/types.h>

# define	CSTRING_SIZE_START	16

typedef		struct
{
  char*		str;
  size_t	size, tab_size;
}		CString;

/* Getters */
char const*	CString_c_str(CString const*);
size_t		CString_size(CString const*);
size_t		CString_capacity(CString const*);

/* malloc & copy */
CString*	CString_create_chr(char const*);
CString*	CString_create_str(CString const*);
int		CString_resize(CString*, size_t);

/* = ; += */
CString*	CString_assign_chr(CString*, char const*);
CString*	CString_assign_str(CString*, CString const*);
CString*	CString_append_chr(CString*, char const*);
CString*	CString_append_str(CString*, CString const*);
CString*	CString_insert_chr(CString*, char const*, size_t);
CString*	CString_insert_str(CString*, CString const*, size_t);

CString*	CString_epur(CString*);

/* clean & free */
void		CString_clear(CString*);
void		CString_destroy(CString*);

#endif
