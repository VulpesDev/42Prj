/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:17:09 by tvasilev          #+#    #+#             */
/*   Updated: 2022/12/03 11:05:12 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cs;
	unsigned char	cc;
	size_t			i;

	i = 0;
	cs = (unsigned char *)s;
	cc = (unsigned char)c;
	while (i < n)
	{
		if (cs[i] == cc)
			return (cs + i);
		i++;
	}
	return ((void *)0);
}
