/* ************************************************************************** */
/*                                                                            */
/*   rush01.c                                             :::      ::::::::   */
/*   By: joshtan <joshtan@student.42.fr>                :+:      :+:    :+:   */
/*   By: patitan <patitan@student.42.fr>              +:+ +:+         +:+     */
/*   By: dming-ha <dming-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 15:08:08 by joshtan           #+#    #+#             */
/*   Updated: 2026/06/14 07:01:35 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_putchar(char draw);

void	drawrow_first(int col)
{
	int	col_count;

	col_count = 1;
	while (col_count <= col)
	{
		if (col_count == 1)
		{
			ft_putchar('A');
		}
		else if (col_count < col)
		{
			ft_putchar('B');
		}
		else
		{
			ft_putchar('C');
		}
		col_count++;
	}
	ft_putchar('\n');
}

void	drawrow_middles(int col)
{
	int	col_count;

	col_count = 1;
	while (col_count <= col)
	{
		if (col_count == 1)
		{
			ft_putchar('B');
		}
		else if (col_count < col)
		{
			ft_putchar(' ');
		}
		else
		{
			ft_putchar('B');
		}
		col_count++;
	}
	ft_putchar('\n');
}

void	drawrow_last(int col)
{
	int	col_count;

	col_count = 1;
	while (col_count <= col)
	{
		if (col_count == 1)
		{
			ft_putchar('C');
		}
		else if (col_count < col)
		{
			ft_putchar('B');
		}
		else
		{
			ft_putchar('A');
		}
		col_count++;
	}
	ft_putchar('\n');
}

void	translate(int x, int y)
{
	int	row_count;

	row_count = 1;
	while (row_count <= y)
	{
		if (row_count == 1)
		{
			drawrow_first(x);
		}
		else if (row_count < y)
		{
			drawrow_middles(x);
		}
		else
		{
			drawrow_last(x);
		}
		row_count = row_count + 1;
	}
}

//	x = column, y = row
void	rush(int x, int y)
{
	printf("rush(%d, %d):\n", x, y);
	if (x >= 0 && y >= 0)
	{
		translate(x, y);
	}
	else if (x < 0 || y < 0)
	{
		printf("Please check again ! Both value cannot be negative\n");
	}
}
