/*
** rush01.c
**
** ALGORITHM: Pattern-lookup with priority ordering.
**
** TERMINOLOGY:
**   views[16] = the 16 clue values parsed from argv[1], in subject order:
**     [0..3]  = col1top..col4top
**     [4..7]  = col1bottom..col4bottom
**     [8..11] = row1left..row4left
**     [12..15]= row1right..row4right
**
** PAIRS (rearranged from views[] for easier lookup):
**   row views for row r : views[8 + r] (left)  views[12 + r] (right)
**   col views for col c : views[c]     (top)   views[4 + c]  (bottom)
**
** PATTERN TABLE LAYOUT (g_patterns[24][6]):
**   col 0   = left  (row_left  OR col_top)
**   col 1   = right (row_right OR col_bottom)
**   col 2-5 = the four cell values in order
**
**   Priority 1 (1 pattern each):  [4,1]  [1,4]
**   Priority 2 (2 patterns each): [2,1]  [1,2]
**   Priority 3 (3 patterns each): [1,3]  [3,1]
**   Priority 4 (3 patterns each): [2,3]  [3,2]
**   Priority 5 (6 patterns):      [2,2]  (two sub-cases)
**     sub-case  [2,2]  : 4 is at index 2 (0-indexed from col 2)
**     sub-case  [2,2]' : 4 is at index 1 (0-indexed from col 2)
*/

#include <unistd.h>

#define PATTERN_COUNT 24

/*
** g_patterns[i][0]   = left  (row_left or col_top)
** g_patterns[i][1]   = right (row_right or col_bottom)
** g_patterns[i][2-5] = four cell values in order
** Ordered by priority: fewest options first (most constrained pairs first).
*/
static const int	g_patterns[PATTERN_COUNT][6] = {
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

/*
** Count buildings visible scanning arr[4] left-to-right.
** Each building taller than all previous ones adds +1 to visible count.
*/
static int	count_visible(int arr[4])
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
** Check column c against its top (views[c]) and bottom (views[4+c]) clues.
** Extracts column into a temporary array, then checks both directions.
*/
static int	check_col_views(int grid[4][4], int c, int views[16])
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
	if (count_visible(col) != views[c])
		return (0);
	if (count_visible(rev) != views[4 + c])
		return (0);
	return (1);
}

/*
** Return 1 if val does not appear in column c for rows 0..(limit-1).
** Used to enforce the Latin-square constraint before committing a row.
*/
static int	col_has_no_repeat(int grid[4][4], int c, int val, int limit)
{
	int	r;

	r = 0;
	while (r < limit)
	{
		if (grid[r][c] == val)
			return (0);
		r++;
	}
	return (1);
}

static void	write_char(char c)
{
	write(1, &c, 1);
}

static void	write_digit(int n)
{
	char	c;

	c = '0' + n;
	write(1, &c, 1);
}

static void	print_grid(int grid[4][4])
{
	int	r;
	int	c;

	r = 0;
	while (r < 4)
	{
		c = 0;
		while (c < 4)
		{
			write_digit(grid[r][c]);
			if (c < 3)
				write_char(' ');
			c++;
		}
		write_char('\n');
		r++;
	}
}

/*
** Recursive solver: places one row at a time (r = 0..3).
** Looks up candidate patterns by key = views[8+r]*10 + views[12+r].
** Guards: no column repeat, then full column view check at r==4.
** Returns 1 if a valid complete grid was found, 0 otherwise.
*/
static int	solve_row(int grid[4][4], int views[16], int r)
{
	int	p;
	int	c;
	int	col_ok;

	if (r == 4)
	{
		c = 0;
		while (c < 4)
		{
			if (!check_col_views(grid, c, views))
				return (0);
			c++;
		}
		return (1);
	}
	p = 0;
	while (p < PATTERN_COUNT)
	{
		if (g_patterns[p][0] != views[8 + r]
			|| g_patterns[p][1] != views[12 + r])
		{
			p++;
			continue ;
		}
		col_ok = 1;
		c = 0;
		while (c < 4)
		{
			if (!col_has_no_repeat(grid, c, g_patterns[p][c + 2], r))
			{
				col_ok = 0;
				break ;
			}
			c++;
		}
		if (!col_ok)
		{
			p++;
			continue ;
		}
		c = 0;
		while (c < 4)
		{
			grid[r][c] = g_patterns[p][c + 2];
			c++;
		}
		if (solve_row(grid, views, r + 1))
			return (1);
		p++;
	}
	return (0);
}

/*
** Parse argv[1]: exactly 16 digits '1'..'4' separated by single spaces.
** Fills views[16]. Returns 0 on success, -1 on any format error.
*/
static int	parse_views(char *arg, int views[16])
{
	int	i;
	int	pos;

	i = 0;
	pos = 0;
	while (i < 16)
	{
		if (arg[pos] < '1' || arg[pos] > '4')
			return (-1);
		views[i] = arg[pos] - '0';
		pos++;
		if (i < 15)
		{
			if (arg[pos] != ' ')
				return (-1);
			pos++;
		}
		i++;
	}
	if (arg[pos] != '\0')
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	int	grid[4][4];
	int	views[16];

	if (argc != 2 || parse_views(argv[1], views) == -1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (!solve_row(grid, views, 0))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	print_grid(grid);
	return (0);
}
