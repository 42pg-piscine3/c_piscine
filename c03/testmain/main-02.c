#include <stdio.h>
#include <string.h>

char    *ft_strcat(char *dest, char *src);

int     main(void)
{
    char    dest[50];
    char    *ret;

    // basic concatenation
    strcpy(dest, "hello");
    ft_strcat(dest, " world");
    printf("[%s] basic concatenation\n", strcmp(dest, "hello world") == 0 ? "PASS" : "FAIL");
    printf("found: \"%s\"\n", dest);

    // return value must be dest
    strcpy(dest, "hello");
    ret = ft_strcat(dest, " world");
    printf("[%s] return value is dest\n", ret == dest ? "PASS" : "FAIL");

    // src empty → dest unchanged
    strcpy(dest, "hello");
    ft_strcat(dest, "");
    printf("[%s] empty src leaves dest unchanged\n", strcmp(dest, "hello") == 0 ? "PASS" : "FAIL");

    // dest empty → result equals src
    strcpy(dest, "");
    ft_strcat(dest, "world");
    printf("[%s] empty dest → result equals src\n", strcmp(dest, "world") == 0 ? "PASS" : "FAIL");

    // both empty
    strcpy(dest, "");
    ft_strcat(dest, "");
    printf("[%s] both empty\n", strcmp(dest, "") == 0 ? "PASS" : "FAIL");

    // appending twice
    strcpy(dest, "a");
    ft_strcat(dest, "b");
    ft_strcat(dest, "c");
    printf("[%s] chained appends\n", strcmp(dest, "abc") == 0 ? "PASS" : "FAIL");

    // no extra characters after concat
    strcpy(dest, "foo");
    ft_strcat(dest, "bar");
    printf("[%s] null terminator in right place\n", dest[6] == '\0' ? "PASS" : "FAIL");

    return (0);
}
