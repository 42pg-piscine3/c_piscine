#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	main(void)
{
	printf("Test 1 (n=3): %d\n", ft_strncmp("hello", "hell", 3));
	printf("Test 2 (n=5): %d\n", ft_strncmp("hello", "hell", 5));

    int res;

    // n = 0 → always 0, regardless of content
    res = ft_strncmp("abc", "xyz", 0);
    printf("[%s] n=0 always returns 0\n", res == 0 ? "PASS" : "FAIL");

    // identical strings, n = length
    res = ft_strncmp("abc", "abc", 3);
    printf("[%s] equal strings\n", res == 0 ? "PASS" : "FAIL");

    // s1 < s2
    res = ft_strncmp("abc", "abd", 3);
    printf("[%s] s1 < s2 returns negative\n", res < 0 ? "PASS" : "FAIL");

    // s1 > s2
    res = ft_strncmp("abd", "abc", 3);
    printf("[%s] s1 > s2 returns positive\n", res > 0 ? "PASS" : "FAIL");

    // difference exists but beyond n → 0
    res = ft_strncmp("abcX", "abcY", 3);
    printf("[%s] difference beyond n returns 0\n", res == 0 ? "PASS" : "FAIL");

    // s1 ends before s2 within n
    res = ft_strncmp("ab", "abc", 3);
    printf("[%s] s1 shorter than s2 returns negative\n", res < 0 ? "PASS" : "FAIL");

    // s2 ends before s1 within n
    res = ft_strncmp("abc", "ab", 3);
    printf("[%s] s2 shorter than s1 returns positive\n", res > 0 ? "PASS" : "FAIL");

    // n larger than both strings, equal content
    res = ft_strncmp("abc", "abc", 10);
    printf("[%s] n > strlen, equal strings\n", res == 0 ? "PASS" : "FAIL");

    // both empty
    res = ft_strncmp("", "", 1);
    printf("[%s] both empty\n", res == 0 ? "PASS" : "FAIL");

    // s1 empty, s2 not
    res = ft_strncmp("", "a", 1);
    printf("[%s] s1 empty, s2 not → negative\n", res < 0 ? "PASS" : "FAIL");

	return (0);
}
