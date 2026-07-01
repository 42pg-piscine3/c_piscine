/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 14:07:02 by joshtan           #+#    #+#             */
/*   Updated: 2026/07/01 14:00:46 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	flag;

	flag = 1;
	if (!str)
		return (flag);
	while (*str)
	{
		if (!('A' <= *str && *str <= 'Z'))
		{
			flag = 0;
		}
		str++;
	}
	return (flag);
}

/*
 *
 **
int	main(void)
{
	printf("T1 (Empty)          - Expect: 1, Got: %d\n",
			ft_str_is_uppercase(""));
	printf("T2 (Valid Uppercase)- Expect: 1, Got: %d\n",
			ft_str_is_uppercase("HELLO"));
	printf("T3 (Single Upper)   - Expect: 1, Got: %d\n",
			ft_str_is_uppercase("A"));
	printf("T4 (Lowercase)      - Expect: 0, Got: %d\n",
			ft_str_is_uppercase("HELLo"));
	printf("T5 (Numbers)        - Expect: 0, Got: %d\n",
			ft_str_is_uppercase("HELLO123"));
	printf("T6 (Spaces)         - Expect: 0, Got: %d\n",
			ft_str_is_uppercase("HELLO WORLD"));
	printf("T7 (Symbols)        - Expect: 0, Got: %d\n",
			ft_str_is_uppercase("HELLO!"));
	printf("T8 (All Bounds)     - Expect: 1, Got: %d\n",
			ft_str_is_uppercase("ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
	
   return (0);
}
***/
