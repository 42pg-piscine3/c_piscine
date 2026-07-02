#include <stdio.h>
#include <string.h>
#include <assert.h>

// Prototype of the function being tested

int main() {
    // ---------------------------------------------------------
    // Test 1: Normal Concatenation (Buffer has plenty of space)
    // ---------------------------------------------------------
    {
        char dest[20] = "Hello";
        const char *src = " World";
        // Expected return: initial dest len (5) + src len (6) = 11
        unsigned int ret = strlcat(dest, src, sizeof(dest));
        
        assert(ret == 11);
        assert(strcmp(dest, "Hello World") == 0);
    }

    // ---------------------------------------------------------
    // Test 2: Partial Truncation (Buffer runs out of space)
    // ---------------------------------------------------------
    {
        char dest[10] = "Hello"; // Max capacity 10 (9 chars + '\0')
        const char *src = " World"; // Needs 6 more bytes -> total 11 chars
        // Expected return: 5 + 6 = 11 (even though it's truncated)
        unsigned int ret = strlcat(dest, src, sizeof(dest));
        
        assert(ret == 11);
        // "Hello" (5) + " Wo" (2) + '\0' (1) = 8 chars used, fits in 10
        assert(strcmp(dest, "Hello Wo") == 0);
    }

    // ---------------------------------------------------------
    // Test 3: Exact Fit (Buffer fits src perfectly with NUL)
    // ---------------------------------------------------------
    {
        char dest[12] = "Hello"; 
        const char *src = " World"; // "Hello World" is 11 chars + '\0' = 12 bytes
        unsigned int ret = strlcat(dest, src, sizeof(dest));
        
        assert(ret == 11);
        assert(strcmp(dest, "Hello World") == 0);
    }

    // ---------------------------------------------------------
    // Test 4: Size is smaller than initial dest length
    // ---------------------------------------------------------
    {
        char dest[20] = "Hello";
        const char *src = " World";
        // Size passed is 3, which is less than strlen(dest) (5)
        // Expected return: size (3) + strlen(src) (6) = 9
        // dest should remain untouched
        unsigned int ret = strlcat(dest, src, 3);
        
        assert(ret == 9);
        assert(strcmp(dest, "Hello") == 0);
    }

    // ---------------------------------------------------------
    // Test 5: Size is exactly equal to initial dest length
    // ---------------------------------------------------------
    {
        char dest[20] = "Hello";
        const char *src = " World";
        // Size passed is 5, which equals strlen(dest)
        // Expected return: size (5) + strlen(src) (6) = 11
        // dest should remain untouched because there's no room for '\0'
        unsigned int ret = strlcat(dest, src, 5);
        
        assert(ret == 11);
        assert(strcmp(dest, "Hello") == 0);
    }

    // ---------------------------------------------------------
    // Test 6: Size is 0
    // ---------------------------------------------------------
    {
        char dest[20] = "Hello";
        const char *src = " World";
        // Expected return: size (0) + strlen(src) (6) = 6
        unsigned int ret = strlcat(dest, src, 0);
        
        assert(ret == 6);
        assert(strcmp(dest, "Hello") == 0);
    }

    // ---------------------------------------------------------
    // Test 7: Empty Source String
    // ---------------------------------------------------------
    {
        char dest[20] = "Hello";
        const char *src = "";
        // Expected return: strlen(dest) (5) + 0 = 5
        unsigned int ret = strlcat(dest, src, sizeof(dest));
        
        assert(ret == 5);
        assert(strcmp(dest, "Hello") == 0);
    }

    // ---------------------------------------------------------
    // Test 8: Empty Destination String
    // ---------------------------------------------------------
    {
        char dest[20] = "";
        const char *src = "World";
        // Expected return: 0 + 5 = 5
        unsigned int ret = strlcat(dest, src, sizeof(dest));
        
        assert(ret == 5);
        assert(strcmp(dest, "World") == 0);
    }

    printf("All strlcat tests passed successfully!\n");
    return 0;
}
