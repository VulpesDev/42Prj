/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:31:48 by tvasilev          #+#    #+#             */
/*   Updated: 2022/12/08 14:42:09 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stdlib.h>

static unsigned int	occ_c(const char *s, char c)
{
	int	i;
	int	result;

	result = 1;
	i = -1;
	while (s[++i])
		if (s[i] == c)
			result++;
	return ((unsigned int)result);
}

char	**helper(char **result, char *s1, char *p, char c)
{
	int	count;

	count = 0;
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
	result[count++] = ft_strdup(p);
	result[count] = NULL;
	return (result);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	char	*s1;
	char	*p;
	int		count;

	if (s[0] == '\0')
	{
		result = malloc(1 * sizeof(char *));
		result[0] = NULL;
		return (result);
	}
	s1 = ft_strtrim(s, &c);
	result = malloc((occ_c(s1, c) + 1) * sizeof(char *));
	count = 0;
	p = s1;
	return (helper(result, s1, p, c));
}
