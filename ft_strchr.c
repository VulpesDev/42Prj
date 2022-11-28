/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:09:38 by tvasilev          #+#    #+#             */
/*   Updated: 2022/11/28 15:40:00 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "libft.h"

char*	ft_strchr(char c, char* s)
{
	int	i;
	char*	result;
	char	k;

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
