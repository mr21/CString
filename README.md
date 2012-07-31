CString
=======

Surcouchons nos char_étoile !  


Exemple :  

`
CString*  str;

/*                                       size / capacity - [c_str()]                    */

str = CString_create_chr("Trinity");    /*  7 / 16 - [Trinity]                          */

CString_assign_chr(str, "Thomas");      /*  6 / 16 - [Thomas]                           */
CString_append_chr(str, " TORTORINI");  /* 16 / 32 - [Thomas TORTORINI]                 */
CString_insert_chr(str, " (Mr21)", 6);  /* 23 / 32 - [Thomas (Mr21) TORTORINI]          */
CString_insert_chr(str, "I am ", 0);    /* 28 / 32 - [I am Thomas (Mr21) TORTORINI]     */
CString_insert_chr(str, " !!!", 9999);  /* 32 / 64 - [I am Thomas (Mr21) TORTORINI !!!] */
CString_clear(str);                     /*  0 / 64 - []                                 */
CString_append_chr(str, "@+");          /*  2 / 64 - [@+]                               */

CString_destroy(str);
`
