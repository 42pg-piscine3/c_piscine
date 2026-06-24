/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <joshtan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 10:53:09 by joshtan           #+#    #+#             */
/*   Updated: 2026/06/24 11:09:20 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int track;

	printf("*tab=%d, *(tab+(size-1)):%d\n", *tab, *(tab+(size-1)));

	while (track < size)
	{
		*tab = *(tab);
	}
}

/*
 * Uncomment for test
 */
int main (int argc, char *argv[])
{
	int	tab[] = {1,2,3,4,5,6,7,8,9,0};

	printf("sizeof tab= %ld \n", (sizeof(tab)/sizeof(int)));
}/* */
