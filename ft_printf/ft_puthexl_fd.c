/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:51:17 by tvasilev          #+#    #+#             */
/*   Updated: 2022/12/18 17:06:19 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lib/libft.h"

int	ft_puthexl_fd(int n, int fd)
{
	char	to_put;
	int		result;

	result = 1;
	to_put = '0';
	if (n > 15)
		result += ft_puthexL_fd(n / 16, fd);
	if (n % 16 < 10)
		to_put = (n % 16) + 48;
	else if (n % 16 == 10)
		to_put = 'a';
	else if (n % 16 == 11)
		to_put = 'b';
	else if (n % 16 == 12)
		to_put = 'c';
	else if (n % 16 == 13)
		to_put = 'd';
	else if (n % 16 == 14)
		to_put = 'e';
	else if (n % 16 == 15)
		to_put = 'f';
	ft_putchar_fd(to_put, fd);
	return (result);
}
