/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <joshtan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 13:40:22 by joshtan           #+#    #+#             */
/*   Updated: 2026/06/17 10:06:44 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	if (n < 0)
		write(1, "N", 1);
	else
		write(1, "P", 1);
}

/*
 * Uncomment to test
 *
void	num_to_char (int num)
{
	if (num >= 10)
	{
		num_to_char(num / 10);
		num_to_char

	}
	num_to_char('0' + (num % 10));
}

int	main(void)
{
	int test = -2;

	while (test < 9)
	{
		write(1, test, 1);
		ft_is_negative(test);
		write(1, "\n", 1);
		test++;
	}
}
*/
