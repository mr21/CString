#include	"CString.h"
#include	<stdio.h>

static void	show(CString* str)
{
  printf("%2lu / %2lu - [%s]\n",
	 CString_size(str),
	 CString_capacity(str),
	 CString_c_str(str));
}

int		main(void)
{
  {
    CString*	s;

    /*                                               size / capacity - [c_str()]                    */
    s = CString_create_chr("Trinity");   show(s); /*    7 / 16 - [Trinity]                          */
    CString_assign_chr(s, "Thomas");     show(s); /*    6 / 16 - [Thomas]                           */
    CString_append_chr(s, " TORTORINI"); show(s); /*   16 / 32 - [Thomas TORTORINI]                 */
    CString_insert_chr(s, " (Mr21)", 6); show(s); /*   23 / 32 - [Thomas (Mr21) TORTORINI]          */
    CString_insert_chr(s, "I am ", 0);   show(s); /*   28 / 32 - [I am Thomas (Mr21) TORTORINI]     */
    CString_insert_chr(s, " !!!", 9999); show(s); /*   32 / 64 - [I am Thomas (Mr21) TORTORINI !!!] */
    CString_clear(s);                    show(s); /*    0 / 64 - []                                 */
    CString_append_chr(s, "@+");         show(s); /*    2 / 64 - [@+]                               */
    CString_destroy(s);
  }
  {
    CString*  s1;
    CString*  s2;

    s1 = CString_create_chr("Oracle"); show(s1); /*    6 / 16 - [Oracle]                           */
    s2 = CString_create_str(s1);       show(s2); /*    6 / 16 - [Oracle]                           */
    CString_assign_chr(s1, "Neo");     show(s1); /*    3 / 16 - [Neo]                              */
    CString_append_str(s2, s1);        show(s2); /*    9 / 16 - [OracleNeo]                        */
    CString_assign_chr(s1, " & ");     show(s1); /*    3 / 16 - [ & ]                              */
    CString_insert_str(s2, s1, 6);     show(s2); /*   12 / 16 - [Oracle & Neo]                     */
    CString_destroy(s1);
    CString_destroy(s2);
  }
  return 0;
}
