#include <unistd.h>

void	ft_putchar(char *str)
{
	while (*str)
	{
		write (1, str, 1);
		str++;
	}
}

int	ft_strlen(char *str)
{
	int len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return len;
}

char	*ft_revstring(char *str)
{
	int fwd;
	int rev;
	char ctmp;

	fwd =0;
	rev = ft_strlen(str);
	rev = rev -1;

	while (fwd<rev)
	{
		ctmp = str[fwd];
		str[fwd] = str[rev];
		str[rev] = ctmp;

		rev--;
		fwd++;
	}
	return str;
}

/*
 * Uncomment to test
 *
int	main(int argc, char *argv[])
{
	char *local;
	int cnt;

	local = (char[]){"hello"};

	if  (argc < 2 || argc > 4)
	{
		ft_revstring(local);
		ft_putchar(local);
		write (1, "\n", 1);
		return (0);
	}
	cnt = 1;
	while (cnt < argc)
	{
		ft_revstring(argv[cnt]);
		ft_putchar(argv[cnt]);
		cnt++;
	}
	write (1, "\n", 1);
}
**/
