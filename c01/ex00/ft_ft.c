/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <joshtan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 10:18:25 by joshtan           #+#    #+#             */
/*   Updated: 2026/06/18 11:11:41 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#define TEST 0//Define 1 to test with main()

#if TEST == 1

# include <stdio.h>

#endif

void	ft_ft(int *nbr)
{
	*nbr = 42;
}

#if TEST == 1

/*
 * Simple char to int conversion. Does not handle negative well.
 */
int	main(int argc, char *argv[])
{
	int	test_nbr;

	test_nbr = 0;
	if (argc < 2)
		ft_ft(&test_nbr);
	else
	{
		while (*argv[1] != '\0')
		{
			test_nbr *= 10;
			test_nbr = test_nbr + (*argv[1] - '0');
			argv[1]++;
		}
		printf("Received: %d\n", test_nbr);
		ft_ft(&test_nbr);
	}
	printf("post ft_ft(): %d\n", test_nbr);
	return (0);
}

#endif
