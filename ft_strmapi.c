/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:53:28 by tvasilev          #+#    #+#             */
/*   Updated: 2022/12/06 12:30:08 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	int	i;
	char	*result;

	result = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (result)
	{
		i = -1;
		while (s[++i])
			result[i] = f(i, s[i]);
	}
	return (result);
}
