/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:09:38 by tvasilev          #+#    #+#             */
/*   Updated: 2022/12/02 16:26:22 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*result;
	char	k;
	int		i;

	k = '\0';
	result = &k;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			*result = s[i];
		i++;
	}
	return (result);
}
