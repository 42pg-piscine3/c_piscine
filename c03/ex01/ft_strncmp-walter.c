int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	// while the counter is less than the passed number
	while (i < n)
	{
		// If s1 is different from S2 or S1 reaches the end
		// The difference between the two is returned
		if (s1[i] != s2[i] || s1[i] == '\0')
			return (s1[i] - s2[i]);
		i++;
	}
	// If the two are equal the return is zero
	return (0);
}
