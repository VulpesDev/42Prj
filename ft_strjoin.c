#include "libft.h"
#include<stdlib.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*result;

	result = malloc((ft_strlen(s1) + ft_strlen(s2)) 
			* sizeof(char) + 2);
	ft_strlcpy(result, s1, ft_strlen(s1) + 1);
	ft_strlcpy(result + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (result);
}
