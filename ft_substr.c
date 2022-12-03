#include <stdlib.h>
#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*result;

	result = malloc(len * sizeof(char) + 1);
	if (result == NULL)
		return ((void *)0);
	ft_strlcpy(result, s + start, len+1);
	return (result);
}
