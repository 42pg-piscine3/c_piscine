/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <joshtan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 21:39:17 by joshtan           #+#    #+#             */
/*   Updated: 2026/06/23 03:06:00 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

void	ft_putnbr(int n)
{
	char	c;

	if (n < 0)
	{
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	n = n % 10;
	c = n + '0';
	write(1, &c, 1);
}

int	main(void)
{
	int	div;
	int	mod;

	div = 0;
	mod = 0;
	ft_putnbr(div);
	write(1, "\n", 1);
	ft_putnbr(mod);
	write(1, "\n", 1);
	ft_div_mod(56, 0, &div, &mod);
	ft_putnbr(div);
	write(1, "\n", 1);
	ft_putnbr(mod);
	write(1, "\n", 1);
}
