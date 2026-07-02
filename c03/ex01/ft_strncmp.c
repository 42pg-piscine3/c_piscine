/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <joshtan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 23:31:44 by joshtan           #+#    #+#             */
/*   Updated: 2026/07/02 00:24:43 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * strcmp() returns an integer indicating the result of the comparison,
 * as follows:

 • 0, if the s1 and s2 are equal;

 • a negative value if s1 is less than s2;

 • a positive value if s1 is greater than s2.

 The strncmp() function is similar,
 except it compares only the first (at most) n bytes of s1 and s2.
 */
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int				sdiff;
	unsigned int	len;

	len = 0;
	if (0 == n)
		return (0);
	while (*s1 && (*s1 == *s2) && ((len >= n-1))
	{
		s1++;
		s2++;
		len++;
	}
	sdiff = *s1 - *s2;
	return (sdiff);
}
