/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <joshtan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 04:46:25 by joshtan           #+#    #+#             */
/*   Updated: 2026/06/30 05:16:25 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	is_alpha;

	is_alpha = 1;
	if (!str)
		return (1);
	while (*str)
	{
		if (!(('A' <= *str && *str <= 'Z') || ('a' <= *str && *str <= 'z')))
			is_alpha = 0;
		str++;
	}
	return (is_alpha);
}

/*
 * Uncomment to test
 **
#include <stdio.h>

int	main(void)
{
	printf("T1 (Empty)   - Expect: 1, Is: %d\n", ft_str_is_alpha(""));
    printf("T2 (Alpha)   - Expect: 1, Is: %d\n", ft_str_is_alpha("Hello"));
    printf("T3 (Space)   - Expect: 0, Is: %d\n", ft_str_is_alpha("Hello World"));
    printf("T4 (Numbers) - Expect: 0, Is: %d\n", ft_str_is_alpha("Code42"));
    printf("T5 (Special) - Expect: 0, Is: %d\n", ft_str_is_alpha("C++"));
}
***/
