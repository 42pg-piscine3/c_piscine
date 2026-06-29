/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <joshtan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 00:13:53 by joshtan           #+#    #+#             */
/*   Updated: 2026/06/29 10:48:47 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Insertion Sort, we compare x with the value before.
 * Start check at element[1].
 * Outer loop travels the unsorted list.
 * Inner loop scan back and swap forward larger values
 * note: Inner loop should check array controller for boundary before access.
 */
void	ft_sort_int_tab(int *tab, int size)
{
	int	idx;
	int	scan;
	int	cval;

	if (tab)
	{
		idx = 1;
		while (idx < size)
		{
			cval = tab[idx];
			scan = idx;
			while ((scan > 0) && (tab[scan - 1] > cval))
			{
				tab[scan] = tab[scan - 1];
				tab[scan - 1] = cval;
				scan--;
			}
			idx++;
		}
	}
}

/*
 * Uncomment to test
 **
#include <stdio.h>
int main (void)
{
	int	*tab;
	int	size_tab;
	int loop = 0;

	//tab = (int []){7, 2, 6, 3, 8, 4, 5};
	size_tab = sizeof((int []){7, 2, 6, 3, 8, 4, 5})/sizeof(int);
	printf ("size = %d\n", size_tab);
	tab = (int []){7, 2, 6, 3, 8, 4, 5};
	ft_sort_int_tab(tab, size_tab);

	while (loop < size_tab)
	{
		printf ("%d, ", tab[loop]);
		loop++;
	}

	printf ("\n");
	//Null pointer check.
	tab = 0;
	ft_sort_int_tab(tab, 2);
	while (loop < size_tab)
	{
		printf ("%d, ", tab[loop]);
		loop++;
	}
	printf ("\n");
}
**/
