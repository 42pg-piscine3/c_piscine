/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <joshtan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 11:15:38 by joshtan           #+#    #+#             */
/*   Updated: 2026/06/29 12:11:58 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_ft(int *********nbr)
{
	*********nbr = 42;
}

/* Uncomment to test
 *
#include <stdio.h>

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
	int cnt = 0;

	ptest_nbr = &test_nbr;
	p2test_nbr = &ptest_nbr;
	p3test_nbr = &p2test_nbr;
	p4test_nbr = &p3test_nbr;
	p5test_nbr = &p4test_nbr;
	p6test_nbr = &p5test_nbr;
	p7test_nbr = &p6test_nbr;
	p8test_nbr = &p7test_nbr;
	test_nbr = 0;
	if (argc < 2 )
		ft_ultimate_ft(&p8test_nbr);
	else
	{
		printf("Taking 1st input param only: = %s\n", argv[1]);
		if(argv[1][cnt] == '-')
		{
			printf("-ve input not supported\n");
			return  (-1);
		}
		while (argv[1][cnt] != '\0')
		{
			test_nbr = (test_nbr * 10) + (*argv[1] - '0');
			//argv[1]++;
			cnt++;
		}
		ft_ultimate_ft(&p8test_nbr);
	}
	printf("test_nbr = %d\n", test_nbr);
	return (0);
}
*/
