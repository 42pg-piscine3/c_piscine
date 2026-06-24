/* ************************************************************************** */
/*                                                                            */
/*   main.c                                               :::      ::::::::   */
/*   By: joshtan <joshtan@student.42.fr>                :+:      :+:    :+:   */
/*   By: patitan <patitan@student.42.fr>              +:+ +:+         +:+     */
/*   By: dming-ha <dming-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 15:08:08 by joshtan           #+#    #+#             */
/*   Updated: 2026/06/14 07:01:35 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	rush(int x, int y);

int	main(void)
{
	rush(5, 5);
	rush(3, 10);
	rush(8, 1);
	rush(1, 1);
	rush(-3, 5);
	rush(0, 0);
	rush(40, 20);
	rush(1, 5);
	rush(5, 1);
	return (0);
}
