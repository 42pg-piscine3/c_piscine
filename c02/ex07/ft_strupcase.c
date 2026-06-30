/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 14:50:41 by joshtan           #+#    #+#             */
/*   Updated: 2026/06/30 15:50:54 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

/*
 * Returns  str
 **/
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

/**
int	main(void)
{
	char *res;

	// 1. Standard Case: All lowercase
    char case1[] = "hello";
    printf("Test 1 (Lowercase) - Expected: HELLO, Got: %s\n",
			ft_strupcase(case1));

    // 2. Mixed Case: Upper, lower, numbers, and symbols
    char case2[] = "Hello, World! 123";
    printf("Test 2 (Mixed)     - Expected: HELLO, WORLD! 123, Got: %s\n",
			ft_strupcase(case2));

    // 3. Edge Case: Already fully uppercase
    char case3[] = "ALREADY UPPER";
    printf("Test 3 (Upper)     - Expected: ALREADY UPPER, Got: %s\n",
			ft_strupcase(case3));

    // 4. Edge Case: Empty string
    char case4[] = "";
    printf("Test 4 (Empty)     - Expected: \"\", Got: \"%s\"\n",
			ft_strupcase(case4));

    // 5. Boundary Case: Single characters at the alphabet extremes
    char case5[] = "a z A Z";
    printf("Test 5 (Bounds)    - Expected: A Z A Z, Got: %s\n",
			ft_strupcase(case5));

    // 6. Return Value Check: Ensuring it returns the exact pointer passed to it
    char case6[] = "ptr";
    char *result = ft_strupcase(case6);
    if (result == case6)
        printf("Test 6 (Return ptr)- Expected: Match, Got: Match\n");
    else
        printf("Test 6 (Return ptr)- Expected: Match, Got: Mismatch\n");

    // 7. Null Pointer Safety Check
    // If your function does not handle NULL, comment out this test to avoid a 
	// crash.
    printf("Test 7 (Null Guard)- Expected: (null), Got: %p\n",
			(void *)ft_strupcase(NULL));

    // Test 8: Boundary Case
    res = ft_strupcase(case5);
    printf("Addr: %s\n", (res == case5) ? "MATCH" : "MISMATCH");

    return (0);
}
**/
