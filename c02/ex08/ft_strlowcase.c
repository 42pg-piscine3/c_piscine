/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 15:54:11 by joshtan           #+#    #+#             */
/*   Updated: 2026/06/30 15:59:15 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

/*
 * Returns  str
 **/
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

/**
int	main(void)
{   char *res;

    // 1. Standard Case: All uppercase
    char case1[] = "HELLO";
    printf("Test 1 (Uppercase) - Expected: hello, Got: %s\n",
            ft_strlowcase(case1));

    // 2. Mixed Case: Upper, lower, numbers, and symbols
    char case2[] = "Hello, World! 123";
    printf("Test 2 (Mixed)     - Expected: hello, world! 123, Got: %s\n",
            ft_strlowcase(case2));

    // 3. Edge Case: Already fully lowercase
    char case3[] = "already lower";
    printf("Test 3 (Lower)     - Expected: already lower, Got: %s\n",
            ft_strlowcase(case3));

    // 4. Edge Case: Empty string
    char case4[] = "";
    printf("Test 4 (Empty)     - Expected: \"\", Got: \"%s\"\n",
            ft_strlowcase(case4));

    // 5. Boundary Case: Single characters at the alphabet extremes
    char case5[] = "a z A Z";
    printf("Test 5 (Bounds)    - Expected: a z a z, Got: %s\n",
            ft_strlowcase(case5));

    // 6. Return Value Check: Ensuring it returns the exact pointer passed to it
    char case6[] = "ptr";
    char *result = ft_strlowcase(case6);
    if (result == case6)
        printf("Test 6 (Return ptr)- Expected: Match, Got: Match\n");
    else
        printf("Test 6 (Return ptr)- Expected: Match, Got: Mismatch\n");

    // 7. Null Pointer Safety Check
    // If your function does not handle NULL, comment out this test to avoid a
    // crash.
    printf("Test 7 (Null Guard)- Expected: (null), Got: %p\n",
            (void *)ft_strlowcase(NULL));

    // Test 8: Boundary Case
    res = ft_strlowcase(case5);
    printf("Addr: %s\n", (res == case5) ? "MATCH" : "MISMATCH");

    return (0);


}
**/
