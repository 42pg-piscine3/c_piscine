/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <joshtan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 21:39:17 by joshtan           #+#    #+#             */
/*   Updated: 2026/06/23 03:31:41 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b);

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
	int	alpha;
	int	beta;

	alpha = 51;
	beta = 5;
	ft_putnbr(alpha);
	write(1, "\n", 1);
	ft_putnbr(beta);
	write(1, "\n", 1);
	ft_ultimate_div_mod(&alpha, &beta);
	ft_putnbr(alpha);
	write(1, "\n", 1);
	ft_putnbr(beta);
	write(1, "\n", 1);
}
