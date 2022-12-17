/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:42:20 by tvasilev          #+#    #+#             */
/*   Updated: 2022/12/14 18:31:19 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_str_memcpy(void *dest, const void *src, size_t n)
{
	int	i;

	i = -1;
	if (!dest && !src)
		return (0);
	while (++i < (int)n)
		((char *)dest)[i] = ((char *)src)[i];
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest > src)
		ft_memcpy(dest, src, n);
	else
		ft_str_memcpy(dest, src, n);
	return (dest);
}
