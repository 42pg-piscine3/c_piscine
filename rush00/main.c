/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <joshtan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 15:06:21 by joshtan           #+#    #+#             */
/*   Updated: 2026/06/13 17:24:20 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h> // for using printf


void	rush (int x, int y);

int		main ()
{
	//rush ( column, row)
	printf (" rush (5,5)\n");
	rush (5,5);

	printf (" \nrush (5,3)\n");
	rush (5,3);

	printf (" \nrush (5,1)\n");
	rush (5,1);

	printf (" \nrush (1,1)\n");
	rush (1,1);

	printf (" \nrush (1,5)\n");
	rush (1,5);

	printf (" \nrush (4,4)\n");
	rush (4,4);

	printf (" \nrush (2,2)\n");
	rush (2,2);
	return (0);
}
