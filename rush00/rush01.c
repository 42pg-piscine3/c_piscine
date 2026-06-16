/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <joshtan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 15:08:08 by joshtan           #+#    #+#             */
/*   Updated: 2026/06/16 13:26:11 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

extern int	g_option_rush;

static char	g_patterns[5][8] = {
{'o', '-', 'o', '|', '|', 'o', '-', 'o'},
{'/', '*', '\\', '*', '*', '\\', '*', '/'},
{'A', 'B', 'A', 'B', 'B', 'C', 'B', 'C'},
{'A', 'B', 'C', 'B', 'B', 'A', 'B', 'C'},
{'A', 'B', 'C', 'B', 'B', 'C', 'B', 'A'}
};

void	ft_putchar(char draw);

/*
 *	This function draws column by column when the program is at first row (top)
 *
 *	col_count is used to indicate which column the program is on.
 *	A loop is used to
 *	1. increment the col_count (from 1 to the "col")
 *	2. decide what to draw depending on col_count.
 *
 *		/ * * * \  <-- Draws this pattern for first row
 *		*       *
 *		*       *
 *		\ * * * /
 *
 *	At the end of the column, place a newline (\n) character.
 */
void	drawrow_first(int col)
{
	int	col_count;

	col_count = 1;
	while (col_count <= col)
	{
		if (col_count == 1)
		{
			ft_putchar(g_patterns[g_option_rush][0]);
		}
		else if (col_count < col)
		{
			ft_putchar(g_patterns[g_option_rush][1]);
		}
		else
		{
			ft_putchar(g_patterns[g_option_rush][2]);
		}
		col_count++;
	}
	ft_putchar('\n');
}

/*
 *	This function draws column by column for row the program is at.
 *
 *	col_count is used to indicate which column the program is on.
 *	A loop is used to
 *	1. increment the col_count (from 1 to the "col")
 *	2. decide what to draw depending on col_count.
 *
 *		/ * * * \     Draws:
 *		*       * <-- Patterns for rows in between top and last.
 *		*       * <-- Patterns for rows in between top and last.
 *		\ * * * /
 *
 *	At the end of the column, place a newline (\n) character.
 */
void	drawrow_middles(int col)
{
	int	col_count;

	col_count = 1;
	while (col_count <= col)
	{
		if (col_count == 1)
		{
			ft_putchar(g_patterns[g_option_rush][3]);
		}
		else if (col_count < col)
		{
			ft_putchar(' ');
		}
		else
		{
			ft_putchar(g_patterns[g_option_rush][4]);
		}
		col_count++;
	}
	ft_putchar('\n');
}

/*
 *	This function draws column by column when the program is at last row
 *
 *	col_count is used to indicate which column the program is on.
 *	A loop is used to
 *	1. increment the col_count (from 1 to the "col")
 *	2. decide what to draw depending on col_count.
 *
 *		/ * * * \
 *		*       *
 *		*       *
 *		\ * * * / <-- Draws patterns for last rows.
 *
 *	At the end of the column, place a newline (\n) character.
 */
void	drawrow_last(int col)
{
	int	col_count;

	col_count = 1;
	while (col_count <= col)
	{
		if (col_count == 1)
		{
			ft_putchar(g_patterns[g_option_rush][5]);
		}
		else if (col_count < col)
		{
			ft_putchar(g_patterns[g_option_rush][6]);
		}
		else
		{
			ft_putchar(g_patterns[g_option_rush][7]);
		}
		col_count++;
	}
	ft_putchar('\n');
}

/*
 *	This function controls the row traversal.
 *
 *	row_count is used to indicate which row the program is on.
 *	A loop is used to
 *	1. increment the row_count (from 1 to the "row")
 *	2. decide what to draw depending on row_count.
 *
 *	when row_count is the first	- call a drawing function for the first row
 *  when row_count is not first/last - call a drawing function for middle rows
 *  when row_count is the last - call a drawing function for the last row
 *
 *	note: row_count can only be incremented at the end of the loop.
 *	If row_count is at the beginnin of the loop, the decisions will be wrong.
 *
 */
//			x = column, y = row
void	rush(int x, int y)
{
	int	row_count;

	row_count = 1;
	printf("\nrush(%d, %d):\n", x, y);//TODO: remove
	if ((0 > x) || (0 > y))
	{
		x = 0;
		y = 0;
	}
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
