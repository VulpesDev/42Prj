/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:48:32 by tvasilev          #+#    #+#             */
/*   Updated: 2022/11/29 17:33:04 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strrchr(char c, const char	*s)
{
	char	*result;
	char	r;
	int		i;

	i = 0;
	r = '\0';
	result = &r;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			*result = s[i];
		}
		i++;
	}
	return (result);
}
