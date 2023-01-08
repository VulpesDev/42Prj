/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:31:48 by tvasilev          #+#    #+#             */
/*   Updated: 2022/12/14 18:33:05 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stdlib.h>

static unsigned int	occ_c(const char *s, char c)
{
	int	i;
	int	result;
	int	in_c;

	i = -1;
	result = 0;
	in_c = 1;
	if (s == NULL)
		return (0);
	while (s[++i])
	{
		if (s[i] == c)
			in_c = 1;
		if (in_c && s[i] != c)
		{
			result++;
			in_c = 0;
		}
	}
	return (result);
}

static void	helper(const char *s, char c, char **result)
{
	int	length;
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			length = 0;
			while (s[i] != c && s[i] && ++length)
				i++;
			result[count++] = ft_substr(s, i - length, length);
		}
		else
			i++;
	}
	result[count] = 0;
}

char	**ft_split(const char *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = malloc((occ_c(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	helper(s, c, result);
	return (result);
}
