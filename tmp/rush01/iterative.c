static int	solve_row(int grid[4][4], int viewLR[4][2], int viewTB[4][2])
{
	int	p_idx[4];
	int	r;
	int	c;
	int	p;

	r = 0;
	p_idx[0] = 0;
	while (r >= 0)
	{
		if (r == 4)
		{
			c = 0;
			while (c < 4 && check_col_views(grid, c, viewTB))
				c++;
			if (c == 4)
				return (1);
			r--;
			continue ;
		}
		p = p_idx[r];
		while (p < PATTERN_COUNT && !row_pattern_fits(grid, viewLR, r, p))
			p++;
		if (p == PATTERN_COUNT)
		{
			r--;
			continue ;
		}
		place_row(grid, p, r);
		p_idx[r] = p + 1;
		r++;
		p_idx[r] = 0;
	}
	return (0);
}
