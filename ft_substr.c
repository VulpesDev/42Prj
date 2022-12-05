/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:03:10 by tvasilev          #+#    #+#             */
/*   Updated: 2022/12/05 14:35:55 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*result;

	result = malloc(len * sizeof(char) + 1);
	if (result == NULL)
		return ((void *)0);
	ft_strlcpy(result, s + start, len + 1);
	return (result);
}
