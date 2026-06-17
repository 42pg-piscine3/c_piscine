/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <joshtan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 05:19:25 by joshtan           #+#    #+#             */
/*   Updated: 2026/06/18 05:56:55 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

#define TEST 0//Set to 1 for testing with main

void	ft_putnbr(int nb);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	char	charint;

	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		charint = '0' + nb;
		ft_putchar(charint);
	}
}

#if TEST == 1

int	main(int argc, char *argv[])
{
	int	num;

	if (argc < 2)
	{
		ft_putnbr(42);
	}
	else
	{
		while (*argv[1] != '\0')
		{
			num = *argv[1] - '0';
			ft_putnbr(num);
			argv[1] = argv[1] + 1;
		}
	}
}
#endif // End Test
