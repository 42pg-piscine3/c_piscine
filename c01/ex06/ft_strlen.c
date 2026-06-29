/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <joshtan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 03:28:20 by joshtan           #+#    #+#             */
/*   Updated: 2026/06/29 15:26:48 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strlen(char *str)
{
	int	len;

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
 * Uncomment for test
 *
#include <stdio.h>

int main(void)
{
    int len;
    char    *word = "Hi World";

    len = ft_strlen(word);
    printf("len is %d\n", len);

    word = "Done";
    len = ft_strlen(word);
    printf("len is %d\n", len);

	word = "0";
	len = ft_strlen(word);
    printf("len is %d\n", len);

	word = 0;
	len = ft_strlen(word);
    printf("len is %d\n", len);
}
*/
