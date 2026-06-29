/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <joshtan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 01:34:34 by joshtan           #+#    #+#             */
/*   Updated: 2026/06/29 15:22:12 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <unistd.h>
*/

/*
 *  divides ‘a’ by ‘b’store result in the integer pointed to by ‘div’.
 *	stores the remainder of the division of in the integer pointed to by ‘mod’.
 */
void	ft_div_mod(int a, int b, int *div, int *mod)
{
	if (b == 0)
	{
		*div = 0;
		*mod = 0;
	}
	else
	{
		*div = a / b;
		*mod = a % b;
	}
}

/*
 * Uncomment to Test

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
    int div;
    int mod;
    int a;
    int b;

    div = 0;
    mod = 0;
    ft_putnbr(div);
    write(1, "\n", 1);
    ft_putnbr(mod);
    write(1, "\n", 1);
    a = 56;
    b = 5;
    ft_div_mod(a, b, &div, &mod);
    ft_putnbr(div);
    write(1, "\n", 1);
    ft_putnbr(mod);
    write(1, "\n", 1);
}
*/
