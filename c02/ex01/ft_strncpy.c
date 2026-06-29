/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <joshtan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 21:14:10 by joshtan           #+#    #+#             */
/*   Updated: 2026/06/30 04:31:38 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Implement char *ft_strncpy(char *dest, char *src, unsigned int n);
 * The strncpy() function is similar, except that at most n bytes of src are
 * copied.
 * Warning: If there is no null byte among the first n bytes of src, the string
 * placed in dest will not be null-terminated.
 * If the length of src is less than n, strncpy() writes additional null bytes
 * to dest to ensure that a total of n bytes are written.
 * Returns pointer to dest string.
 */
/*
 * Tricky bits:
 * While(*src) at least guarantees a null terminated string is detect right,
 * but "n" specifies bytes to copy, which may be "n < size of src"; no null
 * detection.
 * So we need a counter < len condition to exit the loop without detecting null.
 *
 * Second condition is to fill dest with '\0' if "n > size of src".
 */
char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char			*predest;
	unsigned int	len;

	predest = dest;
	len = 0;
	while (len < n && *src)
	{
		*dest = *src;
		dest++;
		src++;
		len++;
	}
	while (len < n)
	{
		*dest = '\0';
		dest++;
		len++;
	}
	return (predest);
}

/*
 * Uncomment to Test.
 **
#include <stdio.h>
#include <string.h>
// Helper function to print exact buffer contents (including hidden \0 bytes)
void print_buffer(char *label, char *buf, int total_size)
{
	printf("%s: [", label);
	for (int i = 0; i < total_size; i++)
	{
		if (buf[i] == '\0')
			printf("\\0");
		else
			printf("%c", buf[i]);
		if (i < total_size - 1)
			printf(", ");
	}
	printf("]\n");
}

int	main(void)
{
	printf("=== RUNNING STRNCPY TESTS ===\n\n");

	// -----------------------------------------------------------------
	// TEST 1: Standard Copy (src is shorter than n, requiring null-padding)
	// -----------------------------------------------------------------
	{
		char dest_ft[10] = "XXXXXXXXX";
		char dest_std[10] = "XXXXXXXXX";
		char *src = "42";
		unsigned int n = 5;

		char *ret_ft = ft_strncpy(dest_ft, src, n);
		char *ret_std = strncpy(dest_std, src, n);

		printf("[Test 1: Padding Case (src < n)]\n");
		print_buffer("  ft_strncpy ", dest_ft, 10);
		print_buffer("  std_strncpy", dest_std, 10);
		printf("  Return Ptr Match: %s\n\n",
		(ret_ft == dest_ft) ? "✅ PASS" : "❌ FAIL");
	}

	// -----------------------------------------------------------------
	// TEST 2: Truncation Copy (src is longer than n, no null-terminator added)
	// -----------------------------------------------------------------
	{
		char dest_ft[10] = "XXXXXXXXX";
		char dest_std[10] = "XXXXXXXXX";
		char *src = "Piscine";
		unsigned int n = 4;

		char *ret_ft = ft_strncpy(dest_ft, src, n);
		char *ret_std = strncpy(dest_std, src, n);

		printf("[Test 2: Truncation Case (src > n)]\n");
		print_buffer("  ft_strncpy ", dest_ft, 10);
		print_buffer("  std_strncpy", dest_std, 10);
		printf("  Return Ptr Match: %s\n\n",
		(ret_ft == dest_ft) ? "✅ PASS" : "❌ FAIL");
	}

	// -----------------------------------------------------------------
	// TEST 3: Exact Match Copy (src length equals n)
	// -----------------------------------------------------------------
	{
		char dest_ft[10] = "XXXXXXXXX";
		char dest_std[10] = "XXXXXXXXX";
		char *src = "Hello";
		unsigned int n = 5;

		ft_strncpy(dest_ft, src, n);
		strncpy(dest_std, src, n);

		printf("[Test 3: Exact Length Match (src == n)]\n");
		print_buffer("  ft_strncpy ", dest_ft, 10);
		print_buffer("  std_strncpy", dest_std, 10);
		printf("\n");
	}

	// -----------------------------------------------------------------
	// TEST 4: Zero Length Copy (n == 0, destination must remain untouched)
	// -----------------------------------------------------------------
	{
		char dest_ft[10] = "XXXXXXXXX";
		char dest_std[10] = "XXXXXXXXX";
		char *src = "Norminette";
		unsigned int n = 0;

		ft_strncpy(dest_ft, src, n);
		strncpy(dest_std, src, n);

		printf("[Test 4: Zero Length Copy (n == 0)]\n");
		print_buffer("  ft_strncpy ", dest_ft, 10);
		print_buffer("  std_strncpy", dest_std, 10);
		printf("\n");
	}

	// -----------------------------------------------------------------
	// TEST 5: Using Compound Literal (Testing mutable memory initialization)
	// -----------------------------------------------------------------
	{
		char dest_ft[10] = "XXXXXXXXX";
		unsigned int n = 6;

		// Passing a compound literal directly to test assignment fluidity
		ft_strncpy(dest_ft, (char[]){"World"}, n);

		printf("[Test 5: Compound Literal Source Input]\n");
		print_buffer("  ft_strncpy ", dest_ft, 10);
		printf("\n");
	}

	printf("=== TESTING COMPLETE ===\n");
	return (0);
}
**/
