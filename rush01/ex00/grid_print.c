/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 14:47:32 by joshtan           #+#    #+#             */
/*   Updated: 2026/06/21 16:52:40 by nisim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	write_char(char c)
{
	write(1, &c, 1);
}

void	write_digit(int n)
{
	char	c;

	c = '0' + n;
	write(1, &c, 1);
}

void	print_grid(int grid[4][4])
{
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			write_digit(grid[row][col]);
			if (col < 3)
				write_char(' ');
			col++;
		}
		write_char('\n');
		row++;
	}
}
