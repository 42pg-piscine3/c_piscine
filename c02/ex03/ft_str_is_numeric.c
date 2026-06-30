/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <joshtan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 05:23:22 by joshtan           #+#    #+#             */
/*   Updated: 2026/06/30 10:15:41 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	is_num;

	is_num = 1;
	if (!str)
		return (1);
	while (*str)
	{
		if (!('0' <= *str && *str <= '9'))
			is_num = 0;
		str++;
	}
	return (is_num);
}

/*
 * Uncomment to test
 **
int	main(void)
{
	printf("T1 (Empty)  - Expect: 1, Is %d\n",
		ft_str_is_numeric(""));
	printf("T2 (Digits) - Expect: 1, Is %d\n", ft_str_is_numeric("0123456789"));
	printf("T3 (Alpha)  - Expect: 0, Is %d\n", ft_str_is_numeric("123a45"));
	printf("T4 (Space)   - Expect: 0, Is %d\n", ft_str_is_numeric("123 456"));
	printf("T5 (Special) - Expect: 0, Is %d\n", ft_str_is_numeric("42-24"));
	return (0);
}
***/
