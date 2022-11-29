/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:42:20 by tvasilev          #+#    #+#             */
/*   Updated: 2022/11/29 19:38:12 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*csrc = (char *)src;
	char	*cdest = (char *)dest;
	char	*temp = csrc;
	size_t	i;

	i = 0;
	while (csrc[i] && i < n)
	{
		temp[i] = csrc[i];
		i++;
	}
	i = 0;
	while (cdest[i] && i < n)
	{
		cdest[i] = temp[i];
		i++;
	}
	return (dest);
}
