/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 10:03:38 by joshtan           #+#    #+#             */
/*   Updated: 2026/07/01 11:03:26 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Tricky:
 * 1.  what if size is less than src -> what to return?
 * Manual says return the size of string it tried to copy
 * 2. What if size is 0.
 * 3. All copy have to allow '\0' in the last element of dest.
 */
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	idx;
	int				len;

	if ((!dest) && (!src))
		return (0);
	idx = 0;
	len = 0;
	while (src[len] != '\0')
		len++;
	if (size > 0)
	{
		while (src[idx] != '\0' && idx < size - 1)
		{
			dest[idx] = src[idx];
			idx++;
		}
		dest[idx] = '\0';
	}
	return (len);
}

/*
 **
#include <stdio.h>
#include <string.h>

int main(void)
{
	size_t  ret;

	// Test 1: Full Copy (Destination buffer is larger than source string)
	char dest1[10] = "XXXXXXXXX"; 
	ret = ft_strlcpy(dest1, "Hello", 10);
	printf("Test 1 (Full Copy) - Expected Return: 5, Got: %zu\n", ret);
	printf("                   - Expected Buffer: Hello, Got: %s\n\n", dest1);

	// Test 2: Truncation Case (Destination buffer is smaller than source string)
	char dest2[4] = "XXX";
	ret = ft_strlcpy(dest2, "Hello", 4);
	printf("Test 2 (Truncation)- Expected Return: 5, Got: %zu\n", ret);
	printf("                   - Expected Buffer: Hel, Got: %s\n\n", dest2);

	// Test 3: Edge Case (Size is exactly 1, should only place a NUL terminator)
	char dest3[5] = "XXXX";
	ret = ft_strlcpy(dest3, "Hello", 1);
	printf("Test 4 (Size == 1) - Expected Return: 5, Got: %zu\n", ret);
	printf("                   - Expected Buffer: \"\", Got: \"%s\"\n\n", dest3);

	// Test 4: Edge Case (Size is 0, should write absolutely nothing to buffer)
	char dest4[5] = "XXXX"; // Last 'X' is index 3, dest4[4] is '\0'
	ret = ft_strlcpy(dest4, "Hello", 0);
	printf("Test 3 (Size == 0) - Expected Return: 5, Got: %zu\n", ret);
	printf("                   - Expected Buffer: XXXX, Got: %s\n\n", dest4);

	// Test 5: Empty Source String
	char dest5[5] = "XXXX";
	ret = ft_strlcpy(dest5, "", 5);
	printf("Test 5 (Empty Src) - Expected Return: 0, Got: %zu\n", ret);
	printf("                   - Expected Buffer: \"\", Got: \"%s\"\n", dest5);

	return (0);
}
***/
