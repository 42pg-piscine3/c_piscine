#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/* Function Prototype */
char	*ft_itoa(int n);

int	main(void)
{
	struct test_case {
		int			input;
		const char	*expected;
	};

	struct test_case	tests[] = {
		{0, "0"},
		{5, "5"},
		{-5, "-5"},
		{42, "42"},
		{-42, "-42"},
		{1003, "1003"},
		{-1003, "-1003"},
		{INT_MAX, "2147483647"},
		{INT_MIN, "-2147483648"}
	};

	int		num_tests = sizeof(tests) / sizeof(tests[0]);
	int		i = 0;
	char	*result;

	printf("=== Testing ft_itoa ===\n\n");

	while (i < num_tests)
	{
		printf("Test %d: Input = %d\n", i + 1, tests[i].input);
		
		result = ft_itoa(tests[i].input);
		
		/* Verify memory was successfully allocated */
		if (result == NULL)
		{
			printf("  [FAIL]: Function returned NULL (Allocation Failure)\n\n");
			i++;
			continue;
		}

		/* Validate string conversion content */
		if (strcmp(result, tests[i].expected) == 0)
		{
			printf("  [PASS]: Expected \"%s\", Got \"%s\"\n", tests[i].expected, result);
		}
		else
		{
			printf("  [FAIL]: Expected \"%s\", Got \"%s\"\n", tests[i].expected, result);
		}

		/* Free the heap memory allocated by ft_itoa */
		free(result);
		printf("\n");
		i++;
	}

	return (0);
}
