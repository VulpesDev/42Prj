/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:02:30 by tvasilev          #+#    #+#             */
/*   Updated: 2022/12/13 15:44:28 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*result;

	result = malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s, ft_strlen(s) + 1);
	return (result);
}
