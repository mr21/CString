CString
=======

__Surcouchons nos *char_étoile* !__  


Exemple :  

    {
    CString*  str;
                                            /* size / capacity - [c_str()]                    */
    str = CString_create_chr("Trinity");    /*    7 / 16 - [Trinity]                          */
    
    CString_assign_chr(str, "Thomas");      /*    6 / 16 - [Thomas]                           */
    CString_append_chr(str, " TORTORINI");  /*   16 / 32 - [Thomas TORTORINI]                 */
    CString_insert_chr(str, " (Mr21)", 6);  /*   23 / 32 - [Thomas (Mr21) TORTORINI]          */
    CString_insert_chr(str, "I am ", 0);    /*   28 / 32 - [I am Thomas (Mr21) TORTORINI]     */
    CString_insert_chr(str, " !!!", 9999);  /*   32 / 64 - [I am Thomas (Mr21) TORTORINI !!!] */
    CString_clear(str);                     /*    0 / 64 - []                                 */
    CString_append_chr(str, "@+");          /*    2 / 64 - [@+]                               */
    
    CString_destroy(str);
    }

__Pourquoi trouve t-on *_chr* en préfix à chaque fonction ?__  
Pour préciser qu'il s'agit d'une chaîne de caractère en C et non d'un CString.  
*_chr* doit être remplacer par *_str* pour pouvoir passer un CString au lieu d'un simple char*.  

Deuxième exemple :  

    {
    CString*  str1;
    CString*  str2;

    str1 = CString_create_chr("Oracle");    /*    6 / 16 - [Oracle]                           */
    str2 = CString_create_str(str1);        /*    6 / 16 - [Oracle]                           */

    CString_assign_chr(str1, "Neo");        /*    3 / 16 - [Neo]                              */
    CString_append_str(str2, str1);         /*    9 / 16 - [OracleNeo]                        */
    CString_assign_chr(str1, " & ");        /*    3 / 16 - [ & ]                              */
    CString_insert_str(str2, str1, 6);      /*   12 / 16 - [Oracle & Neo]                     */

    CString_destroy(str1);
    CString_destroy(str2);
    }

Enjoy <3
Je vous aime toussa toussa
