/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <joshtan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 03:35:54 by joshtan           #+#    #+#             */
/*   Updated: 2026/06/23 03:59:10 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str);

int main(void)
{
	int	len;
	char	*word = "Hi World";

	len = ft_strlen(word);
	printf("len is %d\n", len);

	word = "Done";
	len = ft_strlen(word);
	printf("len is %d\n", len);

}
