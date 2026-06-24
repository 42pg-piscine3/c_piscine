/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <joshtan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 10:53:09 by joshtan           #+#    #+#             */
/*   Updated: 2026/06/24 21:46:02 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

/* The general idea is to swap front and back.
 * technically:
 * - front starts with 0 and increments
 * - back starts with "size - 1" (off by 1 issue in c) and DEcrements
 * - front++		  // front = 1
 * - size - 1 - front // reverse = size - 2 (:1 - front)
 * Continue condition is front < reverse
 * pointers access to array can be done via *(tab + element)
 *
 * 	while (element < (size-1-element))
	{
		tmp = *(tab + (size - 1 - element));
		*(tab + (size - 1 - element)) = *(tab + element); //tricky to remember
		*(tab + element) = tmp;							  //tab + element
		element++;
	}
 * But it is rather unreadable. So accessing as array looks better.
 */
void	ft_rev_int_tab(int *tab, int size)
{
	int element;
	int rev_element;
	int tmp;

	element = 0;
	rev_element = size - 1;
	while (element < rev_element)
	{
		tmp = tab[element];
		tab[element] = tab[rev_element];
		tab[rev_element] = tmp;
		element++;
		rev_element--;
	}
}

/*
 * Uncomment for test
 */
int main (int argc, char *argv[])
{
	int	tab[] = {1,2,3,4,5,6,7,8,9,0,123};
	int cnt = 0;

	printf("sizeof tab= %ld \n", (sizeof(tab)/sizeof(tab[0])));
	ft_rev_int_tab(tab, sizeof(tab)/sizeof(tab[0]));

	while (cnt < (sizeof(tab)/sizeof(tab[0])))
	{
		printf("tab[%d]: %d\n", cnt, tab[cnt]);
		cnt++;
	}
}/* */
