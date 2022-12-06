/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:05:19 by tvasilev          #+#    #+#             */
/*   Updated: 2022/12/06 16:05:39 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include<stdlib.h>
/*
void	ft_putnbr_fd(int n, int fd)
{
	char	*r;

	r = ft_itoa(n);
	ft_putstr_fd(r, fd);
	free(r);
}
*/

static void	nbrr(long num, int fd)
{
	if (num > 9)
		nbrr(num / 10, fd);
	ft_putchar_fd((num % 10) + 48, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = (long)n;
	if (num < 0)
	{
		num *= -1;
		ft_putchar_fd('-', fd);
	}
	nbrr(num, fd);
}
