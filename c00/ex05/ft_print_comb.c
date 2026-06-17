/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <joshtan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 00:39:57 by joshtan           #+#    #+#             */
/*   Updated: 2026/06/18 04:02:02 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

void	ft_print_comb(void);

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
		printf("1st group recursion call: %d\n", num);
		num_to_char(num / 10);
		printf("2nd group recursion call: %d\n", num);
		num_to_char(num % 10);
	}
	else
	{
		charint = '0' + num;
		ft_putchar(charint);
	}
}

void	ft_print_comb(void)
{
	int	digit1;
	int	digit2;
	int	digit3;

	digit1 = 0;
	while (digit1 < 8)
	{
		digit2 = digit1 + 1;
		while (digit2 < 9)
		{
			digit3 = digit2 + 1;
			while (digit3 < 10)
			{
				if (digit2 > digit1)
				{
					num_to_char(digit1);
					num_to_char(digit2);
				}
				if (digit3 > digit2)
				{
					num_to_char(digit3);
					write(1, ", ", 2);
				}
				digit3++;
			}
			digit2++;
		}
		digit1++;
	}
}

int	main(void)
{
	ft_print_comb();
}
