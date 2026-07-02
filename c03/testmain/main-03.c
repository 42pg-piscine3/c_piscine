#include <stdio.h>
#include <string.h>

char *ft_strncat(char *dest, char *src, unsigned int nb);

int main(void)
{
    printf("--- Running ft_strncat Edge Case Tests ---\n\n");

    // Test 1: Standard Concatenation (nb is larger than src)
    {
        char dest[50] = "Hello ";
        char src[] = "World!";
        char *res = ft_strncat(dest, src, 10);
        printf("Test 1 (Standard):\n");
        printf("  Expected: Hello World!\n");
        printf("  Result:   %s\n", res);
        printf("  Pointer match: %s\n\n", (res == dest) ? "PASS" : "FAIL");
    }

    // Test 2: Truncation (nb is smaller than src length)
    {
        char dest[50] = " have a ";
        char src[] = "dream today";
        // Should only copy "dream " (6 characters)
        char *res = ft_strncat(dest, src, 6);
        printf("Test 2 (Truncation):\n");
        printf("  Expected:  have a dream \n");
        printf("  Result:   %s\n\n", res);
    }

    // Test 3: nb is exactly 0 (Should change nothing)
    {
        char dest[50] = "Don't change me";
        char src[] = "Extraneous text";
        char *res = ft_strncat(dest, src, 0);
        printf("Test 3 (nb = 0):\n");
        printf("  Expected: Don't change me\n");
        printf("  Result:   %s\n\n", res);
    }

    // Test 4: Empty source string
    {
        char dest[50] = "Keep it simple";
        char src[] = "";
        char *res = ft_strncat(dest, src, 5);
        printf("Test 4 (Empty src):\n");
        printf("  Expected: Keep it simple\n");
        printf("  Result:   %s\n\n", res);
    }

    // Test 5: Empty destination string
    {
        char dest[50] = "";
        char src[] = "Fresh start";
        char *res = ft_strncat(dest, src, 20);
        printf("Test 5 (Empty dest):\n");
        printf("  Expected: Fresh start\n");
        printf("  Result:   %s\n\n", res);
    }

    // Test 6: Both strings are empty
    {
        char dest[10] = "";
        char src[] = "";
        char *res = ft_strncat(dest, src, 5);
        printf("Test 6 (Both empty):\n");
        printf("  Expected: [empty string]\n");
        printf("  Result:   [%s]\n\n", res);
    }

    // Test 7: nb matches src length exactly
    {
        char dest[50] = "Exact ";
        char src[] = "Match";
        char *res = ft_strncat(dest, src, 5); // "Match" is 5 chars
        printf("Test 7 (Exact nb match):\n");
        printf("  Expected: Exact Match\n");
        printf("  Result:   %s\n\n", res);
    }

    printf("--- Tests Complete ---\n");
    return (0);
}
