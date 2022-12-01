/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_memcpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:23:09 by tvasilev          #+#    #+#             */
/*   Updated: 2022/11/30 12:40:43 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_rev_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*csrc;
	unsigned char	*cdest;
	int				i;

	i = (int)n;
	csrc = (unsigned char *)src;
	cdest = (unsigned char *)dest;
	while (i >= 0)
	{
		cdest[i] = csrc[i];
		i--;
	}
	return (cdest);
}
