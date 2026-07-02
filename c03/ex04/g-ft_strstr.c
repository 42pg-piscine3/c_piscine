int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	len;

	len = 0;
	if (n == 0)
		return (0);
	// Loop until s1 ends, characters mismatch, or we have matched n characters
	while (*s1 && (*s1 == *s2) && (len < n - 1))
	{
		s1++;
		s2++;
		len++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

unsigned int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0; //  Initialization added to prevent undefined behavior
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int tflen;
	int st_i;

	if (!str || !to_find)
		return (0);
	if (*to_find == '\0')
		return (str);

	tflen = ft_strlen(to_find); //  Fixed: Do not subtract 1
	st_i = 0;
	
	while (str[st_i] != '\0')
	{
		if (str[st_i] == to_find[0])
		{
			// Fixed: Now compares the accurate number of characters
			if (ft_strncmp(&str[st_i], to_find, tflen) == 0)
			{
				return (&str[st_i]);
			}
		}
		st_i++;
	}
	return (0);
}

