/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshtan <joshtan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 21:14:10 by joshtan           #+#    #+#             */
/*   Updated: 2026/06/30 04:39:19 by joshtan          ###   ########.fr       */
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
	char	*predest;

	predest = dest;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (predest);
}

/*
 * Uncomment to Test.
 **
#include <stdio.h>
#include <string.h>

int tester (void);

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

	tester();
}

// Helper function to print exact buffer contents up to a specified size
void print_buffer(char *label, char *buf, int total_size)
{
    printf("%s: [", label);
    for (int i = 0; i < total_size; i++)
    {
        if (buf[i] == '\0')
            printf("\\0");
        else
            printf("%c", buf[i]);
        
        if (i < total_size - 1)
            printf(", ");
    }
    printf("]\n");
}
int	tester(void)
{
	printf("=== RUNNING STRCPY TESTS ===\n\n");

    // -----------------------------------------------------------------
    // TEST 1: Standard String Copy
    // -----------------------------------------------------------------
    {
        char dest_ft[15] = "XXXXXXXXXXXXXX";
        char dest_std[15] = "XXXXXXXXXXXXXX";
        char *src = "Hello 42";

        char *ret_ft = ft_strcpy(dest_ft, src);
        char *ret_std = strcpy(dest_std, src);

        printf("[Test 1: Standard Case]\n");
        print_buffer("  ft_strcpy ", dest_ft, 14);
        print_buffer("  std_strcpy", dest_std, 14);
        printf("  Return Ptr Match: %s\n\n",
	   	(ret_ft == dest_ft) ? "✅ PASS" : "❌ FAIL");
    }

    // -----------------------------------------------------------------
    // TEST 2: Empty String Copy (The edge case)
    // -----------------------------------------------------------------
    {
        char dest_ft[10] = "XXXXXXXXX";
        char dest_std[10] = "XXXXXXXXX";
        char *src = "";

        char *ret_ft = ft_strcpy(dest_ft, src);
        char *ret_std = strcpy(dest_std, src);

        printf("[Test 2: Empty String Case (\"\")]\n");
        print_buffer("  ft_strcpy ", dest_ft, 9);
        print_buffer("  std_strcpy", dest_std, 9);
        printf("  Return Ptr Match: %s\n\n",
				(ret_ft == dest_ft) ? "✅ PASS" : "❌ FAIL");
    }

    // -----------------------------------------------------------------
    // TEST 3: Overwriting a Longer Existing String
    // -----------------------------------------------------------------
    {
        char dest_ft[15] = "LongOldString";
        char dest_std[15] = "LongOldString";
        char *src = "Short";

        ft_strcpy(dest_ft, src);
        strcpy(dest_std, src);

        printf("[Test 3: Overwriting Longer String]\n");
        // We look at the full buffer size to ensure the new null terminator
        // stops further reading, but old data after it remains untouched.
        print_buffer("  ft_strcpy ", dest_ft, 14);
        print_buffer("  std_strcpy", dest_std, 14);
        printf("\n");
    }

    // -----------------------------------------------------------------
    // TEST 4: Compound Literal Source Input
    // -----------------------------------------------------------------
    {
        char dest_ft[10] = "XXXXXXXXX";

        ft_strcpy(dest_ft, (char[]){"Piscine"});

        printf("[Test 4: Compound Literal Source]\n");
        print_buffer("  ft_strcpy ", dest_ft, 9);
        printf("\n");
    }

    printf("=== TESTING COMPLETE ===\n");
    return (0);
}
**/
