/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <joshtan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 01:04:43 by joshtan           #+#    #+#             */
/*   Updated: 2026/07/02 01:29:13 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int len;

	if (!str)
		return (0);
	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

/*
 * appends the src string to the dest string,
 * overwriting the terminating null byte ('\0') at the end of dest,
 * and then adds a terminating null byte.
 * The strings may not overlap, and the dest string must have enough space for
 * the result.
 * *  it will use at most n bytes from src; and
 * *  src does not need to be null-terminated if it contains n or more bytes.
 * As with strcat(), the resulting string in dest is always null-terminated.
 * If src contains n or more bytes, strncat() writes n+1 bytes to dest
 * (n from src plus the terminating null byte).
 * Therefore, the size of dest must be at least strlen(dest)+n+1.
 */
char *ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	len;
	unsigned int	cnt;

	len = ft_strlen(dest);
	cnt = 0;
	while ((cnt < nb) && (src[cnt] != '\0'))
	{
		dest[len + cnt] = src[cnt];
		cnt++;
	}
	dest[len + cnt] = '\0';

	return (dest);
}
