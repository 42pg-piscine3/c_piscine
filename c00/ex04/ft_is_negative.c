/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <joshtan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:40:22 by joshtan           #+#    #+#             */
/*   Updated: 2026/06/18 10:35:00 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#define TEST 1//define 1 to test

#include <unistd.h>

void	ft_is_negative(int n)
{
	if (n < 0)
		write(1, "N", 1);
	else
		write(1, "P", 1);
}

#if TEST == 1

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/*
 *
 * Note: Handling of negatives before attempting to deconstruct num
 *		if it was after conditions (num >= 10), additional recursive call
 *		has to be made:
 *
 	if (num >= 10)
	{
		num_to_char(num / 10);
		num_to_char(num % 10);
	}
	else if(num < 0)
	{
		ft_putchar('-');
		num = -num;
		num_to_char(num); //extra line to call recursion
	}
	else
	{
		charnum = '0' + num;
		ft_putchar(charnum);
	}

 *	Handling negatives first, allows the rest of the logic to deconstruct the 
 *	number without extra line to call.
 *	Printing '-' first, then only deconstruct it.
 */
void	num_to_char(int num)
{
	char	charnum;

	if (num < 0)
	{
		ft_putchar('-');
		num = -num;
	}
	if (num >= 10)
	{
		num_to_char(num / 10);
		num_to_char(num % 10);
	}
	else
	{
		charnum = '0' + num;
		ft_putchar(charnum);
	}
}

int	main(void)
{
	int	test;

	test = -2;
	while (test < 9)
	{
		num_to_char(test);
		ft_is_negative(test);
		write(1, "\n", 1);
		test++;
	}
}

#endif //end TEST
