/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:36:36 by tvasilev          #+#    #+#             */
/*   Updated: 2023/01/08 09:58:05 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

int	ft_convertion(const char *c, va_list valist)
{
	int	result;

	result = 0;
	if (*c == 'c')
		result += ft_putchari_fd(va_arg(valist, int), 1);
	else if (*c == 's')
		result += ft_putstri_fd(va_arg(valist, char *), 1);
	else if (*c == 'i' || *c == 'd')
		result += ft_putnbri_fd(va_arg(valist, int), 1);
	else if (*c == 'u')
		result += ft_putusnbr_fd(va_arg(valist, unsigned int), 1);
	else if (*c == 'X')
		result += ft_puthexu_fd(va_arg(valist, int), 1);
	else if (*c == 'x')
		result += ft_puthexl_fd(va_arg(valist, int), 1);
	else if (*c == 'p')
		result += ft_putp_fd((uintptr_t)va_arg(valist, void *), 1);
	else if (*c == '%' && ++result)
		ft_putchari_fd('%', 1);
	return (result);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		len;
	va_list	valist;

	va_start(valist, s);
	i = -1;
	len = 0;
	while (s[++i])
	{
		if (s[i] == '%')
			len += ft_convertion(s + (++i), valist);
		else
		{
			ft_putchari_fd(s[i], 1);
			len++;
		}
	}
	return (len);
}
