/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <joshtan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 21:14:10 by joshtan           #+#    #+#             */
/*   Updated: 2026/06/30 02:13:50 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Implement char *ft_strcpy(char *dest, char *src);
 * Returns pointer to dest string.
 * Copying includes '\0'
 * Function stop copying after null from src is written.
 */
/*
 * Tricky bit:
 * idiomatic way is while(*dest=*src)
 * However Norminette flags assignment inside loop control.
 * We cannot use while(*dest) because it could contain '\0' randomly, it may
 * terminate prematurely.
 *
 * So while(*src) at least guarantees a null terminated string is detect right.
 * However, when *src == '\0', the while loop ends and skips copying the null
 * to *dest. *dest becomes non-null terminated. We have to assign null after
 * loop exits.
 *
 * "safer" way is directly memcpy, but the exercise disallows other functions.
 */
char	*ft_strcpy(char *dest, char *src)
{
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (dest);
}

/*
 * Uncomment to Test.
 **
#include <stdio.h>
#include <string.h>

int	main(int argc, char *argv[])
{
	char	*orig;
	char	*copy;
	char	s[12];
	int		idx;

	idx = 0;
	if (argc != 3)
	{
		ft_strcpy(s, "abracadabra");
		printf("%s\n", s);
		while (idx < strlen(s))
		{
			if (s[idx] == 'a')
				ft_strcpy(s + idx, s + idx + 1);
			else
				idx++;
		}
		printf("%s\n", s);
	}
}
**/
