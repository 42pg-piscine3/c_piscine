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


	{
		char *res;

		// Test 1: Standard Case (Appending a normal string)
		// Allocate a large enough buffer to hold both strings plus the null terminator
		char dest1[50] = "Hello ";
		res = ft_strcat(dest1, "World!");
		printf("Test 1 (Standard)    - Expected Return Addr Match: YES\n");
		printf("                     - Expected Buffer: Hello World!, Got: %s\n", dest1);
		printf("                     - Return Pointer Verification: %s\n\n", (res == dest1) ? "PASS" : "FAIL");

		// Test 2: Empty Source (Appending nothing to an existing string)
		char dest2[20] = "NoChange";
		res = ft_strcat(dest2, "");
		printf("Test 2 (Empty Src)   - Expected Buffer: NoChange, Got: %s\n", dest2);
		printf("                     - Return Pointer Verification: %s\n\n", (res == dest2) ? "PASS" : "FAIL");

		// Test 3: Empty Destination (Appending a string to an empty buffer)
		char dest3[20] = "";
		res = ft_strcat(dest3, "FreshStart");
		printf("Test 3 (Empty Dest)  - Expected Buffer: FreshStart, Got: %s\n", dest3);
		printf("                     - Return Pointer Verification: %s\n\n", (res == dest3) ? "PASS" : "FAIL");

		// Test 4: Both Empty Strings
		char dest4[10] = "";
		res = ft_strcat(dest4, "");
		printf("Test 4 (Both Empty)  - Expected Buffer: \"\", Got: \"%s\"\n", dest4);
		printf("                     - Return Pointer Verification: %s\n\n", (res == dest4) ? "PASS" : "FAIL");

		// Test 5: Special Characters and Numbers
		char dest5[30] = "Count: ";
		res = ft_strcat(dest5, "1 2 3 #!");
		printf("Test 5 (Symbols)     - Expected Buffer: Count: 1 2 3 #!, Got: %s\n", dest5);
		printf("                     - Return Pointer Verification: %s\n", (res == dest5) ? "PASS" : "FAIL");

		return (0);
	}
}
