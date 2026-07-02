int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	// while the two strings are equal and S1 does not reach the end
	while (s1[i] == s2[i] && s1[i])
	{
		// While they are the same, the counter is added
		i++;
	}
	// In the end, if they are equal or different, the value will be returned
	return (s1[i] - s2[i]);
}
