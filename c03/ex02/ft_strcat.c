/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <joshtan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 00:29:26 by joshtan           #+#    #+#             */
/*   Updated: 2026/07/02 01:13:11 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	if (!str)
		return (0);
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

/*
 * appends the src string to the dest string,
 * overwriting the terminating null byte ('\0') at the end of dest,
 * and then adds a terminating null byte.
 * The strings may not overlap, and the dest string must have enough space for
 * the result.
 */
char *ft_strcat(char *dest, char *src)
{
	unsigned int	len;
	unsigned int	cnt;

	len = ft_strlen(dest);
	cnt = 0;
	while (src[cnt] != '\0')
	{
		dest[len + cnt] = src[cnt];
		cnt++;
	}
	dest[len + cnt] = '\0';
	return (dest);
}
