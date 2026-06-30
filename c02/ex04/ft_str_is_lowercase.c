/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 10:16:35 by joshtan           #+#    #+#             */
/*   Updated: 2026/06/30 14:05:44 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	flag;

	flag = 1;
	if (!*str)
		return (flag);
	while (*str)
	{
		if (!('a' <= *str && *str <= 'z'))
		{
			flag = 0;
		}
		str++;
	}
	return (flag);
}

/*
 *
 *
int	main(void)
{
	// Test case 1: Empty string (Should return 1)
	printf("Test 1 (Empty): Expected 1, Got %d\n",
		ft_str_is_lowercase(""));

	// Test case 2: Only lowercase (Should return 1)
	printf("Test 2 (Valid): Expected 1, Got %d\n",
		ft_str_is_lowercase("abcdefghijklmnopqrstuvwxyz"));

	// Test case 3: Contains uppercase (Should return 0)
	printf("Test 3 (Uppercase): Expected 0, Got %d\n",
		ft_str_is_lowercase("abcDef"));

	// Test case 4: Contains numbers (Should return 0)
	printf("Test 4 (Numbers): Expected 0, Got %d\n",
		ft_str_is_lowercase("abc123def"));

	// Test case 5: Contains special characters (Should return 0)
	printf("Test 5 (Special): Expected 0, Got %d\n",
		ft_str_is_lowercase("hello world!"));

	return (0);
}
***/
