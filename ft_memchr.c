/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:17:09 by tvasilev          #+#    #+#             */
/*   Updated: 2022/11/30 13:31:31 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cs = (unsigned char*)s;
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (cs[i] == c)
			return (cs + i);
		i++;
	}
	return (void*)0;
}
