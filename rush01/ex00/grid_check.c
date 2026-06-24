/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 14:34:41 by joshtan           #+#    #+#             */
/*   Updated: 2026/06/21 16:55:45 by nisim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 ** Count boxes visible scanning arr[4] left-to-right.
 ** Each box taller than all previous ones adds +1 to visible count.
 */
int	count_visible(int arr[4])
{
	int	max;
	int	visible;
	int	i;

	max = 0;
	visible = 0;
	i = 0;
	while (i < 4)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			visible++;
		}
		i++;
	}
	return (visible);
}

/*
 ** Check column c against its top/bottom clues, now stored together as
 ** view_tb[c] = {top, bottom}.
 ** Extracts column into a temporary array, then checks both directions.
 */
int	check_col_views(int grid[4][4], int c, int view_tb[4][2])
{
	int	col[4];
	int	rev[4];
	int	i;

	i = 0;
	while (i < 4)
	{
		col[i] = grid[i][c];
		rev[i] = grid[3 - i][c];
		i++;
	}
	if (count_visible(col) != view_tb[c][0])
		return (0);
	if (count_visible(rev) != view_tb[c][1])
		return (0);
	return (1);
}

/*
 ** Return 1 if val does not appear in column c for rows 0..(limit-1).
 ** Used to check pairing constraint before committing a row.
 */
int	col_has_no_repeat(int grid[4][4], int c, int val, int limit)
{
	int	row;

	row = 0;
	while (row < limit)
	{
		if (grid[row][c] == val)
			return (0);
		row++;
	}
	return (1);
}
