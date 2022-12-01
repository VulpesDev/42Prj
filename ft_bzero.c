/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:06:57 by tvasilev          #+#    #+#             */
/*   Updated: 2022/11/29 18:24:37 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*c;

	c = s;
	i = 0;
	while (*c && i < n)
	{
		*c = '\0';
		i++;
	}
}
