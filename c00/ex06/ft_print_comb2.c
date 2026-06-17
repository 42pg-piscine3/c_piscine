/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <joshtan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 00:39:57 by joshtan           #+#    #+#             */
/*   Updated: 2026/06/18 04:58:28 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_comb2(void);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	num_to_char(int num)
{
	char	charint;

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
		charint = '0' + num;
		ft_putchar(charint);
	}
}

void	ft_print_digits2(int left, int right)
{
	if (left < 10)
	{
		num_to_char(0);
	}
	num_to_char(left);
	if (left < 99)
	{
		write(1, " ", 1);
	}
	if (right < 10)
	{
		num_to_char(0);
	}
	num_to_char(right);
	if (left < 99)
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int	digit1;
	int	digit2;

	digit1 = 0;
	while (digit1 < 99)
	{
		digit2 = digit1 + 1;
		while (digit2 < 100)
		{
			if (digit2 > digit1)
			{
				ft_print_digits2(digit1, digit2);
			}
			digit2++;
		}
		digit1++;
	}
}

int	main(void)
{
	ft_print_comb2();
}
