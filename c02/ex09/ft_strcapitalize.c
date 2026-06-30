/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <joshtan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 22:31:20 by joshtan           #+#    #+#             */
/*   Updated: 2026/07/01 01:26:07 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * To upper
 */
char	*ft_strupcase(char *str)
{
	char	*base;

	if (!str)
		return (str);
	base = str;
	while (*str)
	{
		if ('a' <= *str && *str <= 'z')
		{
			*str = *str - 32;
		}
		str++;
	}
	return (base);
}

/*
 * To lower
 */
char	*ft_strlowcase(char *str)
{
	char	*base;

	if (!str)
		return (str);
	base = str;
	while (*str)
	{
		if ('A' <= *str && *str <= 'Z')
		{
			*str = *str + 32;
		}
		str++;
	}
	return (base);
}

/*
 * Check is char is alphanumeric
 */
int	ft_check_alphanum(char *str)
{
	int	i;

	i = 0;
	if (('0' <= str[i] && str[i] <= '9')
		|| ('A' <= str[i] && str[i] <= 'Z')
		|| ('a' <= str[i] && str[i] <= 'z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/*
 * capitalizes the first letter of each word and converts all other letters to
 * lowercase.
 * A word is a sequence of alphanumeric characters.
 * It should return str.
 *
 * Word detection:
 * Check if alphanumeric: is char '0'-'9' or 'a'-'z' or 'A'-'Z'?
 *
 *	- Use flags if first alphanum char, if not first char, unset flag.
 *	- first == 1, change to upper
 *	- first == 0, change to lower
 * 1. Start condition assumes is first char.
 * 2. Next if alphanum: If first == 1, set to 0
 *		If uppercase, convert to lower case.
 * 3. Else, if !alphanum, set first to 1.
 */
char	*ft_strcapitalize(char *str)
{
	int	i;
	int	first;

	i = 0;
	first = 1;
	if (!str)
		return (str);
	while (str[i] != '\0')
	{
		if (ft_check_alphanum(&str[i]))
		{
			if (1 == first)
			{
				ft_strupcase(&str[i]);
				first = 0;
			}
			else
				ft_strlowcase(&str[i]);
		}
		else
			first = 1;
		i++;
	}
	return (str);
}

/*
 * Uncomment to test
 **
#include <stdio.h>
#include <string.h>

int main(void)
{
	char *result_ptr;

	// =========================================================================
	// Test Case 1: NULL Pointer Safety Test
	// =========================================================================
	printf("--- Test: NULL Pointer Validation ---\n");
	printf("Input Pointer: NULL\n");

	result_ptr = ft_strcapitalize(NULL);
	if (result_ptr == NULL)
	{
		printf(
		"[PASS] Function safely handled NULL pointer and returned NULL.\n\n");
	}
	else
	{
		printf(
		"[FAIL] Function did not return NULL when given a NULL pointer.\n\n");
	}

	// =========================================================================
	// Test Case 2: Subject Example Case
	// =========================================================================
	printf("--- Test: Subject Example ---\n");
	char str1[] = "hi, how are you? 42words forty-two; fifty+and+one";
	const char *exp1 = "Hi, How Are You? 42words Forty-Two; Fifty+And+One";
	printf("Before: \"%s\"\n", str1);

	result_ptr = ft_strcapitalize(str1);

	if (result_ptr != str1)
	{
		printf("[FAIL] Return pointer mismatch! Expected %p, but got %p\n",
				(void *)str1, (void *)result_ptr);
	}
	else
	{
		printf("Return Pointer: Valid (matches original parameter)\n");
	}

	if (strcmp(str1, exp1) == 0)
	{
		printf("[PASS] Result matches expected: \"%s\"\n\n", str1);
	}
	else
	{
		printf("[FAIL] Discrepancy found!\n  "
				"Expected: \"%s\"\n  Got:      \"%s\"\n\n", exp1, str1);
	}

	// =========================================================================
	// Test Case 3: Empty String
	// =========================================================================
	printf("--- Test: Empty String ---\n");
	char str2[] = "";
	const char *exp2 = "";
	printf("Before: \"%s\"\n", str2);

	result_ptr = ft_strcapitalize(str2);

	if (result_ptr != str2)
	{
		printf("[FAIL] Return pointer mismatch! Expected %p, but got %p\n",
				(void *)str2, (void *)result_ptr);
	}
	else
	{
		printf("Return Pointer: Valid (matches original parameter)\n");
	}

	if (strcmp(str2, exp2) == 0)
	{
		printf("[PASS] Result matches expected: \"%s\"\n\n", str2);
	}
	else
	{
		printf("[FAIL] Discrepancy found!\n  "
				"Expected: \"%s\"\n  Got:      \"%s\"\n\n", exp2, str2);
	}

	// =========================================================================
	// Test Case 4: All Caps Lowering
	// =========================================================================
	printf("--- Test: All Caps Lowering ---\n");
	char str3[] = "HELLO WORLD. THIS IS A TEST.";
	const char *exp3 = "Hello World. This Is A Test.";
	printf("Before: \"%s\"\n", str3);

	result_ptr = ft_strcapitalize(str3);

	if (result_ptr != str3)
	{
		printf("[FAIL] Return pointer mismatch! Expected %p, but got %p\n",
				(void *)str3, (void *)result_ptr);
	}
	else
	{
		printf("Return Pointer: Valid (matches original parameter)\n");
	}

	if (strcmp(str3, exp3) == 0)
	{
		printf("[PASS] Result matches expected: \"%s\"\n\n", str3);
	}
	else
	{
		printf("[FAIL] Discrepancy found!\n  "
				"Expected: \"%s\"\n  Got:      \"%s\"\n\n", exp3, str3);
	}

	// =========================================================================
	// Test Case 5: Alphanumeric Word Bounds
	// =========================================================================
	printf("--- Test: Alphanumeric Word Bounds ---\n");
	char str4[] = "abcdef123ghijk 42hello abc";
	const char *exp4 = "Abcdef123ghijk 42hello Abc";
	printf("Before: \"%s\"\n", str4);

	result_ptr = ft_strcapitalize(str4);

	if (result_ptr != str4)
	{
		printf("[FAIL] Return pointer mismatch! Expected %p, but got %p\n",
				(void *)str4, (void *)result_ptr);
	}
	else
	{
		printf("Return Pointer: Valid (matches original parameter)\n");
	}

	if (strcmp(str4, exp4) == 0)
	{
		printf("[PASS] Result matches expected: \"%s\"\n\n", str4);
	}
	else
	{
		printf("[FAIL] Discrepancy found!\n  "
				"Expected: \"%s\"\n  Got:      \"%s\"\n\n", exp4, str4);
	}

	return 0;
}
***/
