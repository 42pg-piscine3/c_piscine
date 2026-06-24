/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <joshtan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 10:53:09 by joshtan           #+#    #+#             */
/*   Updated: 2026/06/24 12:37:56 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int element;
	int tmp;

	//printf("first @*tab=%d, last @*(tab+(size-1)):%d\n", *tab, *(tab+(size-1)));

	element = 0;
	while (element < size)
	{
		tmp = *(tab+(size-1-element));
		*(tab+(size-1-element)) = *tab;
		*tab = tmp;
		element++;
	}
}

/*
 * Uncomment for test
 */
int main (int argc, char *argv[])
{
	int	tab[] = {1,2,3,4,5,6,7,8,9,0,123};

	printf("sizeof tab= %ld \n", (sizeof(tab)/sizeof(int)));
	ft_rev_int_tab(tab, sizeof(tab)/sizeof(int));
	//printf("first @*tab=%d, last @*(tab+(size-1)):%d\n", *tab, *(tab+(size-1)));
}/* */
