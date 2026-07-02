/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 15:08:05 by joshtan           #+#    #+#             */
/*   Updated: 2026/07/02 15:40:54 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int    ft_strlen(char *str)
{
    unsigned int    len;
    len = 0;
    while (*str)
    {
        str++;
        len++;
    }
    return (len);
}

unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
    unsigned int    dlen;
    unsigned int    slen;
    unsigned int    i;

    dlen = ft_strlen(dest);
    i = 0;
    while (*src && i < size -1)
    {
        *(dest + dlen + i) = *src;
        src++;
        i++;
    }
    *(dest + dlen + i) = '\0';

    return (dlen + i);
}

