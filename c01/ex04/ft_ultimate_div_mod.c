/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <joshtan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 01:34:34 by joshtan           #+#    #+#             */
/*   Updated: 2026/06/23 03:30:49 by joshtan          ###   ########.fr       */
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
