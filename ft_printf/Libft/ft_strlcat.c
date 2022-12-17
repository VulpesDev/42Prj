/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:32:47 by tvasilev          #+#    #+#             */
/*   Updated: 2022/12/05 16:38:20 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;

	i = 0;
	dest_len = ft_strlen(dst);
	if (dest_len > size)
		return (size + ft_strlen(src));
	if (size > dest_len)
	{
		while (i < (size - dest_len - 1) && src[i])
		{
			dst[dest_len + i] = src[i];
			i++;
		}
	}
	dst[dest_len + i] = '\0';
	return (dest_len + ft_strlen(src));
}
