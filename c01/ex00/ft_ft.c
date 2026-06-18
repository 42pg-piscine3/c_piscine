/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <joshtan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 10:18:25 by joshtan           #+#    #+#             */
/*   Updated: 2026/06/18 10:32:46 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#define TEST 1 

#if TEST == 1

#include <unistd.h>
#include <stdio.h>
#endif

void	ft_ft(int *nbr)
{
	*nbr = 42;
}

#if TEST == 1

int	main(int argc, char *argv[])
{
	int test_nbr;

	test_nbr = 0;
	if (argc < 2)
		ft_ft(&test_nbr);
	else
	{
		while (*argv[1] != '\0')
		{
			test_nbr = *argv[1] - '0';
			*argv++;
		}
			printf("passed :%d\n", test_nbr);
	}

	return (0);
}

#endif
