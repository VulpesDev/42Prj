/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:53:28 by tvasilev          #+#    #+#             */
/*   Updated: 2022/12/06 16:45:02 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*result;

	if (s == NULL || f == NULL)
		return (NULL);
	i = -1;
	result = malloc((ft_strlen(s) + 1) * sizeof(char));
	ft_strlcpy(result, s, ft_strlen(s) + 1);
	while (result[++i])
		result[i] = f(i, s[i]);
	return (result);
}
