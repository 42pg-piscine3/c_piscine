/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nisim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 19:28:39 by nisim             #+#    #+#             */
/*   Updated: 2026/06/21 16:49:16 by nisim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_grid(int grid[4][4]);
int		solve_row(int grid[4][4], int view_lr[4][2], int view_tb[4][2],
			int row);

/*
 ** Parse argv[1]: exactly 16 digits '1'..'4' separated by single spaces.
 ** Validates char-by-char into a local views[16] (subject order), then
 ** redistributes into the pairing arrays:
 **   [0..3]  col1top..col4top     -> view_tb[c][0]
 **   [4..7]  col1bottom..col4bottom-> view_tb[c][1]
 **   [8..11] row1left..row4left   -> view_lr[r][0]
 **   [12..15] row1right..row4right -> view_lr[r][1]
 ** Returns 0 on success, -1 on any format error.
 */

int	ft_strconvert(char *str, int *view)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i % 2 == 0)
		{
			if (str[i] < '1' || str[i] > '4')
				return (-1);
			view[i / 2] = str[i] - '0';
		}
		else
		{
			if (str[i] != ' ')
				return (0);
		}
		i++;
	}
	if (i != 31)
		return (-1);
	return (0);
}

int	parse_views(char *arg, int view_lr[4][2], int view_tb[4][2])
{
	int	views[16];
	int	i;

	if (ft_strconvert(arg, views) == -1)
		return (-1);
	i = 0;
	while (i < 4)
	{
		view_tb[i][0] = views[i];
		view_tb[i][1] = views[4 + i];
		view_lr[i][0] = views[8 + i];
		view_lr[i][1] = views[12 + i];
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	grid[4][4];
	int	view_lr[4][2];
	int	view_tb[4][2];

	if (argc != 2 || parse_views(argv[1], view_lr, view_tb) == -1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (!solve_row(grid, view_lr, view_tb, 0))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	print_grid(grid);
	return (0);
}
