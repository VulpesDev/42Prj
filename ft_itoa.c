/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvasilev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:54:08 by tvasilev          #+#    #+#             */
/*   Updated: 2022/12/06 11:42:19 by tvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include"libft.h"

static int	calc_zeros(int i)
{
	int	zeros;

	zeros = 0;
	while (i / 10)
	{
		zeros++;
		i /= 10;
	}
	return (zeros);
}

static int	check_neg(int i, int zeros)
{
	if (i < 0)
		return (zeros + 1);
	else
		return (zeros);
}

char	*ft_itoa(int n)
{
	long	num;
	int		zeros;
	int		neg;
	int		i;
	char	*result;

	zeros = calc_zeros(n);
	result = malloc((zeros + 3) * sizeof(char));
	if (n == 0)
		result[0] = 48;
	neg = n < 0;
	num = (long)n;
	if (num < 0)
		num *= -1;
	i = check_neg(n, zeros);
	result[i + 1] = 0;
	while (num)
	{
		result[i--] = (num % 10) + 48;
		num /= 10;
	}
	if (neg)
		result[i] = '-';
	return (result);
}
