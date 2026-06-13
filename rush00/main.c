/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <joshtan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 15:06:21 by joshtan           #+#    #+#             */
/*   Updated: 2026/06/14 07:34:13 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
int option_rush = 0;

void	rush(int x, int y);


// Rush function has the parameters: rush(columns, rows)
int	main(int argc, char *argv)
{
	if (2 == argc)
	{
		printf("Option passed in: %c\n",argv[1]);
		option_rush	= atoi(*argv[1]);
	}
	rush(5, 5);
	rush(0, 0);
	rush(5, 3);
	rush(5, 1);
	rush(1, 1);
	rush(1, 5);
	rush(4, 4);
	rush(2, 2);
	return (0);
}
