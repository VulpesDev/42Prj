/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putusnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 12:11:39 by tvasilev          #+#    #+#             */
/*   Updated: 2022/12/19 11:44:48 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putusnbr_fd(unsigned int n, int fd)
{
	int	result;

	result = 1;
	if (n > 9)
		result += ft_putusnbr_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + 48, fd);
	return (result);
}
