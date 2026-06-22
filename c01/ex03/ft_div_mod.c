/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <joshtan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 01:34:34 by joshtan           #+#    #+#             */
/*   Updated: 2026/06/23 03:08:23 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
