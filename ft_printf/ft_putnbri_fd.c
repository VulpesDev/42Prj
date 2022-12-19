/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbri_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:50:37 by tvasilev          #+#    #+#             */
/*   Updated: 2022/12/19 11:44:50 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nbrr(long num, int fd)
{
	int	result;

	result = 1;
	if (num > 9)
		result += nbrr(num / 10, fd);
	ft_putchar_fd((num % 10) + 48, fd);
	return (result);
}

int	ft_putnbri_fd(int n, int fd)
{
	long	num;
	int		len;

	num = (long)n;
	len = 0;
	if (num < 0)
	{
		num *= -1;
		ft_putchar_fd('-', fd);
		len++;
	}
	len += nbrr(num, fd);
	return (len);
}
