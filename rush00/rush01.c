/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <joshtan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 15:08:08 by joshtan           #+#    #+#             */
/*   Updated: 2026/06/13 16:52:08 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

void ft_putchar(char draw)
{
	write(1, &draw, 1);
}

void	rush(int x, int y)
{
	int row, col;
	
	row = x;
	col = y;

	int col_count = 1 ;
	int row_count ;

	//column loop
	while (row_count <= row)
	{	
		//printf("row_count = %d\n", row_count);
		col_count = 1; //Reset column count when starting a new row

		while (col_count <= col)
		{
			//printf("col_count = %d\n", col_count);

			if (row_count == 1)
			{
				if(col_count == 1 ) //Start with 1 for natural language
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
				if(col_count == 1 ) //Start with 1 for natural language
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
				if(col_count == 1 ) //Start with 1 for natural language
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
