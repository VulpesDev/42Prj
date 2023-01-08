/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:13:25 by tvasilev          #+#    #+#             */
/*   Updated: 2023/01/08 09:57:09 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putp_fd(uintptr_t n, int fd)
{
	int	result;

	result = 0;
	if (n == 0)
	{
		result = ft_putstri_fd("(nil)", 1);
		return (result);
	}
	ft_putstri_fd("0x", 1);
	result += 2;
	result += ft_putp_tohex_fd(n, fd);
	return (result);
}
