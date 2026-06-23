/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <joshtan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 21:39:17 by joshtan           #+#    #+#             */
/*   Updated: 2026/06/23 01:32:52 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//# include <unistd.h>

/*
 * Swapping without extra variable using XOR
 * XOR only performs "OR" when bits differ.
 * 1 OR  1 is 1, but
 * 1 XOR 1 is 0
 *
 *  A | B | A XOR B
    --+---+-------
    0 | 0 |   0
    0 | 1 |   1
    1 | 0 |   1
    1 | 1 |   0
 *
 * (a ^ b) ^ b = a
 * a ^ (b ^ b )= a ----- {1}
 *
 * 1. a = a^b
 *	Now a is a^b    ---- {2}
 *      b is unchanged
 *
 * 2. b = a^b
 * substiture {2} into a: a=(a^b)
 *	  b = (a^b)^b
 *	  b = a^(b^b)   [equation 1]
 *    b = a
 * Now b is a      ---- {3}
 *    a is still [equation 2]
 *
 * 3. a = a^b
 * Substitute {3} into b: b=a
 * Substitute {2} into a: a=(a^b)
 *    a = (a^b)^(a)
 *    a = (a^a)^b
 *    a = b
 *
 *    a is now b
 *    b is now a [equation 3]
 */

void	ft_swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

/*
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

	alpha = 12;
	beta = 2048;
	ft_putnbr(alpha);
	write(1, "\n", 1);
	ft_putnbr(beta);
	write(1, "\n", 1);
	ft_swap(&alpha, &beta);
	ft_putnbr(alpha);
	write(1, "\n", 1);
	ft_putnbr(beta);
	write(1, "\n", 1);
}
*/
