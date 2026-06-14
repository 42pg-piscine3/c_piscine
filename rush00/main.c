/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <joshtan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 15:06:21 by joshtan           #+#    #+#             */
/*   Updated: 2026/06/14 23:09:45 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	g_option_rush = 1;

void	rush(int x, int y);

/*
 * Take a maximum of 2 arguments (either no user input or 1 input)
 * Return -1 if too many arguments
 *
 * If 1 user option detected, convert to int value, otherwise skip.
 * Without checking for user input, (null) will be used for the conversion
 * which have invalid calculation.
 * The resulting conversion is check against ranges 0 to 4.
 * Call rush() to print pattern.
 * Default pattern is 1.
 */
// Rush function has the parameters: rush(columns, rows)
int	main(int argc, char *argv[])
{
	if (2 < argc)
	{
		return (-1);
	}
	if (argc > 1)
	{
		printf("Option passed in: %c\n", argv[1][0]);
		g_option_rush = argv[1][0] - '0';
	}
	printf("Option converted: %d\n", g_option_rush);
	if (g_option_rush < 0 || 4 < g_option_rush)
	{
		return (-1);
	}
	rush(5, 5);
	rush(0, 0);
	rush(5, 3);
	rush(5, 1);
	rush(1, 1);
	rush(1, 5);
	rush(4, 4);
	rush(2, 2);
	rush(-5, 5);
	rush(5, -5);
	return (0);
}
