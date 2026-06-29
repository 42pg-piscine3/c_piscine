/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <joshtan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 01:34:34 by joshtan           #+#    #+#             */
/*   Updated: 2026/06/29 15:59:55 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * divides the value pointed to by ‘a’ by the value pointed to by ‘b’.
 * - result of the division is stored in the integer pointed to by ‘a’,
 * - remainder is stored in the integer pointed to by ‘b’.
 */
void	ft_ultimate_div_mod(int *a, int *b)
{
	int	atmp;

	if (*b == 0)
	{
		*a = 0;
		*b = 0;
	}
	else
	{
		atmp = *a;
		*a = *a / *b;
		*b = atmp % *b;
	}
}

/*
 * Uncomment to test.
 *
#include <unistd.h>
void    ft_putnbr(int n)
{
    char    c;

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

int main(void)
{
    int alpha;
    int beta;

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
**/
