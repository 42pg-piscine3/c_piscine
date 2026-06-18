/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <joshtan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 11:15:38 by joshtan           #+#    #+#             */
/*   Updated: 2026/06/18 13:06:35 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TEST 0//Define 1 to test with main()

#if TEST == 1

# include <stdio.h>

#endif

void	ft_ultimate_ft(int *********nbr)
{
	*********nbr = 42;
}

#if TEST == 1

/*
 * Simple char to int conversion. Does not handle negative well.
 */

/* Uncomment to test
int	main(int argc, char *argv[])
{
	int	test_nbr;
	int	*ptest_nbr;
	int	**p2test_nbr;
	int	***p3test_nbr;
	int	****p4test_nbr;
	int	*****p5test_nbr;
	int	******p6test_nbr;
	int	*******p7test_nbr;
	int	********p8test_nbr;

	ptest_nbr = &test_nbr;
	p2test_nbr = &ptest_nbr;
	p3test_nbr = &p2test_nbr;
	p4test_nbr = &p3test_nbr;
	p5test_nbr = &p4test_nbr;
	p6test_nbr = &p5test_nbr;
	p7test_nbr = &p6test_nbr;
	p8test_nbr = &p7test_nbr;
	test_nbr = 0;
	if (argc < 2)
		ft_ultimate_ft(&p8test_nbr);
	else
	{
		while (*argv[1] != '\0')
		{
			test_nbr *= 10;
			test_nbr = test_nbr + (*argv[1] - '0');
			argv[1]++;
		}
		printf("Received: %d\n", test_nbr);
		ft_ultimate_ft(&p8test_nbr);
	}
	printf("post ft_ultimate_ft(): %d\n", test_nbr);
	return (0);
}
*/
#endif
