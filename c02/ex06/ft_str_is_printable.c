/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 14:19:33 by joshtan           #+#    #+#             */
/*   Updated: 2026/06/30 14:46:27 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //For test print.

int	ft_str_is_printable(char *str)
{
	int flag;

	if (!str)
		return (1);
	flag = 1;
	while(*str)
	{
		if(!(32 <= *str && *str <= 126))
			flag = 0;

		str++;
	}
	return (flag);
}


int	main (void)
{
	printf("Test 1 (Empty)          - Expected: 1, Got: %d\n",
			ft_str_is_printable(""));
	printf("Test 2 (Standard Text)  - Expected: 1, Got: %d\n",
			ft_str_is_printable("Hello, World!"));
	printf("Test 3 (Numbers/Syms)   - Expected: 1, Got: %d\n",
			ft_str_is_printable("1234567890 -=~"));
	printf("Test 4 (Tab Character)  - Expected: 0, Got: %d\n",
			ft_str_is_printable("Hello\tWorld"));
	printf("Test 5 (Newline)        - Expected: 0, Got: %d\n",
			ft_str_is_printable("Line1\nLine2"));
	printf("Test 6 (Backspace Esc)  - Expected: 0, Got: %d\n",
			ft_str_is_printable("Hello\b"));
	printf("Test 7 (All Bounds)     - Expected: 1, Got: %d\n",
			ft_str_is_printable(
				" !\"#$%&'()*+,-./"
				"0123456789:;<=>?@"
				"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
				"[\\]^_`"
				"abcdefghijklmnopqrstuvwxyz{|}~"));
}
