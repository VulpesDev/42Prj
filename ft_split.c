#include "libft.h"
#include<stdlib.h>
#include<stdio.h>

static unsigned int	occ_c(const char *s, char c)
{
	unsigned int	result;
	int	i;

	result = 1;
	i = -1;
	while (s[++i])
		if (s[i] == c)
			result++;
	return (result);
}
char	**ft_split(const char *s, char c)
{
	char	**result;
	char	*s1;
	char	*p;
	int	count;

	s1 = ft_strdup(s);
	result = malloc((occ_c(s1,c) + 1) * sizeof(char *));
	printf("%d\n", occ_c(s1,c));
	count = 0;
	p = s1;
	while (*s1)
	{
		while (*p == c && *s1)
			p = s1++;
		if (*s1 == c && *s1 && *(s1 + 1))
		{
			*s1 = '\0';
			result[count++] = ft_strdup(p);
			p = s1 + 1;
		}
		s1++;
	}
	if (*(s1 - 1) != '\0')
		result[count++] = ft_strdup(p);
	result[count] = (void *)0;
	return (result);
}
