/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <joshtan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 15:08:08 by joshtan           #+#    #+#             */
/*   Updated: 2026/06/13 17:49:59 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_putchar(char draw);

// x = column, y = row
void	rush(int x, int y)
{
	int	row;
	int	col;
	int	col_count;
	int	row_count;
	
	row = y;
	col = x;
	row_count = 1; //Start row_count with 1 for natural language

	// | row loop 
	// V
	while (row_count <= row)
	{	
		//printf("row_count = %d\n", row_count);
		col_count = 1; //Reset column count when starting a new row
		
		//column loop -->>
		while (col_count <= col)
		{
			//printf("col_count = %d\n", col_count);

			if (row_count == 1)
			{
				if (col_count == 1) //Start with 1 for natural language
				{
					ft_putchar('o');
				}
				else if (col_count < col) //other columns than start or end
				{
					ft_putchar('-');
				}
				else // end of column
				{
					ft_putchar('o');
				}	
			} 
			else if (row_count < row)
			{
				if (col_count == 1) //Start with 1 for natural language
				{
					ft_putchar('|');
				}
				else if (col_count < col) //other columns than start or end
				{
					ft_putchar(' ');
				}
				else // end of column
				{
					ft_putchar('|');
				}				
			}
			else //end of row
			{
				if (col_count == 1) //Start with 1 for natural language
				{
					ft_putchar('o');
				}
				else if (col_count < col) //other columns than start or end
				{
					ft_putchar('-');
				}
				else // end of column
				{
					ft_putchar('o');
				}						
			}
			col_count = col_count + 1; //go to next column
		}

		ft_putchar('\n'); //put newline at the end column
		row_count = row_count + 1; //go to next row
	}
}
