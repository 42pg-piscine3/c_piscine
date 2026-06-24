/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_row.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaminudd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 15:00:18 by aaminudd          #+#    #+#             */
/*   Updated: 2026/06/21 16:55:19 by nisim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_col_views(int grid[4][4], int c, int view_tb[4][2]);
int	col_has_no_repeat(int grid[4][4], int c, int val, int limit);

#define PATTERN_COUNT 24

/*
** g_patterns[i][0]   = left  (row_left or col_top)
** g_patterns[i][1]   = right (row_right or col_bottom)
** g_patterns[i][2-5] = four cell values in order
** Ordered by priority: fewest options first (most constrained pairs first).
*/
const int	g_patterns[PATTERN_COUNT][6] = {
{4, 1, 1, 2, 3, 4},
{1, 4, 4, 3, 2, 1},
{2, 1, 3, 1, 2, 4},
{2, 1, 3, 2, 1, 4},
{1, 2, 4, 2, 1, 3},
{1, 2, 4, 1, 2, 3},
{1, 3, 4, 2, 3, 1},
{1, 3, 4, 3, 1, 2},
{1, 3, 4, 1, 3, 2},
{3, 1, 1, 3, 2, 4},
{3, 1, 2, 1, 3, 4},
{3, 1, 2, 3, 1, 4},
{2, 3, 1, 4, 3, 2},
{2, 3, 2, 4, 3, 1},
{2, 3, 3, 4, 2, 1},
{3, 2, 2, 3, 4, 1},
{3, 2, 1, 3, 4, 2},
{3, 2, 1, 2, 4, 3},
{2, 2, 2, 1, 4, 3},
{2, 2, 3, 1, 4, 2},
{2, 2, 3, 2, 4, 1},
{2, 2, 3, 4, 1, 2},
{2, 2, 2, 4, 1, 3},
{2, 2, 1, 4, 2, 3},
};

int	all_cols_match(int grid[4][4], int view_tb[4][2])
{
	int	col;

	col = 0;
	while (col < 4)
	{
		if (!check_col_views(grid, col, view_tb))
			return (0);
		col++;
	}
	return (1);
}

int	pattern_can_be_used(int grid[4][4], int view_lr[4][2],
		int row, int ptn)
{
	int	col;

	if (g_patterns[ptn][0] != view_lr[row][0])
		return (0);
	if (g_patterns[ptn][1] != view_lr[row][1])
		return (0);
	col = 0;
	while (col < 4)
	{
		if (!col_has_no_repeat(grid, col, g_patterns[ptn][col + 2],
			row))
			return (0);
		col++;
	}
	return (1);
}

void	put_pattern_in_row(int grid[4][4], int row, int ptn)
{
	int	col;

	col = 0;
	while (col < 4)
	{
		grid[row][col] = g_patterns[ptn][col + 2];
		col++;
	}
}

/*
** Recursive solver: places one row at a time (row = 0..3).
** Looks up candidate patterns by key = viewlr[row][0] (left), viewlr[row][1]
** (right). Guards: no column repeat, then full column view check at row==4.
** Returns 1 if a valid complete grid was found, 0 otherwise.
*/
int	solve_row(int grid[4][4], int view_lr[4][2], int view_tb[4][2],
		int row)
{
	int	ptn;

	if (row == 4)
		return (all_cols_match(grid, view_tb));
	ptn = 0;
	while (ptn < PATTERN_COUNT)
	{
		if (pattern_can_be_used(grid, view_lr, row, ptn))
		{
			put_pattern_in_row(grid, row, ptn);
			if (solve_row(grid, view_lr, view_tb, row + 1))
				return (1);
		}
		ptn++;
	}
	return (0);
}
