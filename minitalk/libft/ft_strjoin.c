/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:36:14 by tvasilev          #+#    #+#             */
/*   Updated: 2022/12/14 16:19:46 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stdlib.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*result;

	result = malloc((ft_strlen(s1) + ft_strlen(s2))
			* sizeof(char) + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, ft_strlen(s1) + 1);
	ft_strlcpy(result + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (result);
}
