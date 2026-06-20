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
**   row_pair[r][0] = rowN_left  = views[8 + r]
**   row_pair[r][1] = rowN_right = views[12 + r]
**   col_pair[c][0] = colN_top   = views[c]
**   col_pair[c][1] = colN_bottom= views[4 + c]
**
** CANONICAL PATTERNS per pair (from priority table in subject PDF):
**   Each [left, right] or [top, bottom] pair maps to a fixed set of
**   valid permutations of {1,2,3,4}.  We try them in priority order.
**
**   Priority 1 (1 pattern each):
**     [4,1] -> {1,2,3,4}
**     [1,4] -> {4,3,2,1}
**
**   Priority 2 (2 patterns each):
**     [2,1] -> {3,1,2,4} , {3,2,1,4}
**     [1,2] -> {4,2,1,3} , {4,1,2,3}
**
**   Priority 3 (3 patterns each):
**     [1,3] -> {4,2,3,1} , {4,3,1,2} , {4,1,3,2}
**     [3,1] -> {1,3,2,4} , {2,1,3,4} , {2,3,1,4}
**
**   Priority 4 (3 patterns each):
**     [2,3] -> {1,4,3,2} , {2,4,3,1} , {3,4,2,1}
**     [3,2] -> {2,3,4,1} , {1,3,4,2} , {1,2,4,3}
**
**   Priority 5 (3 patterns each):
**     [2,2]  -> {2,1,4,3} , {3,1,4,2} , {3,2,4,1}
**     [2,2]' -> {3,4,1,2} , {2,4,1,3} , {1,4,2,3}
**
** NOTE: [2,2] and [2,2]' are two distinct sub-cases of the [2,2] pair.
**   [2,2]  has 4 in column 3 (0-indexed: position 2)
**   [2,2]' has 4 in column 2 (0-indexed: position 1)
**
** SOLVING ORDER:
**   Traverse rows first (top to bottom), then columns (left to right).
**   For each row, look up matching patterns from the table.
**   For each candidate row pattern, check no column repeats a value.
**   Then verify all column [top, bottom] view counts are satisfiable.
**   Finally verify the completed grid satisfies all views exactly.
*/

#include <unistd.h>
#include <stdlib.h>

/*
** ─── DATA STRUCTURES ────────────────────────────────────────────────────────
*/

/*
** Pattern table entry: one valid permutation for a given [left, right] pair.
** A "pair" is encoded as left * 10 + right for fast key lookup.
*/
typedef struct	s_pattern
{
	int	key;		/* left * 10 + right  (e.g. [2,3] -> 23) */
	int	row[4];		/* the 4 values in order */
}				t_pattern;

/*
** Grid state passed through the solver.
*/
typedef struct	s_board
{
	int	grid[4][4];
	int	views[16];	/* raw views: [0..3]=col_top [4..7]=col_bot
					   [8..11]=row_left [12..15]=row_right */
}				t_board;

/*
** ─── PATTERN TABLE ──────────────────────────────────────────────────────────
**
** Ordered by priority (fewest patterns first = most constrained first).
** Within the same priority level, patterns are listed A,B,C as in PDF.
** key = left * 10 + right
*/
static const t_pattern	g_patterns[] = {
	/* Priority 1 - pair [4,1] and [1,4] - 1 pattern each */
	{41, {1, 2, 3, 4}},
	{14, {4, 3, 2, 1}},

	/* Priority 2 - pair [2,1] and [1,2] - 2 patterns each */
	{21, {3, 1, 2, 4}},
	{21, {3, 2, 1, 4}},
	{12, {4, 2, 1, 3}},
	{12, {4, 1, 2, 3}},

	/* Priority 3 - pair [1,3] and [3,1] - 3 patterns each */
	{13, {4, 2, 3, 1}},
	{13, {4, 3, 1, 2}},
	{13, {4, 1, 3, 2}},
	{31, {1, 3, 2, 4}},
	{31, {2, 1, 3, 4}},
	{31, {2, 3, 1, 4}},

	/* Priority 4 - pair [2,3] and [3,2] - 3 patterns each */
	{23, {1, 4, 3, 2}},
	{23, {2, 4, 3, 1}},
	{23, {3, 4, 2, 1}},
	{32, {2, 3, 4, 1}},
	{32, {1, 3, 4, 2}},
	{32, {1, 2, 4, 3}},

	/* Priority 5 - pair [2,2] - 6 patterns (two sub-cases) */
	/* [2,2]  sub-case: 4 is at index 2 */
	{22, {2, 1, 4, 3}},
	{22, {3, 1, 4, 2}},
	{22, {3, 2, 4, 1}},
	/* [2,2]' sub-case: 4 is at index 1 */
	{22, {3, 4, 1, 2}},
	{22, {2, 4, 1, 3}},
	{22, {1, 4, 2, 3}},
};

#define	PATTERN_COUNT	(int)(sizeof(g_patterns) / sizeof(g_patterns[0]))

/*
** ─── UTILITY ────────────────────────────────────────────────────────────────
*/

/*
** Count how many buildings are visible scanning arr[4] left-to-right.
** A taller building hides all shorter ones behind it.
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
** Check column `c` against its top and bottom view clues.
** views[c] = col_top, views[4 + c] = col_bottom
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
** Check that value `val` does not already appear in column `c`
** for rows 0..(row_limit - 1).
*/
static int	col_has_no_repeat(int grid[4][4], int c, int val, int row_limit)
{
	int	r;

	r = 0;
	while (r < row_limit)
	{
		if (grid[r][c] == val)
			return (0);
		r++;
	}
	return (1);
}

/*
** ─── OUTPUT ─────────────────────────────────────────────────────────────────
*/

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
** ─── SOLVER ─────────────────────────────────────────────────────────────────
**
** Fills the grid row by row (r = 0..3).
** For each row, iterates the pattern table looking for entries whose key
** matches [row_left * 10 + row_right] for that row.
** Before accepting a pattern:
**   1. No value in the pattern repeats a value already in the same column.
**   2. After placing the last row (r == 3), all column view clues pass.
** Returns 1 if a solution was found (grid is filled), 0 otherwise.
*/
static int	solve_row(t_board *b, int r)
{
	int	key;
	int	p;
	int	c;
	int	col_ok;

	if (r == 4)
	{
		c = 0;
		while (c < 4)
		{
			if (!check_col_views(b->grid, c, b->views))
				return (0);
			c++;
		}
		return (1);
	}
	key = b->views[8 + r] * 10 + b->views[12 + r];
	p = 0;
	while (p < PATTERN_COUNT)
	{
		if (g_patterns[p].key != key)
		{
			p++;
			continue ;
		}
		col_ok = 1;
		c = 0;
		while (c < 4)
		{
			if (!col_has_no_repeat(b->grid, c, g_patterns[p].row[c], r))
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
			b->grid[r][c] = g_patterns[p].row[c];
			c++;
		}
		/*
		** Early pruning: after filling all 4 rows in a column (r == 3),
		** we check col views in the base case above.
		** Here we do a partial upward visibility check: if the column
		** is complete only when r == 3, handled above.
		** For r < 3 we rely on the no-repeat guard to keep it valid.
		** (Full column check deferred to r == 4 for simplicity and Norm.)
		*/
		if (solve_row(b, r + 1))
			return (1);
		p++;
	}
	return (0);
}

/*
** ─── PARSE ──────────────────────────────────────────────────────────────────
**
** argv[1] must be exactly 16 digits '1'..'4' separated by single spaces.
** Fills views[16]. Returns 0 on success, -1 on error.
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

/*
** ─── ENTRY POINT ────────────────────────────────────────────────────────────
*/

int	main(int argc, char **argv)
{
	t_board	b;

	if (argc != 2 || parse_views(argv[1], b.views) == -1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (!solve_row(&b, 0))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	print_grid(b.grid);
	return (0);
}
