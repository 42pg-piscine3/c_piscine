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

int	main(int argc, char *argv[])
{
	int isrc;
	int icmp;
	int lensrc;

	lensrc = ft_strlen(argv[1]);

	if  (argc < 3 || argc >3)
	{
		write (1, "\n", 1);
		return (0);
	}

	while (argv[2][icmp])
	{
		if (argv[1][isrc] == argv[2][icmp])
		{
			isrc++;
		}
		icmp++;
	}

	if (isrc == lensrc)
		ft_putchar(argv[1]);

	write (1, "\n", 1);

}

