#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "gotoxy.h"

int main () {
    char buf1 [ ] = "aaa", buf2 [ ] = "ccc", buf3 [ ] = "ddd";
    int res;
    res = strcmp (buf2, buf1);
    gotoxy (9,2);
    printf ("string2 es: \"%s\" y string1 es: \"%s\"", buf2, buf1);
    system("pause");
    gotoxy (9,5);
    printf ("string2 = string1 ------> res: 0\n\t");
    printf ("string2 < string1 ------> res: < 0\n\t");
    printf ("string2 > string1 ------> res: > 0\n\n\t");
    system("pause");
    if (res == 0)
        printf ("string2 es igual a string1 ------> res = %d\n\n\n\n\n\t", res);
    else if (res > 0)
        printf ("string2 es mayor que string1 ------> res = %d\n\n\n\n\n\t", res);
    else printf ("string2 es menor que string1 ------> res = %d\n\n\n\n\n\t", res);
    system("pause");
    res = strcmp (buf2, buf3);
    printf ("string2 es: \"%s\" y string3 es: \"%s\"\n\n\n\t", buf2, buf3);
    system("pause");
    printf ("string2 = string3 ------> res: 0\n\t");
    printf ("string2 < string3 ------> res: < 0\n\t");
    printf ("string2 > string3 ------> res: > 0\n\n\t");
    system("pause");
    if (res == 0)
        printf ("string2 es igual a string3 ------> res = %d\n\n\t", res);
    else if (res > 0)
        printf ("string2 es mayor que string3 ------> res = %d\n\n\t", res);
    else
        printf ("string2 es menor que string3 ------> res = %d", res);
    system("pause");
    return 0;
}
