/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:02:30 by tvasilev          #+#    #+#             */
/*   Updated: 2022/12/02 15:25:52 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*result;

	result = malloc(ft_strlen(s) * sizeof(char));
	ft_strlcpy(result, s, ft_strlen(s));
	return (result);	
}
