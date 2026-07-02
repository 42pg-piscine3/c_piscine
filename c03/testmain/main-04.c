#include <stdio.h>
#include <string.h>

char    *ft_strstr(char *str, char *to_find);

int main(void)
{
    char *res;
    char haystack[] = "Hello World, welcome to 42!";

    // Test 1: Standard Match (Substring exists in the middle)
    res = ft_strstr(haystack, "World");
    printf("Test 1 (Standard)   - Expected: World, welcome to 42!\n");
    printf("                    - Got:      %s\n\n", res ? res : "NULL");

    // Test 2: Match at the very beginning
    res = ft_strstr(haystack, "Hello");
    printf("Test 2 (Start Match)- Expected Match Addr: YES\n");
    printf("                    - Got Pointer Match:   %s\n\n", (res == haystack) ? "PASS" : "FAIL");

    // Test 3: Match at the very end
    res = ft_strstr(haystack, "42!");
    printf("Test 3 (End Match)  - Expected: 42!\n");
    printf("                    - Got:      %s\n\n", res ? res : "NULL");

    // Test 4: Substring does not exist
    res = ft_strstr(haystack, "Goodbye");
    printf("Test 4 (No Match)   - Expected: (null), Got: %p\n\n", (void *)res);

    // Test 5: Substring is part of a longer word but mismatching
    res = ft_strstr(haystack, "welcome-to");
    printf("Test 5 (Partial)    - Expected: (null), Got: %p\n\n", (void *)res);

    // Test 6: Empty 'to_find' string (CRITICAL EDGE CASE)
    // The standard dictates it must return the intact 'str' address immediately.
    res = ft_strstr(haystack, "");
    printf("Test 6 (Empty Find) - Expected Return Addr Match: YES\n");
    printf("                    - Got Pointer Match:          %s\n\n", (res == haystack) ? "PASS" : "FAIL");

    // Test 7: Empty 'str' haystack
    char empty_haystack[] = "";
    res = ft_strstr(empty_haystack, "Hello");
    printf("Test 7 (Empty Str)  - Expected: (null), Got: %p\n\n", (void *)res);

    // Test 8: Both parameters are empty strings
    res = ft_strstr(empty_haystack, "");
    printf("Test 8 (Both Empty) - Expected Return Addr Match: YES\n");
    printf("                    - Got Pointer Match:          %s\n", (res == empty_haystack) ? "PASS" : "FAIL");

    return (0);
}

