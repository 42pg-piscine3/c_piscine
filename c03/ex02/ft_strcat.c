/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 09:05:48 by joshtan           #+#    #+#             */
/*   Updated: 2026/07/02 09:18:16 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	len;
	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

char *ft_strcat(char *dest, char *src)
{
	unsigned int	dlen;
	unsigned int	i;

	dlen = ft_strlen(dest);
	i = 0;
	while (*src)
	{
		*(dest + dlen + i) = *src;
		src++;
		i++;
	}
	*(dest + dlen + i) = '\0';

	return (dest);
}
