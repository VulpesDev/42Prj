/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:37:59 by tvasilev          #+#    #+#             */
/*   Updated: 2022/12/05 14:38:01 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stdlib.h>

static int	check_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
		if (c == set[i++])
			return (1);
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*result;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	result = malloc(len * sizeof(char) + 1);
	while (s1[i])
	{
		if (!check_set(s1[i], set))
		{
			result = ft_strdup(s1 + i);
			break ;
		}
		i++;
	}
	len = ft_strlen(result);
	while (result[--len])
	{
		if (!check_set(result[len], set))
		{
			result[len + 1] = '\0';
			break ;
		}
	}
	return (result);
}
