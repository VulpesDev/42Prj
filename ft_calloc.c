/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:24:00 by tvasilev          #+#    #+#             */
/*   Updated: 2022/12/02 13:59:52 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;

	if (!nmemb || !size || (nmemb * size) > 2147483647)
		return ((void *)0);
	result = malloc(nmemb * size);
	ft_memset(result, 0, nmemb * size);
	return (result);
}
