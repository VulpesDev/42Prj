/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:10:10 by tvasilev          #+#    #+#             */
/*   Updated: 2022/12/13 13:25:38 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	size_t	result;

	result = 0;
	if (s == NULL)
		return (0);
	while (s[result] != '\0')
		result++;
	return (result);
}
