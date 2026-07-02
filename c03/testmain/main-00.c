#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2);

int	main(void)
{
	printf("Test 1 (same): %d\n", ft_strcmp("hello", "hello"));
	printf("Test 2 (diff): %d\n", ft_strcmp("hell", "hello"));
	printf("Test 3 (diff): %d\n", ft_strcmp("hello", "hell"));
	// Note: Standard strcmp does not mandate NULL checks, 
	// but for robustness in your own code, consider how you handle it.
	int res;

    // identical strings
    res = ft_strcmp("abc", "abc");
    printf("[%s] equal strings\n", res == 0 ? "PASS" : "FAIL");

    // s1 < s2
    res = ft_strcmp("abc", "abd");
    printf("[%s] s1 < s2 returns negative\n", res < 0 ? "PASS" : "FAIL");

    // s1 > s2
    res = ft_strcmp("abd", "abc");
    printf("[%s] s1 > s2 returns positive\n", res > 0 ? "PASS" : "FAIL");

    // s1 shorter than s2
    res = ft_strcmp("ab", "abc");
    printf("[%s] s1 shorter returns negative\n", res < 0 ? "PASS" : "FAIL");

    // s1 longer than s2
    res = ft_strcmp("abc", "ab");
    printf("[%s] s1 longer returns positive\n", res > 0 ? "PASS" : "FAIL");

    // both empty
    res = ft_strcmp("", "");
    printf("[%s] both empty\n", res == 0 ? "PASS" : "FAIL");

    // s1 empty, s2 not
    res = ft_strcmp("", "a");
    printf("[%s] s1 empty, s2 not → negative\n", res < 0 ? "PASS" : "FAIL");

    // s2 empty, s1 not
    res = ft_strcmp("a", "");
    printf("[%s] s2 empty, s1 not → positive\n", res > 0 ? "PASS" : "FAIL");

    // same prefix, differ on case
    res = ft_strcmp("abc", "ABC");
    printf("[%s] lowercase > uppercase (ASCII order)\n", res > 0 ? "PASS" : "FAIL");

	return (0);
}
