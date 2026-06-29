/* ************************************************************************** */
/*                                                                            */
/*   ft_putchar.c                                         :::      ::::::::   */
/*   By: joshtan <joshtan@student.42.fr>                :+:      :+:    :+:   */
/*   By: patitan <patitan@student.42.fr>              +:+ +:+         +:+     */
/*   By: dming-ha <dming-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 15:08:08 by joshtan           #+#    #+#             */
/*   Updated: 2026/06/14 07:01:35 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char draw)
{
	write(1, &draw, 1);
}
