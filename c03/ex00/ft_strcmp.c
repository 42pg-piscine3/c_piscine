/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <joshtan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 21:08:00 by joshtan           #+#    #+#             */
/*   Updated: 2026/07/01 23:26:04 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * It is better to check for NULL, but strcmp doesn't do it - so we don't have 
 * to handle NULL
 *     if ((!s2) || (!s1))
 *       return (0);
 */
int	ft_strcmp(char *s1, char *s2)
{
	int sdiff;

	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	sdiff = *s1 - *s2;
	return (sdiff);
}

