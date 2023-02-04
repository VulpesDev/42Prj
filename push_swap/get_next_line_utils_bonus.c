/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:13:19 by tvasilev          #+#    #+#             */
/*   Updated: 2023/02/04 14:03:47 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen1(const char *s)
{
	size_t	result;

	result = 0;
	if (s == NULL)
		return (0);
	while (s[result] != '\0')
		result++;
	return (result);
}

size_t	ft_strlcpy1(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen1(src));
	i = 0;
	while (i < (size - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen1(src));
}

char	*ft_strchr1(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (i <= ft_strlen1(s))
		if (s[i++] == (unsigned char)c)
			return ((char *)(s + (i - 1)));
	return ((void *)0);
}

char	*ft_strjoin1(char *s1, const char *s2, size_t size)
{
	char	*result;

	result = malloc((ft_strlen1(s1) + ft_strlen1(s2))
			* sizeof(char) + 1);
	if (!result)
		return (NULL);
	ft_strlcpy1(result, s1, ft_strlen1(s1) + 1);
	ft_strlcpy1(result + ft_strlen1(s1), s2, size);
	free(s1);
	return (result);
}
