/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <joshtan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 15:06:21 by joshtan           #+#    #+#             */
/*   Updated: 2026/06/14 06:46:06 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	rush(int x, int y);

// Rush function has the parameters: rush(columns, rows)
int	main(void)
{
	rush(5, 5);
	rush(0, 0);
	rush(5, 3);
	rush(5, 1);
	rush(1, 1);
	rush(1, 5);
	rush(4, 4);
	rush(2, 2);
	return (0);
}
