#include "libft.h"
#include<stdlib.h>

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
	result = malloc(occ_c(s1,c) * sizeof(char *) + 1);
	count = 0;
	p = s1;
	while (*s1)
	{
		while (*p == c && *s1)
			p = s1++;
		if (*s1 == c)
		{
			if (*p != c)
				result[count++] = p;
			*s1 = '\0';
		}
		s1++;
	}
	if (*(s1 - 1) != '\0')
		result[count++] = p;
	result[count] = (void *)0;
	return (result);
}
