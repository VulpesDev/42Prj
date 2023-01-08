/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexu_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:40:14 by tvasilev          #+#    #+#             */
/*   Updated: 2023/01/08 09:57:10 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexu_fd(unsigned int n, int fd)
{
	char	to_put;
	int		result;

	result = 1;
	to_put = '0';
	if (n > 15)
		result += ft_puthexu_fd(n / 16, fd);
	if (n % 16 < 10)
		to_put = (n % 16) + 48;
	else if (n % 16 == 10)
		to_put = 'A';
	else if (n % 16 == 11)
		to_put = 'B';
	else if (n % 16 == 12)
		to_put = 'C';
	else if (n % 16 == 13)
		to_put = 'D';
	else if (n % 16 == 14)
		to_put = 'E';
	else if (n % 16 == 15)
		to_put = 'F';
	ft_putchari_fd(to_put, fd);
	return (result);
}
