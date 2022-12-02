/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:39:25 by tvasilev          #+#    #+#             */
/*   Updated: 2022/12/02 18:07:35 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*sc;

	c = s;
	if (s)
	{
		unsigned char	*p;

		while (n)
			sc[--n] = (unsigned char)c;
	}
	return (s);
}
