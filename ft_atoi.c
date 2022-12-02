/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:41:26 by tvasilev          #+#    #+#             */
/*   Updated: 2022/12/02 13:20:56 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stdio.h>

int	ft_pow(int num, int pow)
{
	if (pow != 0)
		return (num * ft_pow(num, pow - 1));
	return (1);
}

int	calc_zeros(const char *nptr, int i)
{
	int	zeros;

	zeros = -1;
	while (nptr[i] >= '0' && nptr[i++] <= '9')
		zeros++;
	return (zeros);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	zeros;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ')
		i++;
	while (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i++] == '-')
			sign *= -1;
	}
	zeros = calc_zeros(nptr, i);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result += (nptr[i] - 48) * ft_pow(10, zeros);
		zeros--;
		i++;
	}
	return (result * sign);
}
