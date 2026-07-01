/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 13:35:50 by joshtan           #+#    #+#             */
/*   Updated: 2026/07/01 13:56:52 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2);

int	main(void)
{
	printf("Test 1 (same): %d\n", ft_strcmp("hello", "hello"));
	printf("Test 2 (diff): %d\n", ft_strcmp("hell", "hello"));
	printf("Test 3 (diff): %d\n", ft_strcmp("hello", "hell"));
	// Note: Standard strcmp does not mandate NULL checks, 
	// but for robustness in your own code, consider how you handle it.
	return (0);
}
