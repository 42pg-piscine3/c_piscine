#include <stdio.h>
#include <string.h>

char    *ft_strncat(char *dest, char *src, int n);

int     main(void)
{
    char    dest[50];
    char    *ret;

    // basic concatenation within n
    strcpy(dest, "hello");
    ft_strncat(dest, " world", 6);
    printf("[%s] basic concatenation\n", strcmp(dest, "hello world") == 0 ? "PASS" : "FAIL");

    // return value must be dest
    strcpy(dest, "hello");
    ret = ft_strncat(dest, " world", 6);
    printf("[%s] return value is dest\n", ret == dest ? "PASS" : "FAIL");

    // n = 0 → dest unchanged
    strcpy(dest, "hello");
    ft_strncat(dest, "world", 0);
    printf("[%s] n=0 leaves dest unchanged\n", strcmp(dest, "hello") == 0 ? "PASS" : "FAIL");

    // n smaller than src → only n chars appended
    strcpy(dest, "hello");
    ft_strncat(dest, " world", 3);
    printf("[%s] n < strlen(src) appends only n chars\n", strcmp(dest, "hello wo") == 0 ? "PASS" : "FAIL");

    // n larger than src → full src appended, no garbage
    strcpy(dest, "hello");
    ft_strncat(dest, " world", 20);
    printf("[%s] n > strlen(src) appends full src\n", strcmp(dest, "hello world") == 0 ? "PASS" : "FAIL");

    // result always null terminated
    strcpy(dest, "hello");
    ft_strncat(dest, " world", 3);
    printf("[%s] result is null terminated\n", dest[8] == '\0' ? "PASS" : "FAIL");

    // empty src → dest unchanged
    strcpy(dest, "hello");
    ft_strncat(dest, "", 5);
    printf("[%s] empty src leaves dest unchanged\n", strcmp(dest, "hello") == 0 ? "PASS" : "FAIL");

    // empty dest → result equals first n chars of src
    strcpy(dest, "");
    ft_strncat(dest, "world", 3);
    printf("[%s] empty dest appends n chars of src\n", strcmp(dest, "wor") == 0 ? "PASS" : "FAIL");

    // both empty
    strcpy(dest, "");
    ft_strncat(dest, "", 5);
    printf("[%s] both empty\n", strcmp(dest, "") == 0 ? "PASS" : "FAIL");

    return (0);
}
