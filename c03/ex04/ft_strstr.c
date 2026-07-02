/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 09:42:23 by joshtan           #+#    #+#             */
/*   Updated: 2026/07/02 13:18:30 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int				sdiff;
	unsigned int	len;

	len = 0;
	if (0 == n)
		return (0);
	while (*s1 && (*s1 == *s2) && (len < n - 1))
	{
		s1++;
		s2++;
		len++;
	}
	sdiff = *s1 - *s2;
	return (sdiff);
}

unsigned int	ft_strlen(char *str)
{
	unsigned int	len;

	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int tflen;
	unsigned int slen;
	int st_i;

	if (!str || !to_find)
		return (0);
	tflen = ft_strlen(to_find) - 1;
	st_i = 0;
	if (*to_find == '\0')
		return (str);
	while (str[st_i] != '\0')
	{
		if (str[st_i] == to_find[0])
		{
			if(ft_strncmp(to_find, &str[st_i], tflen) == 0)
			{
				return (&str[st_i]);
			}
		}
		st_i++;
	}
	return (0);
}



