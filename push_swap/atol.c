/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <tvasilev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:14:57 by tvasilev          #+#    #+#             */
/*   Updated: 2023/01/22 14:58:05 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_pow(int num, int pow)
{
	if (pow != 0)
		return (num * ft_pow(num, pow - 1));
	return (1);
}

static int	calc_zeros(const char *nptr, int i)
{
	int	zeros;

	zeros = -1;
	while (nptr[i] >= '0' && nptr[i++] <= '9')
		zeros++;
	return (zeros);
}

//checks for numbers that 
//have the same length as max and min (basically long atoi)
long	ft_atol(const char *nptr)
{
	int		i;
	int		zeros;
	int		sign;
	long	result;
	int		signs;

	i = 0;
	result = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 7 && nptr[i] <= 13))
		i++;
	signs = 0;
	while (nptr[i] == '-' || nptr[i] == '+')
	{
		signs++;
		if (sign == -1 || signs > 1)
			return (0);
		if (nptr[i++] == '-')
			sign = -1;
	}
	zeros = calc_zeros(nptr, i);
	while (nptr[i] >= '0' && nptr[i] <= '9')
		result += (nptr[i++] - 48) * ft_pow(10, zeros--);
	return (result * sign);
}
