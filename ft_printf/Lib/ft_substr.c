/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:03:10 by tvasilev          #+#    #+#             */
/*   Updated: 2022/12/14 19:04:01 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	size;

	size = 0;
	if ((ft_strlen(s) - (size_t)start) > len)
		size = len;
	else
		size = (ft_strlen(s) - (size_t)start);
	if (start >= ft_strlen(s) || len <= 0)
	{
		result = ft_strdup("");
		return (result);
	}
	result = malloc ((size + 1) * sizeof(char));
	if (!*s || !result)
		return (NULL);
	ft_strlcpy(result, s + start, size + 1);
	return (result);
}
