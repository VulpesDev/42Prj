/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:28:05 by tvasilev          #+#    #+#             */
/*   Updated: 2022/12/07 16:15:23 by tvasilev         ###   ########.fr       */
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

char	**ft_split(const char *s, char c)
{
	char	**result;
	char	*s1;
	char	*p;
	int		count;

	s1 = ft_strdup(s);
	result = malloc((occ_c(s1, c) + 1) * sizeof(char *));
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
