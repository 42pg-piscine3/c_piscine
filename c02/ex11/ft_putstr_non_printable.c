/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 11:04:47 by joshtan           #+#    #+#             */
/*   Updated: 2026/07/01 12:24:52 by joshtan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/*
 * Only call this if val is 0 to 16
 * for 0 to 9, we print values corresponding to '0' to '9'
 * For 10 to 16, we print 'a' to 'f'
 *  which is 1 to 6
 *  therefore, hex - 10 to get a to f
 * 
 **/
char	ft_hexes(int val)
{
	char	hex;

	if (val < 10)
	{
		hex = val + '0';
	}
	else
	{
		hex = val - 10 + 'a';
	}
	return (hex);
}

/*
 *	
 */
void	ft_puthex(char c)
{
	unsigned int	hval;
	unsigned char	npc;

	hval = c / 16;
	npc = ft_hexes(hval);
	ft_putchar(npc);
	hval = c % 16;
	npc = ft_hexes(hval);
	ft_putchar(npc);
}

void	ft_putstr_non_printable(char *str)
{
	while (str && *str)
	{
		if (' ' <= *str && *str <= '~')
		{
			ft_putchar(*str);
		}
		else
		{
			ft_putchar('\\');
			ft_puthex(*str);
		}
		str++;
	}
}

/*
 *
 **
#include <stdio.h>

int	main(void)
{
	// Test Case 1: NULL pointer handling
	printf("Test 1: NULL pointer (should handle gracefully or do nothing):\n");
	ft_putstr_non_printable(NULL);
	printf("\n\n");

	// Test Case 2: Empty string
	printf("Test 2: Empty string (should produce no output):\n");
	ft_putstr_non_printable("");
	printf("\n\n");

	// Test Case 3: Standard printable string
	printf("Test 3: Standard printable characters (\"Hello World\"):\n");
	ft_putstr_non_printable("Hello World");
	printf("\n\n");
 
	// Test Case 4: String containing non-printable characters
	// \n (0x0a), \t (0x09), \a (0x07)
	printf("Test 4: Non-printable characters ("
		"\"Hello\\nHow\\tare you?\\a\\b\\r\"):\n");
	ft_putstr_non_printable("Hello\nHow\tare you?\a\b\r");
	printf("\n\n");

	// Test Case 5: Boundary conditions (Control characters)
	// 0x00 (if handled), 0x1f (last control char), 0x7f (DEL)
	printf("Test 5: Boundary control characters (0x1f and 0x7f):\n");
	char boundary[] = {0x1f, 0x7f, 0};
	ft_putstr_non_printable(boundary);
	printf("\n");

	return (0);
}
***/
