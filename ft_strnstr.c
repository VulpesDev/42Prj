/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:16:33 by tvasilev          #+#    #+#             */
/*   Updated: 2022/12/02 17:04:19 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	are_same(const char *big, const char *lit, size_t pos)
{
	size_t	i;

	i = 0;
	while (lit[i] != '\0')
	{
		if (lit[i] != big[pos])
			return (0);
		pos++;
		i++;
	}
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		if (big[i] == little[0])
		{
			if (are_same(big, little, i))
				return ((char *)&big[i]);
		}
		i++;
	}
	return ((void *)0);
}
